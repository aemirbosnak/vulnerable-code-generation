#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int frequency;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->frequency - ((Word *)a)->frequency;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Word words[MAX_WORDS] = {0};
    char buffer[MAX_WORD_LENGTH + 2];

    while (fscanf(file, "%s", buffer) != EOF) {
        int found = 0;
        for (int i = 0; i < MAX_WORDS && words[i].word[0]; ++i) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found && strlen(buffer) <= MAX_WORD_LENGTH) {
            strcpy(words[MAX_WORDS - 1].word, buffer);
            words[MAX_WORDS - 1].frequency = 1;
        }
    }

    fclose(file);

    qsort(words, MAX_WORDS, sizeof(Word), compare);

    for (int i = 0; i < MAX_WORDS && words[i].word[0]; ++i) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return EXIT_SUCCESS;
}
