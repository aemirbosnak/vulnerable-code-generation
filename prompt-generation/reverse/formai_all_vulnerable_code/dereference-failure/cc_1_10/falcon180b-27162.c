//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_SIZE 1024
#define EBOOK_FILE "ebook.txt"

typedef struct {
    char* line;
    int line_num;
} Line;

void* read_ebook(void* arg) {
    int thread_id = *(int*) arg;
    FILE* ebook_file = fopen(EBOOK_FILE, "r");
    if (ebook_file == NULL) {
        printf("Thread %d: Error opening ebook file.\n", thread_id);
        return NULL;
    }

    Line lines[MAX_LINE_SIZE];
    int num_lines = 0;

    char* line = NULL;
    size_t line_size = 0;
    while (getline(&line, &line_size, ebook_file)!= -1) {
        if (num_lines >= MAX_LINE_SIZE) {
            printf("Thread %d: Maximum number of lines reached.\n", thread_id);
            break;
        }

        lines[num_lines].line = strdup(line);
        lines[num_lines].line_num = thread_id * MAX_LINE_SIZE + num_lines + 1;
        num_lines++;
    }

    fclose(ebook_file);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_id = 0;

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, read_ebook, (void*) &thread_id);
        thread_id++;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}