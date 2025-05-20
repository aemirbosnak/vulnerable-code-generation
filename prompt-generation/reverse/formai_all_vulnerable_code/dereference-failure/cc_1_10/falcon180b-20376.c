//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <curl/curl.h>

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    FILE* file = (FILE*)userp;
    return fwrite(contents, realsize, 1, file);
}

int main(int argc, char* argv[])
{
    if(argc!= 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    CURL* curl;
    FILE* file;
    CURLcode res;

    curl = curl_easy_init();
    if(curl)
    {
        file = fopen("output.html", "wb");
        if(!file)
        {
            printf("Failed to open file: %s\n", strerror(errno));
            return 1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
        {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("Downloaded %s successfully\n", argv[1]);
        }

        fclose(file);
        curl_easy_cleanup(curl);
    }

    return 0;
}