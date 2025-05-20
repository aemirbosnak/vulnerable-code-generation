//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <errno.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*10

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char*)malloc(size * nmemb);
    if(buffer == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for response\n");
        exit(EXIT_FAILURE);
    }
    memcpy(buffer, contents, size * nmemb);
    *(char**)userp = buffer;
    return nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LEN];
    char response[MAX_RESPONSE_LEN];
    int response_code = 0;

    printf("Enter the URL to monitor: ");
    scanf("%s", url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        else
        {
            response_code = atoi(response);
            printf("Response code: %d\n", response_code);
        }

        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }

    return 0;
}