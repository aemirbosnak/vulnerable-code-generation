//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WEBSITES 10
#define CHECK_INTERVAL 60 // in seconds

struct website {
    char *url;
    char *name;
    time_t last_checked;
    int is_up;
};

void check_website(struct website *website) {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to check %s: %s\n", website->name, curl_easy_strerror(res));
        } else {
            website->is_up = 1;
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl\n");
    }
}

int main() {
    int num_websites;
    struct website websites[MAX_WEBSITES];

    printf("Enter the number of websites to monitor (max %d): ", MAX_WEBSITES);
    scanf("%d", &num_websites);

    for(int i = 0; i < num_websites; i++) {
        printf("Enter the URL for website %d: ", i+1);
        scanf("%s", websites[i].url);

        printf("Enter the name for website %d: ", i+1);
        scanf("%s", websites[i].name);

        websites[i].last_checked = time(NULL);
        websites[i].is_up = 1;
    }

    while(1) {
        time_t current_time = time(NULL);

        for(int i = 0; i < num_websites; i++) {
            if(difftime(current_time, websites[i].last_checked) >= CHECK_INTERVAL) {
                check_website(&websites[i]);
            }
        }

        sleep(1);
    }

    return 0;
}