//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <errno.h>

#define MAX_URL_LENGTH 512
#define TIMEOUT 10
#define RETRY_DELAY 5000

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *buffer = (char*)malloc(realsize + 1);
    if(buffer!= NULL) {
        memcpy(buffer, contents, realsize);
        buffer[realsize] = '\0';
        printf("%s", buffer);
        free(buffer);
    }
    return realsize;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char url[MAX_URL_LENGTH];
    int failures = 0;

    if(argc!= 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            printf("Error: %s\n", curl_easy_strerror(res));
            failures++;
        } else {
            printf("Website is up!\n");
        }

        curl_easy_cleanup(curl);
    } else {
        printf("Error: Failed to initialize curl\n");
        failures++;
    }

    curl_global_cleanup();

    if(failures == 0) {
        return 0;
    } else {
        return 1;
    }
}