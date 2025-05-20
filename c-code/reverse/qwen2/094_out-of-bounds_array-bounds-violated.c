#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    int max_words = 100;
    char **words = malloc(max_words * sizeof(char *));
    int *counts = malloc(max_words * sizeof(int));
    if (!words || !counts) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    int word_count = 0;

    while (1) {
        char word[MAX_WORD_LENGTH];
        if (fscanf(file, "%s", word) != 1) {
            break;
        }
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], word) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[word_count] = strdup(word);
            counts[word_count] = 1;
            word_count++;
            if (word_count >= max_words) {
                max_words *= 2;
                words = realloc(words, max_words * sizeof(char *));
                counts = realloc(counts, max_words * sizeof(int));
                if (!words || !counts) {
                    perror("Realloc failed");
                    free(words);
                    free(counts);
                    fclose(file);
                    return 1;
                }
            }
        }
    }

    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], counts[i]);
        free(words[i]);
    }

    free(words);
    free(counts);
    fclose(file);

    return 0;
}
