//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50 // maximum length of a word
#define MAX_DICTIONARY_WORDS 50000 // maximum number of words in dictionary

char *dictionary[MAX_DICTIONARY_WORDS]; // dictionary of words

// function to load dictionary from file
int load_dictionary(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 0;
    }
    char word[MAX_WORD_LENGTH];
    int i = 0;
    while (fgets(word, MAX_WORD_LENGTH, fp) != NULL && i < MAX_DICTIONARY_WORDS) {
        word[strcspn(word, "\n")] = 0; // remove newline character
        dictionary[i] = strdup(word); // add word to dictionary
        i++;
    }
    fclose(fp);
    return i; // return number of words added to dictionary
}

// function to check if a word is spelled correctly
int check_spelling(const char *word, int size) {
    // make word lowercase
    char lower_word[MAX_WORD_LENGTH];
    for (int i = 0; i < size; i++) {
        lower_word[i] = tolower(word[i]);
    }
    lower_word[size] = '\0';
    
    // check if word is in dictionary
    for (int i = 0; i < MAX_DICTIONARY_WORDS; i++) {
        if (dictionary[i] == NULL) {
            break;
        }
        if (strcmp(lower_word, dictionary[i]) == 0) {
            return 1; // word found in dictionary
        }
    }
    return 0; // word not found in dictionary
}

int main() {
    const char *dict_file = "dictionary.txt";
    int num_words = load_dictionary(dict_file);
    printf("Dictionary loaded with %d words.\n", num_words);

    char input[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", input);
    int size = strlen(input);
    
    if (check_spelling(input, size)) {
        printf("%s is spelled correctly.\n", input);
    } else {
        printf("%s is not spelled correctly.\n", input);
    }

    // free memory allocated to dictionary
    for (int i = 0; i < MAX_DICTIONARY_WORDS; i++) {
        if (dictionary[i] == NULL) {
            break;
        }
        free(dictionary[i]);
    }
    return 0;
}