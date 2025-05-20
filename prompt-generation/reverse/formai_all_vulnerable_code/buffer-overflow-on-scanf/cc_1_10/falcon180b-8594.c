//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <errno.h>

#define MAX_URL_SIZE 1024
#define MAX_ERROR_SIZE 512

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[(size_t)((char*)userp) - 1] = '\0';
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    char error_buffer[MAX_ERROR_SIZE];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[MAX_URL_SIZE];
        char *error_msg = NULL;
        int response_code = 0;

        printf("Enter website URL: ");
        scanf("%s", url);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &error_buffer);
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error_buffer);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", error_buffer);
        } else {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

            if(response_code >= 200 && response_code < 300) {
                printf("Website is up and running.\n");
            } else {
                fprintf(stderr, "Website is down. Response code: %d\n", response_code);
            }
        }
    } else {
        fprintf(stderr, "curl_easy_init() failed.\n");
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}