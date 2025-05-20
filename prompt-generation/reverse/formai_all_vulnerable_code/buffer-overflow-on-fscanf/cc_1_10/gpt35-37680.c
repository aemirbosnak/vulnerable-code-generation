//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 50
#define MAX_DICT_WORDS 1000

int load_dictionary(char* filepath, char dictionary[MAX_DICT_WORDS][MAX_WORD_SIZE]) {

    FILE* file = fopen(filepath, "r");
    if (!file) {
        perror("Error opening dictionary file!");
        return 0;
    }

    int num_words = 0;
    char word[MAX_WORD_SIZE];
    while(fscanf(file, "%s", word) == 1 && num_words < MAX_DICT_WORDS) {
        strcpy(dictionary[num_words++], word);
    }

    fclose(file);

    return num_words;
}

void to_lowercase(char* string) {
    int i = 0;
    while (string[i]) {
        string[i] = tolower(string[i]);
        i++;
    }
}

int spell_check(char dictionary[MAX_DICT_WORDS][MAX_WORD_SIZE], int num_words, char* word) {

    // Convert the word to lowercase
    to_lowercase(word);

    // Check if the word is in the dictionary
    for (int i = 0; i < num_words; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1;
        }
    }

    // Word not found in dictionary
    return 0;
}

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: spellcheck <dictionary_filepath> <text_filepath>\n");
        return 0;
    }

    char dictionary[MAX_DICT_WORDS][MAX_WORD_SIZE];
    int num_words = load_dictionary(argv[1], dictionary);
    if (!num_words) {
        return 0;
    }

    FILE* file = fopen(argv[2], "r");
    if (!file) {
        perror("Error opening text file!");
        return 0;
    }

    char word[MAX_WORD_SIZE];
    while(fscanf(file, "%s", word) == 1) {
        if (!spell_check(dictionary, num_words, word)) {
            printf("Misspelled word: %s\n", word);
        }
    }

    fclose(file);

    return 0;
}