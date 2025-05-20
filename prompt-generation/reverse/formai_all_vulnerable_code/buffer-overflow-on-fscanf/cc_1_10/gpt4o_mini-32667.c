//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

// Function to load dictionary words into an array
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        return -1;
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < DICTIONARY_SIZE) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int is_correct_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(dictionary[i], word) == 0) {
            return 1; // Found the word
        }
    }
    return 0; // Word not found
}

// Function to suggest similar words
void suggest_words(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    printf("Did you mean:\n");
    for (int i = 0; i < dict_size; i++) {
        if (strlen(dictionary[i]) > 2 && 
            abs(strlen(dictionary[i]) - strlen(word)) <= 2 &&
            strncmp(dictionary[i], word, strlen(word) > 2 ? 2 : 1) == 0) {
            printf(" - %s\n", dictionary[i]);
        }
    }
}

// Function to check spelling in a given text file
void check_spelling(const char *text_file, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(text_file, "r");
    if (!file) {
        perror("Could not open text file");
        return;
    }
    
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        // Remove punctuation from the word
        for (int i = 0; word[i]; i++) {
            if (ispunct(word[i])) {
                word[i] = '\0'; // Replace punctuation with null character
                break;
            }
        }

        // Check if the word is correct
        if (!is_correct_word(word, dictionary, dict_size)) {
            printf("Incorrect: %s\n", word);
            suggest_words(word, dictionary, dict_size);
        }
    }
    fclose(file);
}

int main() {
    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary("dictionary.txt", dictionary);

    if (dict_size < 0) {
        return 1; // Error loading the dictionary
    }

    char text_file[MAX_WORD_LENGTH];
    printf("Enter the path of the text file to check: ");
    scanf("%s", text_file);

    check_spelling(text_file, dictionary, dict_size);
    
    return 0;
}