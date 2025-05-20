//Falcon-180B DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    if (wordA->frequency > wordB->frequency) {
        return -1;
    } else if (wordA->frequency < wordB->frequency) {
        return 1;
    } else {
        return 0;
    }
}

void readWordsFromFile(FILE* file, WordFrequency* words) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        int i;
        for (i = 0; i < MAX_WORDS - 1 && words[i].word[0]!= '\0'; i++) {
            // Ignore words that exceed the maximum length
            if (strlen(word) > MAX_WORD_LENGTH - 1) {
                break;
            }
            // Ignore duplicate words
            if (strcmp(word, words[i].word) == 0) {
                break;
            }
        }
        // Add new word to the array
        if (i < MAX_WORDS - 1) {
            strcpy(words[i].word, word);
            words[i].frequency = 1;
        }
    }
}

void printTopNWords(WordFrequency* words, int n) {
    qsort(words, MAX_WORDS, sizeof(WordFrequency), compareWords);

    printf("Top %d most frequent words:\n", n);
    for (int i = 0; i < n && words[i].word[0]!= '\0'; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    WordFrequency words[MAX_WORDS];
    readWordsFromFile(file, words);

    int n;
    printf("Enter the number of top words to print: ");
    scanf("%d", &n);

    printTopNWords(words, n);

    fclose(file);
    return 0;
}