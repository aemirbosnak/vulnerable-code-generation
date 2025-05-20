#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compare(const void *a, const void *b) {
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}

int main() {
    FILE *file = fopen("log.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    WordCount *words = NULL;
    size_t capacity = 0;
    size_t count = 0;

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        int found = 0;
        for (size_t i = 0; i < count; ++i) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (count >= capacity) {
                capacity += 10;
                words = realloc(words, capacity * sizeof(WordCount));
            }
            strcpy(words[count].word, buffer);
            words[count].count = 1;
            count++;
        }
    }

    qsort(words, count, sizeof(WordCount), compare);

    for (size_t i = 0; i < count; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    free(words);
    fclose(file);
    return EXIT_SUCCESS;
}
