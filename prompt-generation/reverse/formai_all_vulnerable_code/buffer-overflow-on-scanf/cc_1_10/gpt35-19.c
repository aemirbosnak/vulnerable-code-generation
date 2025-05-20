//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define MAX_STATUS_CODE_LEN 10

int main() {
    CURL *curl;
    CURLcode res;
    char urls[MAX_URLS][100];
    int num_urls, i;
    char status_code[MAX_STATUS_CODE_LEN];

    printf("Enter the number of URLs to monitor (max %d): ", MAX_URLS);
    scanf("%d", &num_urls);

    if (num_urls <= 0 || num_urls > MAX_URLS) {
        printf("Invalid input. Number of URLs must be between 1 and %d\n", MAX_URLS);
        return 1;
    }

    printf("Enter the URLs to monitor, one per line:\n");
    for (i = 0; i < num_urls; i++) {
        scanf("%s", urls[i]);
    }

    printf("\nChecking website status...\n\n");

    curl = curl_easy_init();

    if (curl) {
        for (i = 0; i < num_urls; i++) {
            curl_easy_setopt(curl, CURLOPT_URL, urls[i]);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
            res = curl_easy_perform(curl);

            if (res == CURLE_OK) {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
                printf("%s (%s)\n", urls[i], status_code);
            } else {
                printf("%s (Error: %s)\n", urls[i], curl_easy_strerror(res));
            }
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}