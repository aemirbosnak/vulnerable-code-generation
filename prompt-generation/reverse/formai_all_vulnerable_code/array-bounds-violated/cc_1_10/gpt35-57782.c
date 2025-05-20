//FormAI DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to check if the character is alphabetic
bool isAlphabetic(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

// Function to check if the character is a punctuation symbol
bool isPunctuation(char c) {
    if (c == '.' || c == ',' || c == ';' || c == ':' || c == '?' || c == '!') {
        return true;
    }
    return false;
}

// Function to check if a word is spelled correctly
bool checkSpelling(char *word) {
    // Open the dictionary file in read mode
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error: Unable to open dictionary file!");
        exit(1);
    }

    char buffer[50];
    // Loop through each word in the dictionary file
    while (fgets(buffer, 50, dictionary) != NULL) {
        // Remove the newline character from the end of the word
        buffer[strlen(buffer) - 1] = '\0';
        // Check if the word matches the one we're looking for
        if(strcmp(buffer, word) == 0) {
            fclose(dictionary);
            return true;
        }
    }
    fclose(dictionary);
    return false;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence to spell check: ");
    fgets(sentence, 1000, stdin);

    // Loop through each character in the sentence
    int i = 0;
    while(sentence[i] != '\0') {
        // Check if the current character is alphabetic
        if (isAlphabetic(sentence[i])) {
            char word[50];
            int j = 0;
            // Keep adding characters to the word until we reach a non-alphabetic character or the end of the sentence
            while(isAlphabetic(sentence[i]) || isPunctuation(sentence[i])) {
                word[j] = sentence[i];
                i++;
                j++;
            }
            word[j] = '\0';
            // Check if the word is spelled correctly
            if (!checkSpelling(word)) {
                printf("'%s' is misspelled!\n", word);
            }
        }
        else {
            i++;
        }
    }
    return 0;
}