//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50

typedef struct Word {
    char word[WORD_LENGTH];
    struct Word *next;
} Word;

Word *dictionary = NULL;
Word *current = NULL;

void loadDictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char word[WORD_LENGTH];
    Word *newWord;

    if (fp == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        newWord = (Word *)malloc(sizeof(Word));
        strcpy(newWord->word, word);
        newWord->next = dictionary;
        dictionary = newWord;
    }

    fclose(fp);
}

int isPrefix(const char *prefix, const char *word) {
    int i;

    for (i = 0; prefix[i] != '\0' && word[i] != '\0'; i++) {
        if (tolower(prefix[i]) != tolower(word[i])) {
            return 0;
        }
    }

    return prefix[i] == '\0' || word[i] == '\0';
}

int checkSpelling(const char *word) {
    int found = 0;

    current = dictionary;

    while (current != NULL && strlen(current->word) < WORD_LENGTH) {
        if (isPrefix(current->word, word)) {
            found = 1;
            break;
        }
        current = current->next;
    }

    return found;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <word>\n", argv[0]);
        return 1;
    }

    loadDictionary("dictionary.txt");

    if (!checkSpelling(argv[1])) {
        printf("Error: '%s' is not a valid word.\n", argv[1]);
        return 1;
    }

    printf("Congratulations! '%s' is a valid word.\n", argv[1]);

    return 0;
}