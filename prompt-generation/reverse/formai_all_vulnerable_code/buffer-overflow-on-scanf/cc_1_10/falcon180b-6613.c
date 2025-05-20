//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define MAX_URL_LENGTH 1024
#define MAX_THREADS 10
#define PING_INTERVAL 30

typedef struct {
    char *url;
    pthread_t thread_id;
    time_t last_ping;
} website_t;

void *ping_website(void *arg) {
    website_t *website = (website_t *) arg;
    CURL *curl;
    CURLcode res;
    time_t now = time(NULL);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, website->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "Failed to ping %s: %s\n", website->url, curl_easy_strerror(res));
        } else {
            website->last_ping = now;
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    website_t websites[MAX_THREADS];

    while(num_threads < MAX_THREADS && scanf("%s", websites[num_threads].url)!= EOF) {
        websites[num_threads].last_ping = 0;
        pthread_create(&threads[num_threads], NULL, ping_website, &websites[num_threads]);
        num_threads++;
    }

    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}