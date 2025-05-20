//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_WORKERS 5
#define MAX_LINES 100

typedef struct {
    char *filename;
    int num_lines;
    char **lines;
} Ebook;

void *thread_read(void *arg) {
    Ebook *ebook = arg;
    FILE *fp = fopen(ebook->filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", ebook->filename);
        exit(1);
    }

    char line[MAX_LINES];
    int line_num = 0;

    while (fgets(line, MAX_LINES, fp)!= NULL) {
        ebook->lines[line_num++] = strdup(line);
    }

    fclose(fp);
    return NULL;
}

void *thread_display(void *arg) {
    Ebook *ebook = arg;
    int num_lines = ebook->num_lines;
    char **lines = ebook->lines;

    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }

    return NULL;
}

int main() {
    Ebook ebook;
    ebook.filename = "example.txt";
    ebook.num_lines = 0;
    ebook.lines = NULL;

    pthread_t threads[MAX_THREADS];
    int num_threads = 0;

    pthread_t worker_threads[MAX_WORKERS];
    int num_workers = 0;

    FILE *fp = fopen(ebook.filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", ebook.filename);
        exit(1);
    }

    char line[MAX_LINES];
    int line_num = 0;

    while (fgets(line, MAX_LINES, fp)!= NULL) {
        ebook.lines[line_num++] = strdup(line);
    }

    fclose(fp);

    num_threads = ebook.num_lines;
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_display, &ebook);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}