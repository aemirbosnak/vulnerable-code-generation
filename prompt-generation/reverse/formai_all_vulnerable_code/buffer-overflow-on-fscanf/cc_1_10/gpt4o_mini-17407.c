//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_UNIQUE_WORDS 10000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

void to_lower_case(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_valid_character(char c) {
    return isalnum(c) || c == '\''; // Allow alphanumeric characters and apostrophes
}

int add_word(WordFreq *wordList, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return 0; // Word already exists, no need to add
        }
    }
    
    // If the word is not found, add it to the list
    strcpy(wordList[*wordCount].word, word);
    wordList[*wordCount].count = 1;
    (*wordCount)++;
    return 1; // New word added
}

void print_word_frequencies(WordFreq *wordList, int wordCount) {
    printf("Word Frequencies:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

int main() {
    FILE *file;
    WordFreq wordList[MAX_UNIQUE_WORDS];
    int wordCount = 0;

    // Open the input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open the file. Please make sure 'input.txt' exists.\n");
        return 1; // Exit with an error code
    }
    
    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) == 1) {
        // Clean up the word by removing punctuation and converting to lower case
        char cleanWord[MAX_WORD_LENGTH];
        int j = 0;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (is_valid_character(buffer[i])) {
                cleanWord[j++] = buffer[i];
            }
        }
        cleanWord[j] = '\0'; // Null-terminate the cleaned-up word
        to_lower_case(cleanWord);
        
        if (strlen(cleanWord) > 0) {
            // Add the word to the frequency list
            add_word(wordList, &wordCount, cleanWord);
        }
    }

    // Close the file
    fclose(file);

    // Print out the frequencies
    print_word_frequencies(wordList, wordCount);

    return 0; // Successful completion
}