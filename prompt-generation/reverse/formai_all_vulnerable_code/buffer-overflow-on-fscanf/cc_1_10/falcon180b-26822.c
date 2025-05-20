//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 20
#define DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[], int size) {
    FILE *file = fopen("dictionary.txt", "r");
    int i = 0;

    if (file == NULL) {
        printf("Error loading dictionary\n");
        exit(1);
    }

    while (fscanf(file, "%s", dictionary[i].word)!= EOF) {
        dictionary[i].is_correct = true;
        i++;
    }

    fclose(file);
}

bool is_word_in_dictionary(Word dictionary[], int size, char *word) {
    int i = 0;

    while (i < size) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
        i++;
    }

    return false;
}

void check_spelling(char *text, Word dictionary[], int size) {
    char word[MAX_WORD_LENGTH];
    int i, j;

    i = 0;
    while (text[i]!= '\0') {
        if (isalpha(text[i])) {
            j = 0;
            while (isalpha(text[i]) && j < MAX_WORD_LENGTH) {
                word[j] = tolower(text[i]);
                i++;
                j++;
            }
            word[j] = '\0';

            if (!is_word_in_dictionary(dictionary, size, word)) {
                printf("Possible spelling error: %s\n", word);
            }
        } else {
            i++;
        }
    }
}

int main() {
    Word dictionary[DICTIONARY_SIZE];
    char text[1000];

    printf("Enter text to check spelling: ");
    fgets(text, sizeof(text), stdin);

    load_dictionary(dictionary, DICTIONARY_SIZE);
    check_spelling(text, dictionary, DICTIONARY_SIZE);

    return 0;
}