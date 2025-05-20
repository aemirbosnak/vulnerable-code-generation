//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;
    return strcmp(wordA->word, wordB->word);
}

void printWordFrequency(WordFrequency *wordFrequency, int numWords) {
    qsort(wordFrequency, numWords, sizeof(WordFrequency), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequency[i].word, wordFrequency[i].frequency);
    }
}

int main() {
    char input[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *file;
    int numWords = 0;
    WordFrequency wordFrequency[MAX_WORDS];

    printf("Enter the name of the input file: ");
    scanf("%s", input);

    file = fopen(input, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        int wordLength = strlen(word);
        if (wordLength > MAX_WORD_LENGTH) {
            printf("Error: Word is too long.\n");
            exit(2);
        }
        for (int i = 0; i < wordLength; i++) {
            if (!isalpha(word[i])) {
                printf("Error: Word contains non-alphabetic characters.\n");
                exit(3);
            }
        }
        for (int i = 0; i < numWords; i++) {
            if (strcmp(wordFrequency[i].word, word) == 0) {
                wordFrequency[i].frequency++;
                break;
            }
        }
        if (numWords == MAX_WORDS) {
            printf("Error: Maximum number of words reached.\n");
            exit(4);
        }
        strcpy(wordFrequency[numWords].word, word);
        wordFrequency[numWords].frequency = 1;
        numWords++;
    }

    fclose(file);

    printWordFrequency(wordFrequency, numWords);

    return 0;
}