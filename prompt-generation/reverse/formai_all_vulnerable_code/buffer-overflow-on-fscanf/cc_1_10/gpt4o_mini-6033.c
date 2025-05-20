//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000

// A structure to hold English words and their Cat Language equivalents
typedef struct {
    char english[MAX_WORD_LENGTH];
    char catLanguage[MAX_WORD_LENGTH];
} Dictionary;

// Function prototypes
void loadDictionary(Dictionary *dict, int *size);
void translateLine(Dictionary *dict, int size, const char *line);
void toCatLanguage(char *word, Dictionary *dict, int size);
int isWord(char ch);

int main() {
    Dictionary dict[100];
    int size = 0;

    // Load the dictionary from a file
    loadDictionary(dict, &size);

    // Read input from the user
    char line[MAX_LINE_LENGTH];
    printf("Enter a line to translate into Cat Language (type 'exit' to quit):\n");
    
    while (1) {
        // Get a line of input
        fgets(line, sizeof(line), stdin);
        
        // Check for exit command
        if (strncmp(line, "exit", 4) == 0) {
            break;
        }

        // Translate the line to Cat Language
        translateLine(dict, size, line);
    }

    return 0;
}

// Function to load the dictionary from a file
void loadDictionary(Dictionary *dict, int *size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dict[*size].english, dict[*size].catLanguage) == 2) {
        (*size)++;
    }
    
    fclose(file);
}

// Function to translate a line of text
void translateLine(Dictionary *dict, int size, const char *line) {
    char word[MAX_WORD_LENGTH];
    int index = 0;

    // Go through each character in the line
    for (int i = 0; line[i] != '\0'; i++) {
        if (isWord(line[i])) {
            // Build the word from consecutive letters
            word[index++] = line[i];
        } else {
            // End of a word
            if (index > 0) {
                word[index] = '\0';
                toCatLanguage(word, dict, size);
                index = 0;
            }
            // Print non-word characters (punctuation, spaces, etc.)
            putchar(line[i]);
        }
    }

    // Translate last word if it exists
    if (index > 0) {
        word[index] = '\0';
        toCatLanguage(word, dict, size);
    }
    
    printf("\n");
}

// Function to translate a single word into Cat Language
void toCatLanguage(char *word, Dictionary *dict, int size) {
    for (int i = 0; i < size; i++) {
        // Compare words in the dictionary
        if (strcasecmp(word, dict[i].english) == 0) {
            printf("%s ", dict[i].catLanguage);
            return;
        }
    }
    // If the word is not in the dictionary, print it as is
    printf("%s ", word);
}

// Function to determine if a character is part of a word (a-z, A-Z)
int isWord(char ch) {
    return isalpha(ch);
}