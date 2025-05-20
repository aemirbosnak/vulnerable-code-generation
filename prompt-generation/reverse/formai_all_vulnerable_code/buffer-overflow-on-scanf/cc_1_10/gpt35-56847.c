//FormAI DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50

void checkWord(char *word, FILE *dictionary);
void convertToLower(char *word);
void removePunctuations(char *word);

int main() {
    FILE *dictionary;
    char filename[] = "dictionary.txt";
    char word[MAX_WORD_LEN];

    dictionary = fopen(filename, "r");

    if (dictionary == NULL) {
        printf("Could not open dictionary file.\n");
        exit(1);
    }

    printf("Enter a word to check (Type 'quit' to exit): ");

    while (1) {
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            break;
        }

        convertToLower(word);
        removePunctuations(word);
        checkWord(word, dictionary);
    }

    fclose(dictionary);

    return 0;
}

void checkWord(char *word, FILE *dictionary) {
    char dictWord[MAX_WORD_LEN];

    fseek(dictionary, 0, SEEK_SET);

    while (fgets(dictWord, MAX_WORD_LEN, dictionary) != NULL) {
        convertToLower(dictWord);
        removePunctuations(dictWord);

        if (strcmp(word, dictWord) == 0) {
            printf("The word \"%s\" is spelled correctly.\n", word);
            return;
        }
    }

    printf("The word \"%s\" is spelled incorrectly.\n", word);
}

void convertToLower(char *word) {
    int i;

    for (i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

void removePunctuations(char *word) {
    int i = 0;
    int j = 0;

    while (word[i]) {
        if (ispunct(word[i])) {
            i++;
            continue;
        }

        word[j++] = word[i++];
    }

    word[j] = '\0';
}