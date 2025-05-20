//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_valid;
} DictionaryEntry;

void add_word_to_dictionary(DictionaryEntry* dictionary, const char* word) {
    int i;
    for (i = 0; i < MAX_DICTIONARY_SIZE; i++) {
        if (dictionary[i].is_valid == false) {
            strcpy(dictionary[i].word, word);
            dictionary[i].is_valid = true;
            return;
        }
    }
}

bool is_valid_word(const char* word, DictionaryEntry* dictionary) {
    int i;
    for (i = 0; i < MAX_DICTIONARY_SIZE; i++) {
        if (dictionary[i].is_valid && strcmp(dictionary[i].word, word) == 0) {
            return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    FILE* input_file;
    char word[MAX_WORD_LENGTH];
    DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
    bool first_word = true;
    int num_words = 0;
    int num_invalid_words = 0;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    while (fscanf(input_file, "%s", word)!= EOF) {
        num_words++;
        if (is_valid_word(word, dictionary)) {
            continue;
        }
        if (first_word) {
            printf("Error: invalid word '%s' on line 1.\n", word);
        } else {
            printf("Error: invalid word '%s' on line %d.\n", word, num_words);
        }
        num_invalid_words++;
        add_word_to_dictionary(dictionary, word);
    }

    fclose(input_file);

    if (num_invalid_words == 0) {
        printf("No spelling errors found.\n");
    } else {
        printf("%d spelling errors found.\n", num_invalid_words);
    }

    return 0;
}