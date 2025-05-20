//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_WORDS 50000
#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 20

#define SPAM_THRESHOLD 0.5

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount *words;
    int numWords;
} WordList;

void initWordList(WordList *wordList) {
    wordList->words = (WordCount *) malloc(MAX_WORDS * sizeof(WordCount));
    wordList->numWords = 0;
}

void addWord(WordList *wordList, char *word) {
    int i;
    for (i = 0; i < wordList->numWords; i++) {
        if (strcmp(word, wordList->words[i].word) == 0) {
            wordList->words[i].count++;
            return;
        }
    }
    if (wordList->numWords >= MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(wordList->words[wordList->numWords].word, word);
    wordList->words[wordList->numWords].count = 1;
    wordList->numWords++;
}

void printWordList(WordList *wordList) {
    int i;
    for (i = 0; i < wordList->numWords; i++) {
        printf("%s: %d\n", wordList->words[i].word, wordList->words[i].count);
    }
}

void freeWordList(WordList *wordList) {
    free(wordList->words);
}

int isSpam(WordList *wordList) {
    double spamScore = 0.0;
    int i;
    for (i = 0; i < wordList->numWords; i++) {
        if (strlen(wordList->words[i].word) < MIN_WORD_LENGTH) {
            continue;
        }
        if (strlen(wordList->words[i].word) > MAX_WORD_LENGTH) {
            continue;
        }
        spamScore += log(wordList->words[i].count + 1);
    }
    return spamScore > SPAM_THRESHOLD;
}

int main(int argc, char *argv[]) {
    WordList wordList;
    initWordList(&wordList);
    char word[MAX_WORD_LENGTH];
    while (fgets(word, MAX_WORD_LENGTH, stdin)!= NULL) {
        word[strcspn(word, "\n")] = '\0';
        addWord(&wordList, word);
    }
    printWordList(&wordList);
    if (isSpam(&wordList)) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }
    freeWordList(&wordList);
    return 0;
}