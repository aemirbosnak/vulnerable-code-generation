//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    char *buffer = malloc(realsize + 1);
    if(buffer == NULL)
    {
        return 0;
    }
    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';
    printf("%s", buffer);
    free(buffer);
    return realsize;
}

int main()
{
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl)
    {
        char url[100];
        printf("Enter URL: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
        {
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return 0;
}