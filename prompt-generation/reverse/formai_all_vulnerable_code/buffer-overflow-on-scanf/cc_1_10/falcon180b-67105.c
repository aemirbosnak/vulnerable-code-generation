//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
// A website uptime monitoring system using C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_WEBSITES 10
#define SLEEP_INTERVAL 60 // Sleep for 60 seconds between checks

struct website {
    char *url;
    int is_up;
};

int check_website(struct website *website) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to check website '%s': %s\n", website->url, curl_easy_strerror(res));
        } else {
            website->is_up = 1;
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }

    return website->is_up;
}

int main() {
    int num_websites = 0;
    struct website websites[MAX_WEBSITES];

    printf("Enter the number of websites to monitor (up to %d): ", MAX_WEBSITES);
    scanf("%d", &num_websites);

    for(int i = 0; i < num_websites; i++) {
        printf("Enter website %d URL: ", i+1);
        scanf("%s", websites[i].url);
        websites[i].is_up = 0;
    }

    while(1) {
        for(int i = 0; i < num_websites; i++) {
            if(!websites[i].is_up) {
                int is_up = check_website(&websites[i]);
                if(is_up) {
                    printf("Website %s is back up!\n", websites[i].url);
                }
            }
        }

        sleep(SLEEP_INTERVAL);
    }

    return 0;
}