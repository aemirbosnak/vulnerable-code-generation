//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_FILE "dictionary.txt"

typedef struct word {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void load_dictionary(Word dictionary[], int *size) {
    FILE *file = fopen(DICTIONARY_FILE, "r");
    if (file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int word_count = 0;
    while (fscanf(file, "%s", dictionary[word_count].word)!= EOF) {
        dictionary[word_count].is_correct = true;
        word_count++;
    }

    *size = word_count;
    fclose(file);
}

bool is_word_correct(Word dictionary[], int size, char *word) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

void check_spelling(char *text, int size, Word dictionary[], int dict_size) {
    int i, j;
    char word[MAX_WORD_LENGTH];
    bool start_of_word = true;

    for (i = 0; i < size; i++) {
        if (isalpha(text[i])) {
            word[0] = tolower(text[i]);
            start_of_word = true;
        } else if (start_of_word) {
            word[0] = '\0';
            if (!is_word_correct(dictionary, dict_size, word)) {
                printf("Possible spelling error: %s\n", word);
            }
            start_of_word = false;
        }
    }

    if (start_of_word) {
        word[0] = tolower(text[size - 1]);
        word[1] = '\0';
        if (!is_word_correct(dictionary, dict_size, word)) {
            printf("Possible spelling error: %s\n", word);
        }
    }
}

int main() {
    Word dictionary[1000];
    int dict_size = 0;

    load_dictionary(dictionary, &dict_size);

    char text[1000];
    printf("Enter text to check spelling:\n");
    fgets(text, sizeof(text), stdin);

    check_spelling(text, strlen(text), dictionary, dict_size);

    return 0;
}