//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

void readWords(FILE *file, WordCount words[]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            words[i].word[0] = tolower(ch);
            int j = 1;
            while ((ch = fgetc(file))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH) {
                    words[i].word[j] = tolower(ch);
                    j++;
                }
            }
            words[i].word[j] = '\0';
            words[i].count++;
            i++;
        }
    }
}

void spellCheck(FILE *inputFile, FILE *outputFile, WordCount words[]) {
    char ch;
    int i = 0;

    while ((ch = fgetc(inputFile))!= EOF) {
        if (isalpha(ch)) {
            char word[MAX_WORD_LENGTH + 1];
            int j = 0;
            while ((ch = fgetc(inputFile))!= EOF && isalnum(ch)) {
                if (j < MAX_WORD_LENGTH) {
                    word[j] = tolower(ch);
                    j++;
                }
            }
            word[j] = '\0';

            int found = 0;
            for (int k = 0; k < i; k++) {
                if (strcmp(word, words[k].word) == 0) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                fprintf(outputFile, "Possible misspelling: %s\n", word);
            }
        } else {
            fputc(ch, outputFile);
        }
    }
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    readWords(inputFile, words);

    fprintf(outputFile, "Total words: %d\n", numWords);

    spellCheck(inputFile, outputFile, words);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}