//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

struct Word {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    struct Word *wordA = (struct Word *)a;
    struct Word *wordB = (struct Word *)b;

    return strcmp(wordA->word, wordB->word);
}

void readFile(FILE *file, struct Word words[]) {
    char word[MAX_WORD_LENGTH];
    int wordLength = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        wordLength = strlen(word);

        if (wordLength > 0 && wordLength <= MAX_WORD_LENGTH) {
            struct Word *foundWord = bsearch(word, words, MAX_WORDS, sizeof(struct Word), compareWords);

            if (foundWord == NULL) {
                struct Word newWord;
                strcpy(newWord.word, word);
                newWord.frequency = 1;
                bsearch(word, words, MAX_WORDS, sizeof(struct Word), compareWords);
            } else {
                foundWord->frequency++;
            }
        }
    }
}

void printWords(struct Word words[], int numWords) {
    qsort(words, numWords, sizeof(struct Word), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    struct Word words[MAX_WORDS];
    int numWords = 0;

    readFile(file, words);
    fclose(file);

    printWords(words, numWords);

    return 0;
}