#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 1024

typedef struct {
    char *word;
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    WordCount *words = NULL;
    size_t capacity = 0;
    size_t size = 0;

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%1023s", buffer) == 1) {
        int found = 0;
        for (size_t i = 0; i < size; ++i) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }

        if (!found) {
            if (size >= capacity) {
                capacity = (capacity > 0) ? capacity * 2 : 1;
                words = realloc(words, capacity * sizeof(WordCount));
                if (!words) {
                    perror("Failed to allocate memory");
                    fclose(file);
                    return 1;
                }
            }
            words[size].word = strdup(buffer);
            if (!words[size].word) {
                perror("Failed to duplicate string");
                free(words);
                fclose(file);
                return 1;
            }
            words[size].count = 1;
            size++;
        }
    }

    fclose(file);

    for (size_t i = 0; i < size; ++i) {
        printf("%s: %d\n", words[i].word, words[i].count);
        free(words[i].word);
    }

    free(words);

    return 0;
}
