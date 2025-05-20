//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10
#define TIMEOUT 10

struct website {
    char *url;
    int port;
    char *host;
};

void *monitor_website(void *arg) {
    struct website *website = (struct website *) arg;
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char url[1024];
        snprintf(url, sizeof(url), "http://%s:%d", website->host, website->port);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            printf("Failed to connect to %s:%d - %s\n", website->host, website->port, curl_easy_strerror(res));
        } else {
            printf("Connection to %s:%d successful\n", website->host, website->port);
        }

        curl_easy_cleanup(curl);
    }

    pthread_exit(NULL);
}

int main() {
    int num_websites, i;
    pthread_t threads[MAX_THREADS];
    struct website websites[MAX_THREADS];

    printf("Enter number of websites to monitor: ");
    scanf("%d", &num_websites);

    for(i = 0; i < num_websites; i++) {
        printf("Enter website %d details:\n", i+1);
        printf("URL: ");
        scanf("%s", websites[i].url);
        printf("Port: ");
        scanf("%d", &websites[i].port);
        printf("Host: ");
        scanf("%s", websites[i].host);
    }

    for(i = 0; i < num_websites; i++) {
        pthread_create(&threads[i], NULL, monitor_website, (void *) &websites[i]);
    }

    for(i = 0; i < num_websites; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}