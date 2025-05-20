//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

void loadWords(Word words[], int numWords) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%s", words[i].word)!= EOF) {
        i++;
        if (i >= numWords) {
            break;
        }
    }
    fclose(file);
}

int compareWords(const void *a, const void *b) {
    Word wordA = *(Word *)a;
    Word wordB = *(Word *)b;
    return strcmp(wordA.word, wordB.word);
}

void countWords(Word words[], int numWords, char input[]) {
    char *word = strtok(input, " ");
    while (word!= NULL) {
        int i = 0;
        while (i < numWords && strcmp(word, words[i].word)!= 0) {
            i++;
        }
        if (i < numWords) {
            words[i].count++;
        }
        word = strtok(NULL, " ");
    }
}

void printWords(Word words[], int numWords) {
    qsort(words, numWords, sizeof(Word), compareWords);
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords = 0;
    loadWords(words, MAX_WORDS);
    numWords = MAX_WORDS;
    char input[1000];
    while (1) {
        printf("Enter text to check: ");
        fgets(input, 1000, stdin);
        countWords(words, numWords, input);
        printWords(words, numWords);
        printf("\n");
    }
    return 0;
}