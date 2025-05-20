//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    FILE *file = (FILE *)userp;
    return fwrite(contents, realsize, 1, file);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: %s <username> <password> <server> <port>\n", argv[0]);
        exit(1);
    }

    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (curl)
    {
        char url[100];
        sprintf(url, "ftp://%s:%s@%s:%d", argv[1], argv[2], argv[3], atoi(argv[4]));

        fp = fopen("output.txt", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
        {
            printf("FTP upload failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("FTP upload succeeded!\n");
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}