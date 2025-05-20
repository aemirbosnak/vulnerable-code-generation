//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 5000
#define WORD_LENGTH 30

// structure to store words
typedef struct {
    char word[WORD_LENGTH];
    int frequency;
} Word;

// function to compare two words
int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *)a;
    const Word *wordB = (const Word *)b;
    return strcmp(wordA->word, wordB->word);
}

// function to load dictionary from file
void loadDictionary(char *filename, Word *dictionary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error loading dictionary file\n");
        exit(1);
    }

    int wordCount = 0;
    Word *currentWord = dictionary;
    char word[WORD_LENGTH];

    // read words from file and add to dictionary
    while (fscanf(file, "%s", word)!= EOF) {
        if (wordCount >= MAX_WORDS) {
            printf("Dictionary is full\n");
            break;
        }
        strcpy(currentWord->word, word);
        currentWord->frequency = 1;
        currentWord++;
        wordCount++;
    }

    fclose(file);
}

// function to check spelling of a word
int checkSpelling(char *word, Word *dictionary) {
    Word *closestMatch = NULL;
    int closestDistance = WORD_LENGTH;

    // find closest match in dictionary
    qsort(dictionary, MAX_WORDS, sizeof(Word), compareWords);
    Word *currentWord = dictionary;
    while (currentWord < dictionary + MAX_WORDS) {
        int distance = 0;
        while (word[distance] == currentWord->word[distance] && distance < WORD_LENGTH) {
            distance++;
        }
        if (distance < closestDistance) {
            closestMatch = currentWord;
            closestDistance = distance;
        }
        currentWord++;
    }

    // return 0 if exact match, 1 if one letter off, 2 if two letters off
    if (closestMatch == NULL) {
        return 2;
    } else if (closestDistance == 1) {
        return 1;
    } else {
        return 0;
    }
}

// main function
int main() {
    // load dictionary from file
    Word dictionary[MAX_WORDS];
    loadDictionary("dictionary.txt", dictionary);

    // check spelling of words
    char word[WORD_LENGTH];
    while (1) {
        printf("Enter a word to check spelling: ");
        scanf("%s", word);
        int result = checkSpelling(word, dictionary);
        if (result == 0) {
            printf("Correct spelling\n");
        } else if (result == 1) {
            printf("One letter off\n");
        } else {
            printf("Two or more letters off\n");
        }
    }

    return 0;
}