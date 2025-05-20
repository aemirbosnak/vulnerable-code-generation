//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>
#include <unistd.h>

#define MAX_URL_LEN 512
#define CHECK_INTERVAL 60

struct url_info {
    char url[MAX_URL_LEN];
    time_t last_check;
};

void check_website_status(struct url_info *url_info) {
    CURL *curl;
    CURLcode res;
    char response[2048];
    time_t current_time = time(NULL);

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        sprintf(url_info->url, "http://%s", url_info->url);
        res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            url_info->last_check = current_time;
            printf("%s is up and running.\n", url_info->url);
        } else {
            url_info->last_check = 0;
            printf("%s is down.\n", url_info->url);
        }
        curl_easy_cleanup(curl);
    } else {
        printf("Failed to initialize curl.\n");
    }

    curl_global_cleanup();
}

int main() {
    struct url_info url_info[10];
    int num_urls = 0;
    char input_url[MAX_URL_LEN];

    printf("Enter website URLs (Press enter after each URL):\n");

    while(scanf("%s", input_url)!= EOF) {
        strcpy(url_info[num_urls].url, input_url);
        url_info[num_urls].last_check = 0;
        num_urls++;
    }

    while(1) {
        time_t current_time = time(NULL);
        for(int i = 0; i < num_urls; i++) {
            time_t elapsed_time = current_time - url_info[i].last_check;
            if(elapsed_time >= CHECK_INTERVAL) {
                check_website_status(&url_info[i]);
            }
        }
        sleep(1);
    }

    return 0;
}