//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <time.h>
#include <pthread.h>

#define MAX_URL_LEN 256
#define MAX_THREADS 10
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char *url;
    char *last_response;
    time_t last_check;
} website_t;

website_t websites[MAX_THREADS];
int num_websites = 0;

void *monitor_website(void *arg) {
    int i = *(int *) arg;
    website_t *website = &websites[i];

    while (1) {
        sleep(CHECK_INTERVAL);

        CURL *curl;
        CURLcode res;
        char readBuffer[1024];
        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if(curl) {
            sprintf(website->url, "http://%s", website->url);
            res = curl_easy_perform(curl);

            if(res!= CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));

            curl_easy_cleanup(curl);
        }

        website->last_check = time(NULL);
    }

    return NULL;
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);

    printf("Enter website URLs:\n");
    while (num_websites < MAX_THREADS) {
        char url[MAX_URL_LEN];
        fgets(url, MAX_URL_LEN, stdin);

        if (strlen(url) == 0) {
            printf("Error: Empty URL.\n");
            continue;
        }

        if (!isalpha(url[0])) {
            printf("Error: Invalid URL.\n");
            continue;
        }

        website_t *new_website = malloc(sizeof(website_t));
        strcpy(new_website->url, url);
        new_website->last_response = NULL;
        new_website->last_check = 0;

        websites[num_websites++] = *new_website;
    }

    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_websites; i++) {
        pthread_create(&threads[i], NULL, monitor_website, (void *) i);
    }

    for (int i = 0; i < num_websites; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}