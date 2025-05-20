//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    struct Node *next;
} Node;

Node *dictionary = NULL;

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to create a new node
Node *createNode(const char *word) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode) {
        strcpy(newNode->word, word);
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add a word to the dictionary
void addWord(const char *word) {
    Node *newNode = createNode(word);
    if (dictionary == NULL) {
        dictionary = newNode;
    } else {
        Node *current = dictionary;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to check if a word exists in the dictionary
int checkWord(const char *word) {
    Node *current = dictionary;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to load words from a file into the dictionary
void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open dictionary file.\n");
        return;
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) == 1) {
        toLowerCase(word);
        addWord(word);
    }
    fclose(file);
}

// Function to check and suggest corrections for a misspelled word
void suggestCorrections(const char *word) {
    printf("Did you mean:\n");
    for (int i = 0; i < strlen(word); i++) {
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, word);
        
        for (char c = 'a'; c <= 'z'; c++) {
            temp[i] = c;
            if (checkWord(temp)) {
                printf("- %s\n", temp);
            }
        }
    }
}

// Function to perform spell checking on a given text
void spellCheckText(const char *text) {
    char word[MAX_WORD_LENGTH];
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            word[j++] = text[i];
        } else {
            if (j > 0) {
                word[j] = '\0';
                if (!checkWord(word)) {
                    printf("Misspelled: %s\n", word);
                    suggestCorrections(word);
                }
                j = 0;
            }
        }
    }

    // Check for the last word if exists
    if (j > 0) {
        word[j] = '\0';
        if (!checkWord(word)) {
            printf("Misspelled: %s\n", word);
            suggestCorrections(word);
        }
    }
}

// Main function
int main() {
    loadDictionary("dictionary.txt");

    char text[2048];
    printf("Enter text to spell check:\n");
    fgets(text, sizeof(text), stdin);

    spellCheckText(text);

    // Clean up the dictionary linked list
    Node *current = dictionary;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}