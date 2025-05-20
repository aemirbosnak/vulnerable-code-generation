//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAX_THREADS 10
#define MAX_LOG_ENTRIES 10000

typedef struct log_entry {
    time_t timestamp;
    char ip_address[16];
    char request[100];
} log_entry_t;

typedef struct {
    int id;
    int start_index;
    int end_index;
} thread_data_t;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

log_entry_t log_entries[MAX_LOG_ENTRIES];
int log_entry_count = 0;

void process_log_entry(log_entry_t* entry) {
    printf("Timestamp: %s, IP Address: %s, Request: %s\n",
           ctime(&entry->timestamp), entry->ip_address, entry->request);
}

void* analyze_log_thread(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    int start_index = data->start_index;
    int end_index = data->end_index;

    for (int i = start_index; i < end_index; i++) {
        process_log_entry(&log_entries[i]);
    }

    return NULL;
}

int main() {
    int num_threads = 4;
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < num_threads; i++) {
        thread_data_t data;
        data.id = i + 1;
        data.start_index = i * MAX_LOG_ENTRIES / num_threads;
        data.end_index = (i + 1) * MAX_LOG_ENTRIES / num_threads - 1;
        if (i == num_threads - 1) {
            data.end_index = MAX_LOG_ENTRIES - 1;
        }

        pthread_create(&threads[i], NULL, analyze_log_thread, &data);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}