//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 100

int num_threads = 0;
pthread_t threads[MAX_THREADS];

void *thread_func(void *arg) {
    char *line = (char *) arg;
    int len = strlen(line);
    int i;
    for (i = 0; i < len; i++) {
        if (line[i] >= '0' && line[i] <= '9') {
            printf("%c", line[i]);
        } else if (line[i] >= 'A' && line[i] <= 'F') {
            printf("%c", line[i]);
        } else if (line[i] >= 'a' && line[i] <= 'f') {
            printf("%c", line[i]);
        } else {
            printf("Invalid character: %c", line[i]);
        }
    }
    printf("\n");
    return NULL;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *filename = "input.txt";
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        exit(1);
    }
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        pthread_t thread_id;
        int rc;
        num_threads++;
        rc = pthread_create(&thread_id, NULL, thread_func, (void *) line);
        if (rc) {
            printf("Error creating thread: %s\n", strerror(rc));
            exit(1);
        }
    }
    while (num_threads > 0) {
        pthread_join(threads[--num_threads], NULL);
    }
    fclose(fp);
    return 0;
}