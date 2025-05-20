//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void readWords(FILE *file, WordFrequency *words, int *numWords) {
    char word[MAX_WORD_LENGTH];
    int count = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (count >= MAX_WORDS) {
            printf("Error: Too many words.\n");
            exit(1);
        }
        strcpy(words[count].word, word);
        words[count].count = 1;
        count++;
    }

    *numWords = count;
}

void countWords(char *text, WordFrequency *words, int numWords) {
    char word[MAX_WORD_LENGTH];
    int i;

    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            strcpy(word, "");
            while (isalpha(text[i])) {
                strcat(word, text[i]);
                i++;
            }
            if (strlen(word) > 0) {
                int found = 0;
                int j;
                for (j = 0; j < numWords; j++) {
                    if (strcmp(word, words[j].word) == 0) {
                        words[j].count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Error: Unknown word '%s'.\n", word);
                }
            }
        }
    }
}

void printWords(WordFrequency *words, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    WordFrequency words[MAX_WORDS];
    int numWords;

    if (argc!= 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    readWords(file, words, &numWords);
    countWords(argv[1], words, numWords);
    printWords(words, numWords);

    return 0;
}