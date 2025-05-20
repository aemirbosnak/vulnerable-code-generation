//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LEN 20

// Struct to store words
typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} Word;

// Function to compare two words (case insensitive)
int compareWords(const void *a, const void *b) {
    const Word *wordA = (const Word *)a;
    const Word *wordB = (const Word *)b;

    return strcasecmp(wordA->word, wordB->word);
}

// Function to read words from file into an array of Word structs
void readWordsFromFile(FILE *file, Word words[]) {
    char word[MAX_WORD_LEN];
    int i = 0;

    while (fscanf(file, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in file.\n");
            exit(1);
        }

        strcpy(words[i].word, word);
        words[i].count = 0;
        i++;
    }
}

// Function to check spelling of a word against an array of Word structs
int checkSpelling(const char *word, Word words[]) {
    Word *match = bsearch(word, words, MAX_WORDS, sizeof(Word), compareWords);

    if (match!= NULL) {
        match->count++;
        return 1;
    } else {
        return 0;
    }
}

// Function to print misspelled words and their frequencies
void printMisspelledWords(const char *filename, Word words[]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", words[0].word)!= EOF) {
        int found = checkSpelling(words[0].word, words);

        if (!found) {
            printf("%s: %d\n", words[0].word, words[0].count);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dictionary> <text_file>\n", argv[0]);
        exit(1);
    }

    Word words[MAX_WORDS];
    readWordsFromFile(argv[1], words);
    printMisspelledWords(argv[2], words);

    return 0;
}