//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to check if word is in dictionary
int isInDictionary(char* word) {
    // Open dictionary file
    FILE* dictionary = fopen("dictionary.txt", "r");

    // Check if dictionary file was opened successfully
    if (dictionary == NULL) {
        printf("Error: Dictionary file not found.\n");
        exit(1);
    }

    // Read each word from dictionary file
    char dictionaryWord[50];
    while (fscanf(dictionary, "%s", dictionaryWord)!= EOF) {
        // Compare current word with dictionary word
        if (strcmp(word, dictionaryWord) == 0) {
            // Word is in dictionary
            fclose(dictionary);
            return 1;
        }
    }

    // Word is not in dictionary
    fclose(dictionary);
    return 0;
}

// Function to check spelling of words in a sentence
int checkSpelling(char* sentence) {
    // Split sentence into words
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        // Check if word is in dictionary
        if (isInDictionary(token) == 0) {
            // Word is not in dictionary
            printf("%s is not a valid word.\n", token);
        }
        // Get next word
        token = strtok(NULL, " ");
    }
    return 0;
}

// Main function
int main() {
    // Post-apocalyptic scenario
    printf("In a post-apocalyptic world, where language is evolving rapidly,\n");
    printf("the ability to spell correctly is more important than ever.\n\n");

    // Get input sentence from user
    printf("Enter a sentence: ");
    char sentence[1000];
    fgets(sentence, 1000, stdin);

    // Check spelling of words in sentence
    checkSpelling(sentence);

    return 0;
}