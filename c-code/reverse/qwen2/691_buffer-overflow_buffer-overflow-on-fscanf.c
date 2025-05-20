#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char word[MAX_WORD_LENGTH];
    int count[MAX_WORD_LENGTH] = {0};
    size_t unique_words = 0;

    while (fscanf(file, "%s", word) != EOF) {
        int found = 0;
        for (size_t i = 0; i < unique_words; ++i) {
            if (strcmp(word, word + i * (MAX_WORD_LENGTH + 1)) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(word + unique_words * (MAX_WORD_LENGTH + 1), word);
            count[unique_words]++;
            unique_words++;
        }
    }

    fclose(file);

    printf("Word counts:\n");
    for (size_t i = 0; i < unique_words; ++i) {
        printf("%s: %d\n", word + i * (MAX_WORD_LENGTH + 1), count[i]);
    }

    return EXIT_SUCCESS;
}
