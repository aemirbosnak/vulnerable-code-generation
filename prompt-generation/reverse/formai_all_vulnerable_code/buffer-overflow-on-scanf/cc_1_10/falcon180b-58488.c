//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
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

int main()
{
    CURL *curl;
    CURLcode res;
    FILE *fp;
    char url[1000];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        printf("Enter the URL: ");
        scanf("%s", url);

        fp = fopen("response.txt", "wb");
        if(!fp)
        {
            printf("Failed to open file\n");
            exit(1);
        }

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
        {
            printf("Failed to perform request\n");
            exit(1);
        }

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}