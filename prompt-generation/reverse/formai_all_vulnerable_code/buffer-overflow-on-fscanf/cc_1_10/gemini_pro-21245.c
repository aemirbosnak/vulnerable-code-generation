//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

// Function to load the dictionary into an array of strings
int load_dictionary(char *dictionary_file, char *words[]) {
    FILE *fp = fopen(dictionary_file, "r");
    if (fp == NULL) {
        perror("Error opening dictionary file");
        return -1;
    }

    int num_words = 0;
    while (fscanf(fp, "%s", words[num_words]) != EOF) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            break;
        }
    }

    fclose(fp);

    return num_words;
}

// Function to check if a word is in the dictionary
bool is_word_in_dictionary(char *word, char *words[], int num_words) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            return true;
        }
    }

    return false;
}

// Function to spell check a file
int spell_check_file(char *filename, char *words[], int num_words) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    int num_misspelled_words = 0;
    char word[MAX_WORD_LENGTH + 1];
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert the word to lowercase and remove punctuation
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
            if (!isalpha(word[i])) {
                word[i] = '\0';
                break;
            }
        }

        // Check if the word is in the dictionary
        if (!is_word_in_dictionary(word, words, num_words)) {
            printf("%s is misspelled\n", word);
            num_misspelled_words++;
        }
    }

    fclose(fp);

    return num_misspelled_words;
}

int main()
{
    // Load the dictionary into an array of strings
    char *words[MAX_WORDS];
    int num_words = load_dictionary("dictionary.txt", words);
    if (num_words == -1) {
        return EXIT_FAILURE;
    }

    // Spell check a file
    int num_misspelled_words = spell_check_file("input.txt", words, num_words);
    if (num_misspelled_words == -1) {
        return EXIT_FAILURE;
    }

    printf("Misspelled words: %d\n", num_misspelled_words);

    return EXIT_SUCCESS;
}