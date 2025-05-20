//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_WEBSITES 10
#define INTERVAL 60

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

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            website->is_up = 0;
        } else {
            website->is_up = 1;
        }

        curl_easy_cleanup(curl);
    }
}

void print_websites(struct website websites[], int num_websites) {
    int i;

    for(i = 0; i < num_websites; i++) {
        printf("%s - %s\n", websites[i].name, websites[i].is_up? "Up" : "Down");
    }
}

int main() {
    struct website websites[MAX_WEBSITES];
    int num_websites = 0;
    char input[256];

    printf("Enter website URLs (enter 'done' when finished):\n");

    while(1) {
        scanf("%s", input);

        if(strcmp(input, "done") == 0) {
            break;
        }

        if(num_websites >= MAX_WEBSITES) {
            printf("Maximum number of websites reached.\n");
            continue;
        }

        websites[num_websites].url = strdup(input);
        websites[num_websites].name = strdup(input);
        websites[num_websites].is_up = 1;
        num_websites++;
    }

    while(1) {
        time_t current_time;
        int i;

        time(&current_time);

        for(i = 0; i < num_websites; i++) {
            check_website(&websites[i]);
        }

        sleep(INTERVAL);
    }

    return 0;
}