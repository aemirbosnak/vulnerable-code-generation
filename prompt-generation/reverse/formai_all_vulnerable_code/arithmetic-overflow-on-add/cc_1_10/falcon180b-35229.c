//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define WORD_LENGTH 20

typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} WordFrequency;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    char c;
    char word[WORD_LENGTH] = "";
    int wordLength = 0;

    while ((c = fgetc(file))!= EOF) {
        if (isalpha(c)) {
            word[wordLength++] = tolower(c);
            if (wordLength == WORD_LENGTH) {
                words[numWords].word[WORD_LENGTH - 1] = '\0';
                words[numWords].frequency++;
                numWords++;
                wordLength = 0;
            }
        } else {
            if (wordLength > 0) {
                words[numWords].word[WORD_LENGTH - 1] = '\0';
                words[numWords].frequency++;
                numWords++;
                wordLength = 0;
            }
        }
    }

    if (wordLength > 0) {
        words[numWords].word[WORD_LENGTH - 1] = '\0';
        words[numWords].frequency++;
        numWords++;
    }

    fclose(file);

    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].frequency);
    }

    return 0;
}