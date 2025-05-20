//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_SITES 10
#define TIMEOUT 5

struct site {
    char *url;
    int status;
    pthread_t thread;
};

void *monitor_site(void *arg) {
    struct site *site = (struct site *) arg;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, site->url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            site->status = 200;
        } else {
            site->status = 500;
        }

        curl_easy_cleanup(curl);
    }

    return NULL;
}

int main() {
    struct site sites[MAX_SITES];
    pthread_t threads[MAX_SITES];
    int i;

    for(i = 0; i < MAX_SITES; i++) {
        sites[i].url = (char *) malloc(100);
        sites[i].status = -1;
        sites[i].thread = 0;
    }

    printf("Enter URLs:\n");
    scanf("%s", sites[0].url);
    sites[0].thread = pthread_create(&threads[0], NULL, monitor_site, &sites[0]);

    scanf("%s", sites[1].url);
    sites[1].thread = pthread_create(&threads[1], NULL, monitor_site, &sites[1]);

    // Add more sites as needed

    for(i = 0; i < MAX_SITES; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}