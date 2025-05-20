//Falcon-180B DATASET v1.0 Category: Text processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

char *lines[MAX_THREADS][MAX_LINE_LENGTH];
int line_counts[MAX_THREADS];
int thread_count;

void *process_line(void *arg) {
    int thread_id = *((int *)arg);
    char *line = lines[thread_id];
    int *word_count = &line_counts[thread_id];

    char *word = strtok(line, " \t\n");
    while (word!= NULL) {
        if (strlen(word) > MAX_WORD_LENGTH) {
            printf("Thread %d: Word '%s' is too long.\n", thread_id, word);
        } else {
            (*word_count)++;
        }
        word = strtok(NULL, " \t\n");
    }

    return NULL;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int line_length = strlen(line);
        if (line_length == 0 || line[line_length - 1] == '\n') {
            line[--line_length] = '\0';
        }
        for (int i = 0; i < thread_count; i++) {
            lines[i][line_counts[i]] = strdup(line);
            line_counts[i]++;
        }
    }

    fclose(file);

    pthread_t threads[MAX_THREADS];
    for (int i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], NULL, process_line, &i);
    }

    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}