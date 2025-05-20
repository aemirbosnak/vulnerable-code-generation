//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void generateRandomWord(char* word) {
    const char vowels[] = "aeiouAEIOU";
    const char consonants[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    word[0] = consonants[rand() % strlen(consonants)];
    for (int i = 1; i < MAX_WORD_LENGTH - 1; i++) {
        if (rand() % 2 == 0) {
            word[i] = vowels[rand() % strlen(vowels)];
        } else {
            word[i] = consonants[rand() % strlen(consonants)];
        }
    }
    word[MAX_WORD_LENGTH - 1] = '\0';
}

int compareWords(const void* a, const void* b) {
    const WordFrequency* wordA = (const WordFrequency*)a;
    const WordFrequency* wordB = (const WordFrequency*)b;

    return wordB->frequency - wordA->frequency;
}

int main() {
    srand(time(NULL));

    char* words[MAX_WORDS];
    WordFrequency frequencies[MAX_WORDS];
    int numWords = 0;

    printf("Enter words (type 'done' when finished):\n");
    while (numWords < MAX_WORDS && fgets(words[numWords], MAX_WORD_LENGTH, stdin)!= NULL) {
        if (strcmp(words[numWords], "done") == 0) {
            break;
        }
        numWords++;
    }

    for (int i = 0; i < numWords; i++) {
        strcpy(frequencies[i].word, words[i]);
        frequencies[i].frequency = 1;
    }

    qsort(frequencies, numWords, sizeof(WordFrequency), compareWords);

    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < numWords && i < 10; i++) {
        printf("%s: %d\n", frequencies[i].word, frequencies[i].frequency);
    }

    return 0;
}