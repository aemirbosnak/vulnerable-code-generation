//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define HASH_SIZE 1000

typedef struct Node {
    char *word;
    struct Node *next;
} Node;

Node *dictionary[HASH_SIZE];

// Hash function to convert a word into an index
unsigned int hash(const char *word) {
    unsigned int hashValue = 0;
    while (*word) {
        hashValue = (hashValue << 5) + *word++;
    }
    return hashValue % HASH_SIZE;
}

// Load dictionary from a file
void loadDictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", buffer) != EOF) {
        unsigned int index = hash(buffer);
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->word = strdup(buffer);
        newNode->next = dictionary[index];
        dictionary[index] = newNode;
    }
    fclose(file);
}

// Check if a word is in the dictionary
int checkWord(const char *word) {
    unsigned int index = hash(word);
    Node *current = dictionary[index];
    while (current) {
        if (strcmp(current->word, word) == 0) {
            return 1; // Word found
        }
        current = current->next;
    }
    return 0; // Word not found
}

// Function to clean and split the text into words
void processText(char *text) {
    char *word = strtok(text, " \n\t,.!?;:()[]{}\"'");
    while (word) {
        // Convert to lower case
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        if (!checkWord(word)) {
            printf("Misspelled word: %s\n", word);
        }
        word = strtok(NULL, " \n\t,.!?;:()[]{}\"'");
    }
}

// Free the dictionary memory
void freeDictionary() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = dictionary[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary file> <text file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    loadDictionary(argv[1]);
    
    FILE *textFile = fopen(argv[2], "r");
    if (!textFile) {
        fprintf(stderr, "Could not open text file: %s\n", argv[2]);
        freeDictionary();
        return EXIT_FAILURE;
    }

    char *text = NULL;
    size_t len = 0;

    while (getline(&text, &len, textFile) != -1) {
        processText(text);
    }

    free(text);
    fclose(textFile);
    freeDictionary();

    return EXIT_SUCCESS;
}