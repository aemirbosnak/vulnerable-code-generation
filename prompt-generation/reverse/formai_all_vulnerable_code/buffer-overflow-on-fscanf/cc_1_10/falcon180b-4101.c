//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_THREADS 10
#define MAX_NUM_PATTERNS 10

void *thread_func(void *arg);
int compare_pattern(const char *pattern, const char *line);

int main(int argc, char **argv) {
    int num_threads = 1;
    char *pattern_file = "patterns.txt";
    char *log_file = "log.txt";
    FILE *pattern_fp, *log_fp;
    char pattern[MAX_LINE_SIZE];
    pthread_t threads[MAX_NUM_THREADS];

    pattern_fp = fopen(pattern_file, "r");
    if (pattern_fp == NULL) {
        fprintf(stderr, "Error: could not open pattern file.\n");
        exit(1);
    }

    log_fp = fopen(log_file, "r");
    if (log_fp == NULL) {
        fprintf(stderr, "Error: could not open log file.\n");
        exit(1);
    }

    while (fscanf(pattern_fp, "%s", pattern)!= EOF) {
        if (num_threads >= MAX_NUM_THREADS) {
            fprintf(stderr, "Error: reached maximum number of threads.\n");
            exit(1);
        }
        pthread_create(&threads[num_threads], NULL, thread_func, pattern);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(pattern_fp);
    fclose(log_fp);
    return 0;
}

void *thread_func(void *arg) {
    char *pattern = arg;
    char line[MAX_LINE_SIZE];
    FILE *log_fp;

    log_fp = fopen("log.txt", "a");
    if (log_fp == NULL) {
        fprintf(stderr, "Error: could not open log file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_SIZE, stdin)!= NULL) {
        if (compare_pattern(pattern, line) == 1) {
            fprintf(log_fp, "Intrusion detected: %s\n", pattern);
            break;
        }
    }

    fclose(log_fp);
    pthread_exit(NULL);
}

int compare_pattern(const char *pattern, const char *line) {
    int len_pattern = strlen(pattern);
    int len_line = strlen(line);

    if (len_line < len_pattern) {
        return 0;
    }

    int i, j;
    for (i = 0, j = 0; i < len_line && j < len_pattern; i++) {
        if (line[i]!= pattern[j]) {
            j = 0;
        } else {
            j++;
        }
    }

    if (j == len_pattern) {
        return 1;
    } else {
        return 0;
    }
}