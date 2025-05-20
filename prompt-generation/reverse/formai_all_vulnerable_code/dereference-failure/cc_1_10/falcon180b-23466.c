//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <pthread.h>
#include <time.h>

#define MAX_URL_LEN 512
#define MAX_THREADS 10

// data structure for a thread
typedef struct {
    char url[MAX_URL_LEN];
    int interval;
    time_t last_check;
} thread_data;

// function to check if a website is up
size_t write_data(void *ptr, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int check_website(char *url) {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    return res == CURLE_OK? 1 : 0;
}

// function to run in a thread
void *monitor_website(void *arg) {
    thread_data *data = (thread_data *) arg;
    time_t now;

    while(1) {
        time(&now);
        if(difftime(now, data->last_check) >= data->interval) {
            if(!check_website(data->url)) {
                fprintf(stdout, "Website %s is down\n", data->url);
            }
            data->last_check = now;
        }
        sleep(1);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int i, j;
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    // parse command line arguments
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <interval> <url> [<url>...]\n", argv[0]);
        return 1;
    }

    for(i = 0; i < MAX_THREADS && i < argc - 2; i++) {
        strncpy(data[i].url, argv[i + 2], MAX_URL_LEN);
        data[i].interval = atoi(argv[1]);
        data[i].last_check = 0;

        // create thread
        if(pthread_create(&threads[i], NULL, monitor_website, &data[i])!= 0) {
            fprintf(stderr, "Failed to create thread\n");
            return 1;
        }
    }

    // wait for threads to finish
    for(i = 0; i < MAX_THREADS && i < argc - 2; i++) {
        if(pthread_join(threads[i], NULL)!= 0) {
            fprintf(stderr, "Failed to join thread\n");
            return 1;
        }
    }

    return 0;
}