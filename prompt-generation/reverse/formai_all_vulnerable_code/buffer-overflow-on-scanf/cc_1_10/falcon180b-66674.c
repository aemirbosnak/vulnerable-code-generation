//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LEN 1024
#define MAX_RESPONSE_LEN 1024

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)nmemb * size - 1] = '\0';
    return size * nmemb;
}

int main()
{
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if(curl) {
        char url[MAX_URL_LEN];
        char response[MAX_RESPONSE_LEN];

        printf("Enter website URL: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, response);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        } else {
            printf("Website status: %s\n", response);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}