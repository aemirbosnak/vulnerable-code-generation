//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_WEBSITES 10

struct website {
    char *url;
    char *name;
    int interval;
    int status;
};

struct website websites[MAX_WEBSITES];

void *check_website(void *arg) {
    int i = *(int *) arg;
    CURL *curl;
    CURLcode res;
    char *url = websites[i].url;
    char *name = websites[i].name;
    int interval = websites[i].interval;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        res = curl_easy_perform(curl);

        if(res == CURLE_OK) {
            printf("Website %s is up.\n", name);
            websites[i].status = 1;
        } else {
            printf("Website %s is down.\n", name);
            websites[i].status = 0;
        }

        curl_easy_cleanup(curl);
    }

    return NULL;
}

int main() {
    int i, n;
    pthread_t threads[MAX_WEBSITES];

    printf("Enter number of websites to monitor: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter website URL for %d: ", i+1);
        scanf("%s", websites[i].url);
        printf("Enter website name for %d: ", i+1);
        scanf("%s", websites[i].name);
        printf("Enter interval in seconds for %d: ", i+1);
        scanf("%d", &websites[i].interval);
    }

    for(i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, check_website, (void *) i);
    }

    for(i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}