//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

#define MAX_THREADS 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    int length;
} Line;

void *count_words(void *arg) {
    Line *line = (Line *) arg;
    int words = 1; // assuming the line has at least one word
    char *ptr = line->line;

    while (*ptr) {
        if (isspace(*ptr)) {
            words++;
        }
        ptr++;
    }

    printf("Line %d has %d words.\n", line->length, words);
    return NULL;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    pthread_t threads[MAX_THREADS];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        Line line_data;
        line_data.line = strdup(line);
        line_data.length = strlen(line);

        pthread_create(&threads[line_number - 1], NULL, count_words, &line_data);
        line_number++;
    }

    for (int i = 0; i < line_number - 1; i++) {
        pthread_join(threads[i], NULL);
    }

    fclose(file);
    return 0;
}