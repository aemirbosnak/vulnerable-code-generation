//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORD 10000

char dictionary[MAX_NUM_WORD][MAX_WORD_LENGTH];
int dict_size = 0;

void add_word(char* word) {
    // Check if the word is already in the dictionary
    for(int i=0; i<dict_size; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            return; // The word is already in the dictionary, do nothing
        }
    }

    // If the word is not in the dictionary, add it
    strcpy(dictionary[dict_size], word);
    dict_size++;
}

int check_word(char* word) {
    // Check if the word is in the dictionary
    for(int i=0; i<dict_size; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            return 1; // The word is in the dictionary, return true
        }
    }

    // If the word is not in the dictionary, return false
    return 0;
}

int main() {
    printf("Welcome to the Spell Checker Program!\n");

    // Open the dictionary file
    FILE* dict_file = fopen("dictionary.txt", "r");
    if(dict_file == NULL) {
        printf("Error opening dictionary file!\n");
        return 1;
    }

    // Load words from dictionary into memory
    char word[MAX_WORD_LENGTH];
    while(fscanf(dict_file, "%s", word) != EOF) {
        add_word(word);
    }

    // Close the dictionary file
    fclose(dict_file);

    // Open the text file to check
    FILE* text_file = fopen("text.txt", "r");
    if(text_file == NULL) {
        printf("Error opening text file!\n");
        return 1;
    }

    // Check each word in the text file
    int line_num = 1; // Keep track of the line number for error reporting
    int word_num = 1; // Keep track of the word number for error reporting
    while(fscanf(text_file, "%s", word) != EOF) {
        // Check if the word is spelled correctly
        if(!check_word(word)) {
            printf("Error: Line %d, Word %d: %s is misspelled\n", line_num, word_num, word);
        }

        // If the word is a new line, increment the line number and reset the word number
        if(strcmp(word, "\n") == 0) {
            line_num++;
            word_num = 1;
        }
        // Otherwise, increment the word number
        else {
            word_num++;
        }
    }

    // Close the text file
    fclose(text_file);

    printf("Spell checking complete!\n");

    return 0;
}