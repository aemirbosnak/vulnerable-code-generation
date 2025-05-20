//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <curl/curl.h>

#define MAX_THREADS 10
#define MAX_URL_LENGTH 2048

struct url_data {
    char *url;
    int status;
};

void *sanitize_url(void *ptr) {
    struct url_data *data = (struct url_data *)ptr;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            data->status = res;
        } else {
            data->status = 0;
        }

        curl_easy_cleanup(curl);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, rc;
    struct url_data data[MAX_THREADS];

    for(i = 0; i < MAX_THREADS; i++) {
        printf("Enter URL %d: ", i+1);
        scanf("%s", data[i].url);
    }

    for(i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, sanitize_url, &data[i]);
        if(rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for(i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}