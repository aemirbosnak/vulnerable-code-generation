//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void readWords(FILE *file, WordFrequency words[MAX_WORDS]) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].frequency = 0;
        i++;
    }
}

void countWords(char *text, WordFrequency words[MAX_WORDS]) {
    int i, j, k;
    char word[MAX_WORD_LENGTH];

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            j = 0;
            while (isalpha(text[i + j])) {
                word[j] = tolower(text[i + j]);
                j++;
            }
            word[j] = '\0';

            for (k = 0; k < i; k++) {
                if (strcmp(words[k].word, word) == 0) {
                    words[k].frequency++;
                    break;
                }
            }

            if (k == i) {
                strcpy(words[i].word, word);
                words[i].frequency = 1;
                i++;
            }
        }
    }
}

void printWords(WordFrequency words[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i].word, "")!= 0) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency words[MAX_WORDS];

    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    readWords(file, words);
    fclose(file);

    countWords(argv[2], words);

    printWords(words);

    return 0;
}