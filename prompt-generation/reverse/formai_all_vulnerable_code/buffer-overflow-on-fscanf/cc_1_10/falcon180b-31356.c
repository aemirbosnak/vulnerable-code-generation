//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICTIONARY_SIZE];
int num_dictionary_entries = 0;

void add_word_to_dictionary(char* word) {
    if (num_dictionary_entries >= MAX_DICTIONARY_SIZE) {
        printf("Error: Dictionary is full.\n");
        return;
    }
    strcpy(dictionary[num_dictionary_entries].word, word);
    dictionary[num_dictionary_entries].is_correct = true;
    num_dictionary_entries++;
}

void load_dictionary_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        return;
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        add_word_to_dictionary(word);
    }
    fclose(file);
}

bool is_word_correct(char* word) {
    for (int i = 0; i < num_dictionary_entries; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return dictionary[i].is_correct;
        }
    }
    return false;
}

void check_spelling(char* text) {
    char* word = strtok(text, " \t\r\n\f\v,.!?;:");
    while (word!= NULL) {
        if (!is_word_correct(word)) {
            printf("Possible spelling error: %s\n", word);
        }
        word = strtok(NULL, " \t\r\n\f\v,.!?;:");
    }
}

int main() {
    load_dictionary_from_file("dictionary.txt");
    char* text = "This is a sample text to check the spelling of words. It contains some misspelled words like 'teh' and'recieve'.";
    check_spelling(text);
    return 0;
}