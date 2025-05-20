//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct Word {
    char **words;
    int size;
} Word;

Word *createWordList(int size) {
    Word *wordList = (Word *)malloc(sizeof(Word));
    wordList->words = (char **)malloc(size * sizeof(char *));
    wordList->size = size;
    return wordList;
}

void addWordToList(Word *wordList, char *word) {
    wordList->words[wordList->size++] = word;
}

int main() {
    Word *wordList = createWordList(MAX_WORDS);

    // Multiplayer code begins here
    int numPlayers = 2;
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d, enter a word: ", i + 1);
        char *word = malloc(20);
        scanf("%s", word);
        addWordToList(wordList, word);
    }

    // Compare words and print the winner
    char *winner = NULL;
    for (int i = 0; i < wordList->size; i++) {
        for (int j = i; j < wordList->size; j++) {
            if (strcmp(wordList->words[i], wordList->words[j]) == 0) {
                winner = wordList->words[i];
            }
        }
    }

    if (winner) {
        printf("The winner is: %s\n", winner);
    } else {
        printf("No winner!\n");
    }

    return 0;
}