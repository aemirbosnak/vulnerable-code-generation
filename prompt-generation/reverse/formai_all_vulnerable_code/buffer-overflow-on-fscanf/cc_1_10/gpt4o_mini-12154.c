//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

// Function to convert a word to lowercase
void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word exists in an array
int word_exists(char *word, char word_list[][MAX_WORD_LENGTH], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, word_list[i]) == 0) {
            return 1; // Word exists in the list
        }
    }
    return 0; // Word does not exist in the list
}

// Function to load allowed words from a dictionary file
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF) {
        to_lowercase(dictionary[count]); // Store in lowercase
        count++;
        if (count >= MAX_WORDS) {
            break; // Limit the number of words to avoid overflow
        }
    }
    fclose(file);
    return count;
}

// Function to check spelling of words in a given text
void check_spelling(char *text, char dictionary[][MAX_WORD_LENGTH], int dict_count) {
    char *word = strtok(text, " \n");
    while (word) {
        char word_clean[MAX_WORD_LENGTH];
        int idx = 0;

        // Clean and prepare the word
        for (int i = 0; word[i]; i++) {
            if (isalpha(word[i])) {
                word_clean[idx++] = word[i]; // Add only alphabetic characters
            }
        }
        word_clean[idx] = '\0'; // Null terminate the cleaned word

        // Check for spelling
        if (strlen(word_clean) > 0 && !word_exists(word_clean, dictionary, dict_count)) {
            printf("Misspelled word: %s\n", word_clean);
        }
        word = strtok(NULL, " \n"); // Get the next word
    }
}

int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments is provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    char *text_buffer = NULL;
    long text_length;

    // Load the dictionary
    int dict_count = load_dictionary(argv[1], dictionary);
    printf("Loaded %d words from the dictionary.\n", dict_count);

    // Read the text file into a buffer
    FILE *text_file = fopen(argv[2], "r");
    if (!text_file) {
        perror("Could not open text file");
        return EXIT_FAILURE;
    }
    
    fseek(text_file, 0, SEEK_END);
    text_length = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);
    
    text_buffer = (char *)malloc(text_length + 1);
    if (!text_buffer) {
        perror("Memory allocation failed");
        fclose(text_file);
        return EXIT_FAILURE;
    }
    
    fread(text_buffer, 1, text_length, text_file);
    text_buffer[text_length] = '\0'; // Null terminate the buffer
    fclose(text_file);

    // Check spelling in the text
    check_spelling(text_buffer, dictionary, dict_count);

    free(text_buffer);
    return EXIT_SUCCESS;
}