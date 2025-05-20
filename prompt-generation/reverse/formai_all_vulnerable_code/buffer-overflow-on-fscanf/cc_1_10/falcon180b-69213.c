//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define NUM_DICTIONARY_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_in_dictionary;
} Word;

void load_dictionary(Word* dictionary) {
    FILE* dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        exit(1);
    }

    int num_words_loaded = 0;
    while (fscanf(dictionary_file, "%s", dictionary[num_words_loaded].word)!= EOF) {
        dictionary[num_words_loaded].is_in_dictionary = true;
        num_words_loaded++;
        if (num_words_loaded >= NUM_DICTIONARY_WORDS) {
            printf("Warning: reached maximum number of dictionary words.\n");
            break;
        }
    }

    fclose(dictionary_file);
}

void spell_check(char* text, Word* dictionary) {
    char word[MAX_WORD_LENGTH];
    strcpy(word, "");

    bool is_in_word = false;
    while (*text!= '\0') {
        if (isalpha(*text)) {
            strcat(word, tolower(*text));
            is_in_word = true;
        } else {
            is_in_word = false;
        }
        text++;
    }

    if (is_in_word && strlen(word) > 0) {
        bool is_in_dictionary = false;
        for (int i = 0; i < NUM_DICTIONARY_WORDS; i++) {
            if (strcmp(word, dictionary[i].word) == 0) {
                is_in_dictionary = true;
                break;
            }
        }

        if (!is_in_dictionary) {
            printf("Possible spelling error: %s\n", word);
        }
    }
}

int main() {
    Word dictionary[NUM_DICTIONARY_WORDS];
    load_dictionary(dictionary);

    char text[100000];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    spell_check(text, dictionary);

    return 0;
}