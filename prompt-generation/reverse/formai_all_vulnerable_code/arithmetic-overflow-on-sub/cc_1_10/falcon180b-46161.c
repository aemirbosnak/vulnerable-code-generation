//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_WEBSITES 10
#define CHECK_INTERVAL 60 // seconds

struct website {
    char name[50];
    char url[100];
    time_t last_checked;
    int is_up;
};

void *check_website(void *arg) {
    struct website *website = arg;
    char buffer[2048];
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        sprintf(buffer, "%s HTTP/1.0", website->url);
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, buffer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
            fprintf(stderr, "Failed to check %s: %s\n", website->name, curl_easy_strerror(res));
        else
            website->is_up = 1;
        curl_easy_cleanup(curl);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_WEBSITES];
    struct website websites[MAX_WEBSITES] = {{"Google", "https://www.google.com"},
                                             {"Yahoo", "https://www.yahoo.com"},
                                             {"Bing", "https://www.bing.com"}};
    int i;

    for(i = 0; i < MAX_WEBSITES; i++) {
        websites[i].last_checked = time(NULL) - CHECK_INTERVAL;
        websites[i].is_up = 0;
        pthread_create(&threads[i], NULL, check_website, &websites[i]);
    }

    while(1) {
        sleep(CHECK_INTERVAL);
        for(i = 0; i < MAX_WEBSITES; i++) {
            if(!websites[i].is_up) {
                fprintf(stdout, "%s is down!\n", websites[i].name);
            } else {
                fprintf(stdout, "%s is up.\n", websites[i].name);
            }
        }
    }

    return 0;
}