//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;

    return strcmp(wordA->word, wordB->word);
}

void loadWords(FILE *file, Word *words) {
    char line[MAX_WORD_LENGTH];
    char *word;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " \t\r\n");

        while (word!= NULL) {
            strcpy(words->word, word);
            words->count++;

            if (words - words + 1 >= MAX_WORDS) {
                printf("Error: Too many words!\n");
                exit(1);
            }

            words++;

            word = strtok(NULL, " \t\r\n");
        }
    }
}

void checkSpelling(FILE *file, Word *words) {
    char line[MAX_WORD_LENGTH];
    char *word;

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        word = strtok(line, " \t\r\n");

        while (word!= NULL) {
            Word *foundWord = bsearch(word, words, MAX_WORDS, sizeof(Word), compareWords);

            if (foundWord == NULL) {
                printf("Misspelled word: %s\n", word);
            }

            word = strtok(NULL, " \t\r\n");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s dictionary.txt file.txt\n", argv[0]);
        return 1;
    }

    FILE *dictionary = fopen(argv[1], "r");
    FILE *file = fopen(argv[2], "r");

    if (dictionary == NULL || file == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    Word words[MAX_WORDS];

    loadWords(dictionary, words);

    fclose(dictionary);

    checkSpelling(file, words);

    fclose(file);

    return 0;
}