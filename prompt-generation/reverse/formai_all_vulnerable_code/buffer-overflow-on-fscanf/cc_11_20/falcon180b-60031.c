//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    WordCount words[MAX_WORDS];
    int numWords = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(inputFile, "%s", word)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Maximum number of words reached.\n");
            break;
        }

        int i;
        for (i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                word[i] = '\0';
            }
        }

        int j;
        for (j = 0; j < numWords; j++) {
            if (strcmp(words[j].word, word) == 0) {
                words[j].count++;
                break;
            }
        }

        if (j == numWords) {
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;
        }
    }

    fclose(inputFile);

    int totalWords = 0;
    for (int i = 0; i < numWords; i++) {
        totalWords += words[i].count;
    }

    for (int i = 0; i < numWords; i++) {
        double frequency = (double)words[i].count / totalWords;
        printf("%s: %.2f%%\n", words[i].word, frequency * 100);
    }

    return 0;
}