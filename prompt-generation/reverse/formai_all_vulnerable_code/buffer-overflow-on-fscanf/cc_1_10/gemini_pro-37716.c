//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum word length
#define MAX_WORD_LENGTH 100

// Create a hash table to store the dictionary
typedef struct node {
    char *word;
    struct node *next;
} node;

// Create the hash table
node *hashTable[26];

// Initialize the hash table
void initHashTable() {
    for (int i = 0; i < 26; i++) {
        hashTable[i] = NULL;
    }
}

// Insert a word into the hash table
void insertWord(char *word) {
    // Get the first letter of the word
    char firstLetter = word[0];

    // Get the index of the first letter in the hash table
    int index = firstLetter - 'a';

    // Create a new node for the word
    node *new_node = (node *)malloc(sizeof(node));
    new_node->word = word;
    new_node->next = NULL;

    // Insert the new node into the hash table
    if (hashTable[index] == NULL) {
        hashTable[index] = new_node;
    } else {
        new_node->next = hashTable[index];
        hashTable[index] = new_node;
    }
}

// Check if a word is in the dictionary
int isWordInDictionary(char *word) {
    // Get the first letter of the word
    char firstLetter = word[0];

    // Get the index of the first letter in the hash table
    int index = firstLetter - 'a';

    // Search for the word in the hash table
    node *current_node = hashTable[index];
    while (current_node != NULL) {
        if (strcmp(current_node->word, word) == 0) {
            return 1;
        }
        current_node = current_node->next;
    }

    // The word was not found in the hash table
    return 0;
}

// Function to check spelling of a word
int checkSpelling(char *word) {
    // Check if the word is in the dictionary
    if (isWordInDictionary(word)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to load the dictionary into the hash table
void loadDictionary() {
    // Open the dictionary file
    FILE *fp = fopen("dictionary.txt", "r");

    // Read each word from the dictionary file
    char word[MAX_WORD_LENGTH];
    while (fscanf(fp, "%s", word) != EOF) {
        // Insert the word into the hash table
        insertWord(word);
    }

    // Close the dictionary file
    fclose(fp);
}

// Function to get a word from the user
void getWordFromUser(char *word) {
    printf("Enter a word: ");
    scanf("%s", word);
}

// Function to print the results of the spell check
void printResults(int isCorrect) {
    if (isCorrect) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }
}

// Main function
int main() {
    // Initialize the hash table
    initHashTable();

    // Load the dictionary into the hash table
    loadDictionary();

    // Get a word from the user
    char word[MAX_WORD_LENGTH];
    getWordFromUser(word);

    // Check the spelling of the word
    int isCorrect = checkSpelling(word);

    // Print the results of the spell check
    printResults(isCorrect);

    return 0;
}