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

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    Word words[MAX_WORDS] = {0};
    char line[MAX_WORD_LENGTH * MAX_WORDS];
    char *token;

    while (fgets(line, sizeof(line), inputFile)) {
        token = strtok(line, " \n\t.,;:!?");
        while (token) {
            int found = 0;
            for (int i = 0; i < MAX_WORDS && words[i].word[0]; i++) {
                if (strcmp(words[i].word, token) == 0) {
                    words[i].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                for (int i = 0; i < MAX_WORDS && words[i].word[0]; i++) {
                    if (words[i].word[0] == '\0') {
                        strcpy(words[i].word, token);
                        words[i].count = 1;
                        break;
                    }
                }
            }
            token = strtok(NULL, " \n\t.,;:!?");
        }
    }

    qsort(words, MAX_WORDS, sizeof(Word), compare);

    for (int i = 0; i < MAX_WORDS && words[i].word[0]; i++) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
