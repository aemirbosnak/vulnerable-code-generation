//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_LINE_LENGTH 1024

typedef struct {
    char line[MAX_LINE_LENGTH];
    int count;
} LineCount;

void *count_words(void *arg) {
    LineCount *line_count = (LineCount *) arg;
    char *line = strtok(line_count->line, " \t\n\r\f\v");
    int count = 0;

    while (line!= NULL) {
        count++;
        line = strtok(NULL, " \t\n\r\f\v");
    }

    line_count->count = count;
    return NULL;
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    LineCount line_counts[MAX_THREADS];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_threads >= MAX_THREADS) {
            for (int i = 0; i < MAX_THREADS; i++) {
                pthread_join(threads[i], NULL);
            }
            num_threads = 0;
        }

        strcpy(line_counts[num_threads].line, line);
        pthread_create(&threads[num_threads], NULL, count_words, &line_counts[num_threads]);
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total number of words: %d\n", 0);

    fclose(file);
    return 0;
}