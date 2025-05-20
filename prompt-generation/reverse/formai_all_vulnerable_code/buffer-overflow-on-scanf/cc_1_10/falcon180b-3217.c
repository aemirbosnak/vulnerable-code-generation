//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_WEBSITES 10

struct website {
    char name[100];
    char url[200];
    int is_up;
};

struct website websites[MAX_WEBSITES];

void *monitor_website(void *arg) {
    struct website *website = (struct website *) arg;
    char buffer[4096];
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", website->url, website->url);
        res = curl_easy_setopt(curl, CURLOPT_URL, website->url);
        res = curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, buffer);
        res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            website->is_up = 0;
            printf("%s is down\n", website->name);
        } else {
            website->is_up = 1;
            printf("%s is up\n", website->name);
        }
        curl_easy_cleanup(curl);
    } else {
        printf("curl_easy_init failed\n");
    }

    return NULL;
}

int main() {
    int i;

    for(i = 0; i < MAX_WEBSITES; i++) {
        printf("Enter website name: ");
        scanf("%s", websites[i].name);
        printf("Enter website URL: ");
        scanf("%s", websites[i].url);
        websites[i].is_up = 1;
    }

    pthread_t threads[MAX_WEBSITES];

    for(i = 0; i < MAX_WEBSITES; i++) {
        pthread_create(&threads[i], NULL, monitor_website, (void *) &websites[i]);
    }

    for(i = 0; i < MAX_WEBSITES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}