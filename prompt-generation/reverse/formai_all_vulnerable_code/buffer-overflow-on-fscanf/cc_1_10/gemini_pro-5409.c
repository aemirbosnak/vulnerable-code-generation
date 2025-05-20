//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 100

// Function to read a dictionary into an array of strings
int read_dictionary(char *dictionary_file, char *words[][MAX_WORD_LENGTH]) {
    FILE *fp;
    int num_words = 0;

    fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        printf("Error opening dictionary file: %s\n", dictionary_file);
        return -1;
    }

    while (fscanf(fp, "%s", words[num_words]) != EOF) {
        num_words++;
    }

    fclose(fp);

    return num_words;
}

// Function to check if a word is in the dictionary
int is_in_dictionary(char *word, char *words[][MAX_WORD_LENGTH], int num_words) {
    int i;

    for (i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to check if a word is a valid English word
int is_valid_word(char *word) {
    int i;

    for (i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to check the spelling of a word
int check_spelling(char *word, char *dictionary_file) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int num_words;

    // Read the dictionary into an array of strings
    num_words = read_dictionary(dictionary_file, words);
    if (num_words == -1) {
        return -1;
    }

    // Check if the word is in the dictionary
    if (is_in_dictionary(word, words, num_words)) {
        return 1;
    }

    // Check if the word is a valid English word
    if (is_valid_word(word)) {
        return 0;
    }

    // The word is not in the dictionary and is not a valid English word
    return -1;
}

int main() {
    char word[MAX_WORD_LENGTH];
    int result;

    // Get the word from the user
    printf("Enter a word: ");
    scanf("%s", word);

    // Check the spelling of the word
    result = check_spelling(word, "dictionary.txt");

    // Print the result
    if (result == 1) {
        printf("The word is spelled correctly.\n");
    } else if (result == 0) {
        printf("The word is not spelled correctly, but it is a valid English word.\n");
    } else {
        printf("The word is not spelled correctly and is not a valid English word.\n");
    }

    return 0;
}