//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    int isPositive;
} Word;

Word dictionary[MAX_WORDS];
int numWords = 0;

void loadDictionary() {
    FILE *fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    char line[100];
    Word tempWord;

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%s%d", tempWord.word, &tempWord.isPositive);
        if (numWords >= MAX_WORDS) {
            printf("Error: Dictionary too large.\n");
            exit(1);
        }
        dictionary[numWords++] = tempWord;
    }

    fclose(fp);
}

int getSentimentScore(char *text) {
    int numPositive = 0;
    int numNegative = 0;
    char word[WORD_LENGTH];
    int length = 0;

    while (*text != '\0') {
        if (isalpha(*text)) {
            word[length++] = tolower(*text);
            word[length] = '\0';
            int i;
            for (i = 0; i < numWords; i++) {
                if (strcmp(word, dictionary[i].word) == 0) {
                    if (dictionary[i].isPositive == 1) {
                        numPositive++;
                    } else {
                        numNegative++;
                    }
                    break;
                }
            }
            length = 0;
        }
        text++;
    }

    return numPositive - numNegative;
}

int main() {
    loadDictionary();

    char input[100];
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int score = getSentimentScore(input);

    if (score > 0) {
        printf("Sentiment is positive.\n");
    } else if (score < 0) {
        printf("Sentiment is negative.\n");
    } else {
        printf("Sentiment is neutral.\n");
    }

    return 0;
}