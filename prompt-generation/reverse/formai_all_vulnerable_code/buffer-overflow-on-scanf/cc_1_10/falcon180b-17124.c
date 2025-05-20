//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_LEN 1024
#define MAX_THREADS 10

struct url_info {
    char *url;
    int interval;
    int timeout;
};

void *monitor_url(void *arg) {
    struct url_info *info = (struct url_info *)arg;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, info->url);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, info->timeout);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, info->timeout);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
        } else {
            printf("URL %s is up\n", info->url);
        }

        curl_easy_cleanup(curl);
    }

    pthread_exit(NULL);
}

int main() {
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    struct url_info urls[MAX_THREADS];

    printf("Enter number of URLs to monitor: ");
    scanf("%d", &num_threads);

    for(int i=0; i<num_threads; i++) {
        printf("Enter URL %d: ", i+1);
        scanf("%s", urls[i].url);
        printf("Enter monitoring interval (in seconds): ");
        scanf("%d", &urls[i].interval);
        printf("Enter timeout (in seconds): ");
        scanf("%d", &urls[i].timeout);

        pthread_create(&threads[i], NULL, monitor_url, &urls[i]);
        sleep(1); // wait for 1 second between thread creations
    }

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}