//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URL_LEN 1024
#define MAX_THREADS 10

typedef struct {
    char url[MAX_URL_LEN];
    int port;
} url_t;

void *check_url(void *arg) {
    url_t *url = (url_t *) arg;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char host[MAX_URL_LEN];
        strncpy(host, url->url, strlen(url->url));
        host[strlen(url->url)] = '\0';
        curl_easy_setopt(curl, CURLOPT_URL, host);
        curl_easy_setopt(curl, CURLOPT_PORT, url->port);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            printf("Failed to check URL %s: %s\n", url->url, curl_easy_strerror(res));
        } else {
            printf("URL %s is up.\n", url->url);
        }

        curl_easy_cleanup(curl);
    }

    pthread_exit(NULL);
}

int main() {
    int num_urls = 0;
    url_t urls[MAX_URL_LEN];
    pthread_t threads[MAX_THREADS];

    printf("Enter URLs to monitor (max %d):\n", MAX_URL_LEN);
    while(scanf("%s", urls[num_urls].url)!= EOF) {
        urls[num_urls].port = 80; // Default to port 80 if not specified
        num_urls++;
    }

    printf("Enter number of threads (max %d):\n", MAX_THREADS);
    scanf("%d", &num_urls);

    for(int i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url, &urls[i]);
    }

    for(int i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}