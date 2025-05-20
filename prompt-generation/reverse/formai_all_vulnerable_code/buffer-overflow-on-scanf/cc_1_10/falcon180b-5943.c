//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: scalable
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
    int is_up;
};

void check_website(struct website *website) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            website->is_up = 1;
        } else {
            website->is_up = 0;
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main() {
    int num_websites = 0;
    struct website websites[MAX_WEBSITES];

    printf("Enter number of websites to monitor: ");
    scanf("%d", &num_websites);

    if (num_websites > MAX_WEBSITES) {
        printf("Error: Maximum number of websites is %d\n", MAX_WEBSITES);
        return 1;
    }

    for (int i = 0; i < num_websites; i++) {
        printf("Enter website name: ");
        char name[100];
        scanf("%s", name);

        printf("Enter website URL: ");
        char url[100];
        scanf("%s", url);

        websites[i].name = strdup(name);
        websites[i].url = strdup(url);
        websites[i].is_up = 1;
    }

    while (1) {
        sleep(CHECK_INTERVAL);

        for (int i = 0; i < num_websites; i++) {
            check_website(&websites[i]);
        }
    }

    return 0;
}