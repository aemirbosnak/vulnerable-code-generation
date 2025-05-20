//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define TRUE 1
#define FALSE 0

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void searchForFrequentWords(char *text, int textLength, WordFrequency *frequentWords, int numFrequentWords) {
    int i, j;
    int wordLength;
    char *word;
    int wordFrequency;

    for (i = 0; i < numFrequentWords; i++) {
        frequentWords[i].frequency = 0;
    }

    for (i = 0; i < textLength; i++) {
        if (isspace(text[i])) {
            wordLength = i - 1;
            word = malloc(wordLength + 1);
            for (j = 0; j <= wordLength; j++) {
                word[j] = tolower(text[j]);
            }
            word[wordLength] = '\0';

            for (j = 0; j < numFrequentWords; j++) {
                if (strcmp(word, frequentWords[j].word) == 0) {
                    frequentWords[j].frequency++;
                    break;
                }
            }

            free(word);
        }
    }

    qsort(frequentWords, numFrequentWords, sizeof(WordFrequency), compareWords);
}

int main() {
    char text[MAX_WORDS];
    int textLength;
    WordFrequency frequentWords[MAX_WORDS];
    int numFrequentWords;

    printf("Enter a text: ");
    scanf("%[^\n]s", text);

    textLength = strlen(text);
    numFrequentWords = 0;

    while (numFrequentWords < MAX_WORDS && textLength > 0) {
        searchForFrequentWords(text, textLength, frequentWords, numFrequentWords);
        printf("Enter more text (y/n): ");
        if (tolower(getchar()) == 'n') {
            break;
        }
        scanf("%[^\n]s", text);
        textLength = strlen(text);
    }

    printf("Top %d most frequent words:\n", numFrequentWords);
    for (int i = 0; i < numFrequentWords; i++) {
        printf("%s: %d\n", frequentWords[i].word, frequentWords[i].frequency);
    }

    return 0;
}