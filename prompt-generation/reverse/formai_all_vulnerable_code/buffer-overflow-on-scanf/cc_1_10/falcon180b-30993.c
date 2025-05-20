//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URLS 10
#define TIMEOUT 10
#define THREAD_COUNT 5

struct url_data {
    char *url;
    int status_code;
};

void *monitor_url(void *arg) {
    struct url_data *data = arg;
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    data->status_code = res;
    return NULL;
}

int main() {
    struct url_data urls[MAX_URLS];
    pthread_t threads[THREAD_COUNT];
    int i, j, rc;

    for(i = 0; i < MAX_URLS; i++) {
        printf("Enter URL %d: ", i+1);
        scanf("%s", urls[i].url);
    }

    for(i = 0; i < THREAD_COUNT; i++) {
        for(j = 0; j < MAX_URLS; j++) {
            if(urls[j].status_code == 0) {
                rc = pthread_create(&threads[i], NULL, monitor_url, &urls[j]);
                if(rc) {
                    printf("Error: unable to create thread, %d\n", rc);
                    exit(-1);
                }
                urls[j].status_code = 1;
                break;
            }
        }
    }

    for(i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    for(i = 0; i < MAX_URLS; i++) {
        printf("URL %d status code: %d\n", i+1, urls[i].status_code);
    }

    return 0;
}