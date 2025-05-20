//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LOG_SIZE 100000

typedef struct {
    char log_file[100];
    int start_line;
    int end_line;
} thread_data;

void *log_analysis(void *arg) {
    thread_data *data = (thread_data *) arg;
    FILE *fp;
    char line[100];
    int count = 0;

    fp = fopen(data->log_file, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", data->log_file);
        exit(1);
    }

    if (data->start_line > 0) {
        for (int i = 0; i < data->start_line - 1; i++) {
            if (fgets(line, sizeof(line), fp) == NULL) {
                printf("Error: Cannot read line %d of file %s\n", i+1, data->log_file);
                exit(1);
            }
        }
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        count++;
        if (count >= data->start_line && count <= data->end_line) {
            // Perform analysis on the log line
            printf("Thread %d analyzed line %d of file %s\n", data->start_line, count, data->log_file);
        }
        if (count == data->end_line) {
            break;
        }
    }

    fclose(fp);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int num_threads = 0;
    char log_file[100];
    int start_line, end_line;

    printf("Enter log file name: ");
    scanf("%s", log_file);

    printf("Enter number of threads (1-%d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    printf("Enter start line number for each thread:\n");
    for (int i = 0; i < num_threads; i++) {
        scanf("%d", &start_line);
        thread_data data;
        strcpy(data.log_file, log_file);
        data.start_line = start_line;
        data.end_line = start_line + MAX_LOG_SIZE / num_threads;
        pthread_create(&threads[i], NULL, log_analysis, (void *) &data);
        start_line += MAX_LOG_SIZE / num_threads;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}