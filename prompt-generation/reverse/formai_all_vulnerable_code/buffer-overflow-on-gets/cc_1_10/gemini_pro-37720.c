//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
// Wherefore art thou, spam? A plague on both thy emails!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A list of forbidden words that define a message as spam
const char *forbiddenWords[] = {
    "Viagra",
    "Casino",
    "Free",
    "Lottery",
    "Winner",
    "Urgent",
    "Act now"
};

// A hash table to store the forbidden words for faster lookup
struct HashTable {
    char **words;
    int size;
};

// Create a hash table of forbidden words
struct HashTable *createHashTable(char **words, int size) {
    struct HashTable *table = malloc(sizeof(struct HashTable));
    table->words = words;
    table->size = size;
    return table;
}

// Lookup a word in the hash table
int lookupWord(struct HashTable *table, char *word) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Check if an email message is spam
int isSpam(char *message) {
    // Tokenize the message into words
    char *words[100];
    char *token = strtok(message, " ");
    int i = 0;
    while (token != NULL) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }

    // Check if any of the words in the message are forbidden
    for (int j = 0; j < i; j++) {
        if (lookupWord(createHashTable(forbiddenWords, sizeof(forbiddenWords) / sizeof(char *)), words[j])) {
            return 1;
        }
    }

    // The message is not spam
    return 0;
}

// Get an email message from the user
char *getMessage() {
    char *message = malloc(1000);
    printf("Enter an email message: ");
    gets(message);
    return message;
}

// Main function
int main() {
    // Get an email message from the user
    char *message = getMessage();

    // Check if the message is spam
    if (isSpam(message)) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    // Free the allocated memory
    free(message);
    return 0;
}