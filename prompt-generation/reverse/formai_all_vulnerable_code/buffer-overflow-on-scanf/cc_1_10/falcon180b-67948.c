//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <ctype.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024*1024

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    char *buffer = (char*)malloc(size * nmemb);
    if(buffer == NULL)
    {
        return 0;
    }
    memcpy(buffer, contents, size * nmemb);
    printf("%s", buffer);
    free(buffer);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl)
    {
        char url[MAX_URL_LEN];
        printf("Enter the URL to monitor: ");
        scanf("%s", url);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
        {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("Website is up!\n");
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}