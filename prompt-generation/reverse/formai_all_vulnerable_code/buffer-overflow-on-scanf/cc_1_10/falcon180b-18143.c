//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_WEBSITES 10
#define CHECK_INTERVAL 60 // seconds

struct website {
    char *url;
    char *name;
};

int check_website(const char *url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            printf("Website %s is up.\n", url);
            return 1;
        } else {
            printf("Website %s is down.\n", url);
            return 0;
        }
    } else {
        printf("Failed to initialize curl.\n");
        return -1;
    }
}

void main() {
    struct website websites[MAX_WEBSITES];
    int num_websites = 0;
    char input[100];

    printf("Enter the number of websites to monitor (up to %d): ", MAX_WEBSITES);
    scanf("%d", &num_websites);

    for (int i = 0; i < num_websites; i++) {
        printf("Enter website %d URL: ", i+1);
        scanf("%s", input);
        websites[i].url = strdup(input);
        printf("Enter website %d name: ", i+1);
        scanf("%s", input);
        websites[i].name = strdup(input);
    }

    while (1) {
        for (int i = 0; i < num_websites; i++) {
            if (check_website(websites[i].url) == 0) {
                printf("Website %s is down.\n", websites[i].name);
            }
        }
        sleep(CHECK_INTERVAL);
    }
}