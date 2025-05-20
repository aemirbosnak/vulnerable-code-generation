#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 1024

typedef struct {
    char *word;
    int count;
} WordCount;

int main() {
    FILE *file = fopen("log.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    WordCount *counts = NULL;
    size_t capacity = 0;
    size_t count_size = 0;

    char buffer[MAX_WORD_LEN];
    while (fgets(buffer, sizeof(buffer), file)) {
        char *token = strtok(buffer, " \t\n\r.,;:!?");
        while (token) {
            int found = 0;
            for (size_t i = 0; i < count_size; ++i) {
                if (strcmp(counts[i].word, token) == 0) {
                    counts[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                if (count_size >= capacity) {
                    capacity += 10;
                    counts = realloc(counts, capacity * sizeof(WordCount));
                }
                counts[count_size].word = strdup(token);
                counts[count_size].count = 1;
                count_size++;
            }
            token = strtok(NULL, " \t\n\r.,;:!?");
        }
    }

    fclose(file);

    for (size_t i = 0; i < count_size; ++i) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
        free(counts[i].word);
    }

    free(counts);

    return EXIT_SUCCESS;
}
