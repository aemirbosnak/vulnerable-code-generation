//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_WEBSITES 10
#define MAX_THREADS 10
#define CHECK_INTERVAL 60 // seconds

typedef struct {
    char *url;
    char *name;
} website_t;

website_t websites[MAX_WEBSITES];

int num_websites = 0;

void *check_website(void *arg) {
    int i = *(int *) arg;
    char url[512];
    CURL *curl;
    CURLcode res;

    sprintf(url, "%s", websites[i].url);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "Thread %d: Failed to check website '%s': %s\n", i, websites[i].name, curl_easy_strerror(res));
        } else {
            fprintf(stdout, "Thread %d: Website '%s' is up.\n", i, websites[i].name);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    pthread_exit(NULL);
}

int main() {
    int i;

    printf("Enter number of websites to monitor: ");
    scanf("%d", &num_websites);

    for(i = 0; i < num_websites; i++) {
        printf("Enter website URL for %d: ", i+1);
        scanf("%s", websites[i].url);

        printf("Enter website name for %d: ", i+1);
        scanf("%s", websites[i].name);
    }

    pthread_t threads[MAX_THREADS];

    for(i = 0; i < num_websites; i++) {
        pthread_create(&threads[i], NULL, check_website, (void *) &i);
    }

    for(i = 0; i < num_websites; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}