//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URLS 10
#define CHECK_INTERVAL 60

typedef struct {
    char *url;
    int port;
} url_t;

url_t urls[MAX_URLS];
int num_urls = 0;

void *check_url(void *arg) {
    int i = *(int *) arg;
    char url[256];
    CURL *curl;
    CURLcode res;

    sprintf(url, "http://%s:%d", urls[i].url, urls[i].port);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            printf("URL %s is down\n", urls[i].url);
        } else {
            printf("URL %s is up\n", urls[i].url);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    pthread_exit(0);
}

int main() {
    int i, j;
    pthread_t threads[MAX_URLS];

    printf("Enter number of URLs to monitor: ");
    scanf("%d", &num_urls);

    for(i = 0; i < num_urls; i++) {
        printf("Enter URL %d: ", i+1);
        scanf("%s", urls[i].url);
        printf("Enter port number for %s: ", urls[i].url);
        scanf("%d", &urls[i].port);
    }

    for(i = 0; i < num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url, (void *) &i);
    }

    for(i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}