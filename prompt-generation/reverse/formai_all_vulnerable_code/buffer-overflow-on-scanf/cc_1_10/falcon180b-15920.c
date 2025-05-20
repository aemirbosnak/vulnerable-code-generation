//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    return wordA->frequency - wordB->frequency;
}

int main() {
    srand(time(NULL));

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    char inputWord;
    while (scanf("%c", &inputWord) == 1 && inputWord!= '\n') {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words.\n");
            exit(1);
        }

        char word[MAX_WORD_LENGTH];
        generateRandomWord(word);

        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(word, words[i].word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[numWords].word, word);
            words[numWords].frequency = 1;
            numWords++;
        }
    }

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}