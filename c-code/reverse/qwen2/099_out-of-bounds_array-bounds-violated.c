#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 1024

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LEN];
    int *counts = NULL;
    size_t count_size = 0;

    while (fscanf(file, "%s", word) != EOF) {
        // Convert to lowercase
        for (char *p = word; *p; p++) {
            *p = tolower(*p);
        }

        // Remove trailing punctuation
        char *end = word + strlen(word) - 1;
        while (end > word && ispunct(*end)) {
            *end-- = '\0';
        }

        // Check if word is already in array
        int found = 0;
        for (size_t i = 0; i < count_size; i++) {
            if (strcmp(word, word + i * MAX_WORD_LEN) == 0) {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add new word
        if (!found) {
            count_size++;
            counts = realloc(counts, count_size * MAX_WORD_LEN);
            strcpy(word + count_size * MAX_WORD_LEN, word);
            counts[count_size - 1] = 1;
        }
    }

    fclose(file);

    // Print results
    for (size_t i = 0; i < count_size; i++) {
        printf("%s: %d\n", word + i * MAX_WORD_LEN, counts[i]);
    }

    free(counts);
    return EXIT_SUCCESS;
}
