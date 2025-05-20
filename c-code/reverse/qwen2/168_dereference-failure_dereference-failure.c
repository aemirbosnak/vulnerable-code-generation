#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compare(const void *a, const void *b) {
    return ((Word *)b)->count - ((Word *)a)->count;
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    Word words[MAX_WORDS] = {0};
    char buffer[MAX_WORD_LENGTH];

    while (fscanf(inputFile, "%s", buffer) != EOF) {
        int found = 0;
        for (int i = 0; i < MAX_WORDS; i++) {
            if (strcmp(words[i].word, buffer) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        if (!found && strlen(buffer) > 0) {
            strcpy(words[words[0].count].word, buffer);
            words[words[0].count].count = 1;
            words[0].count++;
        }
    }

    fclose(inputFile);

    qsort(words, words[0].count, sizeof(Word), compare);

    FILE *outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < words[0].count; i++) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(outputFile);

    return EXIT_SUCCESS;
}
