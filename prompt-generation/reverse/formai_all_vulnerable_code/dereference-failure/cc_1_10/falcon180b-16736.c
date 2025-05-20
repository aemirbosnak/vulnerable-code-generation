//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define CHECK_INTERVAL 60 // seconds

struct thread_data {
    char *url;
    int id;
};

void *monitor_thread(void *data) {
    struct thread_data *thread_data = (struct thread_data *) data;
    char url[100];
    strcpy(url, thread_data->url);

    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        res = curl_easy_perform(curl);

        if(res!= CURLE_OK) {
            fprintf(stderr, "Thread %d: curl_easy_perform() failed: %s\n", thread_data->id, curl_easy_strerror(res));
        } else {
            fprintf(stdout, "Thread %d: %s is up\n", thread_data->id, url);
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Thread %d: curl_easy_init() failed\n", thread_data->id);
    }

    curl_global_cleanup();
    free(data);
    return NULL;
}

int main() {
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];

    // Read urls from file
    FILE *fp;
    char line[100];
    fp = fopen("urls.txt", "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: could not open urls.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *url = strtok(line, "\n");
        struct thread_data *thread_data = (struct thread_data *) malloc(sizeof(struct thread_data));
        thread_data->url = url;
        thread_data->id = num_threads++;

        pthread_create(&threads[num_threads - 1], NULL, monitor_thread, thread_data);
    }

    fclose(fp);

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}