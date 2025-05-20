//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URLS 50
#define MAX_LENGTH 100

void check_url(char *url);

int main(void) {
    char urls[MAX_URLS][MAX_LENGTH];
    int count = 0;
    char input[MAX_LENGTH];
    printf("Enter URLs to monitor (up to %d):\n", MAX_URLS);
    // Read URLs from user input and store in array
    while (count < MAX_URLS) {
        scanf("%s", input);
        if (strcmp(input, "end") == 0) {
            break;
        }
        strcpy(urls[count], input);
        count++;
    }
    // Check each URL
    for (int i = 0; i < count; i++) {
        check_url(urls[i]);
    }
    return 0;
}

void check_url(char *url) {
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if (http_code == 200) {
                printf("%s is up!\n", url);
            } else {
                printf("%s is down (HTTP %ld)!\n", url, http_code);
            }
        } else {
            printf("%s is down!\n", url);
        }
        curl_easy_cleanup(curl);
    }
}