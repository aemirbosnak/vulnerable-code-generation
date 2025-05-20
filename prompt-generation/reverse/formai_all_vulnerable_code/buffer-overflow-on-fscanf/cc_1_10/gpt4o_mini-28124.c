//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICTIONARY_SIZE 1000
#define MAX_TEXT_SIZE 10000

// A simple function to clean the text
void clean_word(char *word) {
    char *p = word;
    while (*p) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            p++;
        } else {
            *p = 0;
            break;
        }
    }
}

// A function to check if the word exists in the dictionary
bool check_word_in_dictionary(const char *word, const char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

// A function to load the dictionary from a file
int load_dictionary(const char *filename, char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file.\n");
        return 0;
    }
    
    int count = 0;
    while (count < MAX_DICTIONARY_SIZE && fscanf(file, "%s", dictionary[count]) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

// A function to perform the spell check on the text
void spell_check(const char *text, const char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH], int dict_size) {
    char word[MAX_WORD_LENGTH];
    int text_length = strlen(text);
    int j = 0;
    
    printf("** Spell Checking Result **\n");
    
    for (int i = 0; i < text_length; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            word[j++] = text[i];
        } else {
            if (j > 0) { // End of a word
                word[j] = '\0'; // Null terminate the word
                clean_word(word); // Clean the word
                if (!check_word_in_dictionary(word, dictionary, dict_size)) {
                    printf("Misspelled word: %s\n", word);
                }
                j = 0; // Reset for the next word
            }
        }
    }
    
    // Check the last word if there's no punctuation at the end
    if (j > 0) {
        word[j] = '\0';
        clean_word(word);
        if (!check_word_in_dictionary(word, dictionary, dict_size)) {
            printf("Misspelled word: %s\n", word);
        }
    }
}

// Main function to run the spell checker
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dictionary_size = load_dictionary(argv[1], dictionary);
    
    if (dictionary_size == 0) {
        fprintf(stderr, "No words loaded from dictionary.\n");
        return EXIT_FAILURE;
    }
    
    FILE *text_file = fopen(argv[2], "r");
    if (!text_file) {
        fprintf(stderr, "Could not open text file.\n");
        return EXIT_FAILURE;
    }
    
    char text[MAX_TEXT_SIZE];
    fread(text, sizeof(char), MAX_TEXT_SIZE, text_file);
    fclose(text_file);

    spell_check(text, dictionary, dictionary_size);
    
    return EXIT_SUCCESS;
}