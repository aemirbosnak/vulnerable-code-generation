//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 100000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

int main() {
    FILE *dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return 1;
    }

    Word dictionary[MAX_DICTIONARY_SIZE];
    int dictionary_size = 0;

    char word[MAX_WORD_LENGTH];
    while (fscanf(dictionary_file, "%s", word)!= EOF) {
        if (dictionary_size == MAX_DICTIONARY_SIZE) {
            printf("Error: Dictionary is full.\n");
            return 2;
        }
        strcpy(dictionary[dictionary_size].word, word);
        dictionary[dictionary_size].is_correct = true;
        dictionary_size++;
    }

    fclose(dictionary_file);

    char text[MAX_WORD_LENGTH];
    printf("Enter text to spell check: ");
    fgets(text, MAX_WORD_LENGTH, stdin);

    int i = 0;
    while (i < strlen(text)) {
        char word[MAX_WORD_LENGTH];
        int j = 0;
        while (i < strlen(text) && isalnum(text[i])) {
            word[j++] = tolower(text[i++]);
        }
        word[j] = '\0';

        bool is_correct = false;
        for (int k = 0; k < dictionary_size; k++) {
            if (strcmp(word, dictionary[k].word) == 0) {
                is_correct = true;
                break;
            }
        }

        if (!is_correct) {
            printf("Possible typo: %s\n", word);
        }

        i += strlen(word) - 1;
    }

    return 0;
}