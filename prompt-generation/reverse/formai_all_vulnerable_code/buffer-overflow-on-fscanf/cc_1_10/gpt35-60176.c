//FormAI DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_SIZE 1000 // Maximum word size

char dictionary[MAX_WORD_SIZE][MAX_WORD_SIZE]; // Dictionary to store words
int dictCount = 0; // Count of words in dictionary

void readDictionary() {
    FILE *fp = fopen("dictionary.txt", "r"); // Opening dictionary file
    if(!fp) { // If file does not exist
        printf("Error: Dictionary file not found!");
        exit(1); // Exit program
    }

    char word[MAX_WORD_SIZE];
    while(fscanf(fp, "%s", word) != EOF) { // Reading all words from dictionary file
        strcpy(dictionary[dictCount++], word); // Copying word to dictionary and incrementing count
    }

    fclose(fp); // Closing dictionary file
}

int cmpFunction(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int searchWord(char *word) {
    void *result = bsearch(word, dictionary, dictCount, sizeof(dictionary[0]), cmpFunction); // Searching word in dictionary
    if(result != NULL) {
        return 1; // Word exists in dictionary
    }
    return 0; // Word does not exist in dictionary
}

int main() {
    readDictionary(); // Reading dictionary from file
    
    char userSentence[MAX_WORD_SIZE];
    printf("Enter a sentence to check for spelling errors: ");
    fgets(userSentence, MAX_WORD_SIZE, stdin); // Reading user input

    char *token = strtok(userSentence, " "); // Tokenizing user input
    printf("\nParanoid Spell Checking:\n");
    while(token != NULL) {
        int len = strlen(token);
        if(len > 0 && token[len-1] == '\n') { // Removing newline character from token
            token[len-1] = '\0';
        }
        if(!searchWord(token)) { // Checking if word exists in dictionary
            printf("\tDid you mean: ");
            for(int i=0; i<dictCount; i++) {
                if(strncmp(token, dictionary[i], len-1) == 0) { // Searching for possible correct words
                    printf("%s, ", dictionary[i]);
                }
            }
            printf("\n"); // Printing new line after all suggestions
        }
        token = strtok(NULL, " "); // Fetching next token from user input
    }

    printf("\n");
    return 0; // End of program
}