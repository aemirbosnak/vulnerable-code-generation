//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Function Prototypes
void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dict_size);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void spell_check(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void to_lower_case(char *word);

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = 0;

    load_dictionary("dictionary.txt", dictionary, &dict_size);
    
    printf("Oh, fair youth, dost thou desire a spell checker?\n");
    printf("Let us begin our journey through thine text!\n\n");

    spell_check("text.txt", dictionary, dict_size);
    
    printf("\nThus ends our quest for the righteous spelling.\n");
    return 0;
}

void load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int *dict_size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Alas! The dictionary could not be found.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", dictionary[*dict_size]) != EOF) {
        to_lower_case(dictionary[*dict_size]);
        (*dict_size)++;
    }

    fclose(file);
    printf("The grand lexicon of words hath been loaded with care.\n");
}

void to_lower_case(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

void spell_check(const char *text_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(text_filename, "r");
    if (!file) {
        fprintf(stderr, "O, woe! The text could not be found.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    printf("As we read, we shall mark the words of error:\n");
    
    while (fscanf(file, "%s", word) != EOF) {
        to_lower_case(word);
        if (!is_word_in_dictionary(word, dictionary, dict_size)) {
            printf("Alas, the word '%s' doth not grace our lexicon!\n", word);
        }
    }

    fclose(file);
    printf("The reading hath been completed, our journey is fulfilled.\n");
}