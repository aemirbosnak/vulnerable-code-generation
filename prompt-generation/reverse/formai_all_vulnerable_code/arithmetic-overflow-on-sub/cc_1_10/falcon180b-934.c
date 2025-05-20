//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define WEBSITE_URL "http://example.com"
#define CHECK_INTERVAL 60 // seconds

char *last_response = NULL;
time_t last_check = 0;

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    char *response = (char*)malloc(realsize + 1);
    memcpy(response, contents, realsize);
    response[realsize] = '\0';
    last_response = response;
    last_check = time(NULL);
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        res = curl_easy_setopt(curl, CURLOPT_URL, WEBSITE_URL);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_setopt(CURLOPT_URL) failed: %s\n",
                    curl_easy_strerror(res));
            exit(1);
        }

        res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_setopt(CURLOPT_WRITEFUNCTION) failed: %s\n",
                    curl_easy_strerror(res));
            exit(1);
        }

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            exit(1);
        }

        curl_easy_cleanup(curl);
    }

    while(1) {
        time_t current_time = time(NULL);
        if(current_time - last_check >= CHECK_INTERVAL) {
            if(last_response && strstr(last_response, "OK")) {
                printf("Website is up.\n");
            } else {
                printf("Website is down.\n");
            }
            last_response = NULL;
            last_check = current_time;
        }
        sleep(1);
    }

    curl_global_cleanup();
    return 0;
}