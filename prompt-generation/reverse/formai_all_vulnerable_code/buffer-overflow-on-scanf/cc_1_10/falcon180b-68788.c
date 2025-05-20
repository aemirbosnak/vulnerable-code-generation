//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_LEN 1024
#define MAX_THREADS 10
#define INTERVAL 60

struct thread_data {
    char url[MAX_URL_LEN];
    int interval;
};

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

void *monitor_url(void *param) {
    struct thread_data *data = (struct thread_data *) param;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, data->url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        res = curl_easy_perform(curl);

        if (res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }

    return NULL;
}

int main() {
    int i, max_threads = MAX_THREADS;
    pthread_t threads[MAX_THREADS];
    struct thread_data data[MAX_THREADS];

    printf("Enter the number of URLs to monitor: ");
    scanf("%d", &max_threads);

    printf("Enter the URLs to monitor:\n");
    for (i = 0; i < max_threads; i++) {
        scanf("%s", data[i].url);
        printf("Enter the interval for %s (in seconds): ", data[i].url);
        scanf("%d", &data[i].interval);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, monitor_url, &data[i]);
    }

    for (i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}