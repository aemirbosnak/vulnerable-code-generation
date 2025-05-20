//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define BUFFER_SIZE 256

typedef struct {
    char url[BUFFER_SIZE];
    int interval; // seconds
    int id;
} MonitorTask;

void* monitor_website(void* arg) {
    MonitorTask *task = (MonitorTask *)arg;
    CURL *curl;
    CURLcode res;

    while (1) {
        curl = curl_easy_init();
        if (curl) {
            curl_easy_setopt(curl, CURLOPT_URL, task->url);
            curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Only check the headers
            res = curl_easy_perform(curl);
            
            if (res == CURLE_OK) {
                printf("URL %d (%s): UP\n", task->id, task->url);
            } else {
                printf("URL %d (%s): DOWN (Error: %s)\n", task->id, task->url, curl_easy_strerror(res));
            }
            curl_easy_cleanup(curl);
        }
        sleep(task->interval);
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_URLS];
    MonitorTask tasks[MAX_URLS];
    int task_count = 0;

    printf("Welcome to the Multiplayer Website Uptime Monitor!\n");
    printf("You can monitor up to %d websites.\n", MAX_URLS);

    while (task_count < MAX_URLS) {
        printf("Enter URL to monitor (or 'exit' to finish): ");
        char input[BUFFER_SIZE];
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (task_count < MAX_URLS) {
            strcpy(tasks[task_count].url, input);
            tasks[task_count].id = task_count + 1;

            printf("Enter check interval in seconds for %s: ", input);
            scanf("%d", &(tasks[task_count].interval));

            if (pthread_create(&threads[task_count], NULL, monitor_website, (void*)&tasks[task_count])) {
                fprintf(stderr, "Error creating thread for %s\n", input);
                continue;
            }
            task_count++;
        } else {
            printf("Max URL limit reached!\n");
        }
    }

    // Wait for all threads to finish (this won't happen in this demo since they run forever)
    for (int i = 0; i < task_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}