//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

typedef struct {
    char english[MAX_LENGTH];
    char alien[MAX_LENGTH];
} DictionaryEntry;

DictionaryEntry dictionary[MAX_WORDS];
int wordCount = 0;

// Function to load the dictionary from a file
void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }
    
    while (fscanf(file, "%s %s", dictionary[wordCount].english, dictionary[wordCount].alien) != EOF) {
        wordCount++;
        if (wordCount >= MAX_WORDS) break;  // Prevent overflow
    }
    
    fclose(file);
}

// Function to translate a single word
char* translateWord(const char* word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(dictionary[i].english, word) == 0) {
            return dictionary[i].alien;
        }
    }
    return "UNKNOWN";  // Return "UNKNOWN" if the word isn't in the dictionary
}

// Function to translate a sentence
void translateSentence(const char* sentence) {
    char temp[MAX_LENGTH];
    strcpy(temp, sentence);
    
    char* token = strtok(temp, " ");
    while (token) {
        printf("%s ", translateWord(token));
        token = strtok(NULL, " ");
    }
    printf("\n");
}

// Display available commands
void displayInstructions() {
    printf("Alien Language Translator\n");
    printf("Enter a sentence to translate, or type 'exit' to quit.\n");
}

// Main function
int main() {
    loadDictionary("dictionary.txt");

    char input[MAX_LENGTH];
    displayInstructions();

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from fgets
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        }

        translateSentence(input);
    }

    return 0;
}