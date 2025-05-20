//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

struct log_entry {
    char ip[16];
    char method[8];
    char url[256];
    char status_code[4];
    time_t timestamp;
};

void *process_log_entry(void *arg) {
    struct log_entry *entry = (struct log_entry *)arg;
    printf("IP: %s\nMethod: %s\nURL: %s\nStatus Code: %s\nTimestamp: %ld\n",
           entry->ip, entry->method, entry->url, entry->status_code, (long)entry->timestamp);
    return NULL;
}

int main() {
    FILE *log_file;
    char line[1024];
    struct log_entry entry;
    pthread_t threads[10];

    log_file = fopen("access.log", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    int num_threads = 0;

    while (fgets(line, sizeof(line), log_file)!= NULL) {
        if (num_threads >= 10) {
            printf("Maximum number of threads reached.\n");
            break;
        }

        if (sscanf(line, "%15s %7s %255s %3s [%ld]", entry.ip, entry.method, entry.url, entry.status_code, &entry.timestamp)!= 5) {
            printf("Invalid log entry: %s\n", line);
            continue;
        }

        pthread_create(&threads[num_threads], NULL, process_log_entry, (void *)&entry);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(log_file);

    return 0;
}