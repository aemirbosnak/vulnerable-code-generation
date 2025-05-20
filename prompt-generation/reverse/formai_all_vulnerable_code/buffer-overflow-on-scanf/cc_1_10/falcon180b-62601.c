//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 1024

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    char* buffer = (char*)malloc(realsize + 1);
    if (buffer == NULL) {
        return 0;
    }

    memcpy(buffer, contents, realsize);
    buffer[realsize] = '\0';

    *(char**)userp = buffer;

    return realsize;
}

int main()
{
    CURL* curl;
    CURLcode res;
    char url[MAX_URL_LENGTH];
    char* response = NULL;

    printf("Enter the URL to monitor: ");
    scanf("%s", url);

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res!= CURLE_OK) {
            printf("curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    if (response!= NULL) {
        printf("Response:\n%s\n", response);
        free(response);
    }

    curl_global_cleanup();

    return 0;
}