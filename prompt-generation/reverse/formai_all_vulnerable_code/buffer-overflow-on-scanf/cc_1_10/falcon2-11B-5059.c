//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check if a word is spelled correctly
int isWordCorrect(char *word, char *dictionary[])
{
    // Loop through the dictionary and compare each word with the input word
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(char*); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to get suggestions for misspelled words
char *getSuggestions(char *word, char *dictionary[])
{
    // Loop through the dictionary and find the closest word to the input word
    int i;
    for (i = 0; i < sizeof(dictionary) / sizeof(char*); i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return dictionary[i];
        }
    }
    
    // If no suggestions are found, return an empty string
    return "";
}

// Function to check if a sentence is spelled correctly
int checkSentence(char *sentence, char *dictionary[])
{
    // Loop through each word in the sentence and check if it is spelled correctly
    int i, j;
    for (i = 0; sentence[i]!= '\0'; i++) {
        if (isWordCorrect(sentence + i, dictionary)) {
            continue;
        }
        
        // Get suggestions for the misspelled word
        char *suggestion = getSuggestions(sentence + i, dictionary);
        
        // Replace the misspelled word with the suggestion
        if (suggestion!= NULL) {
            strcpy(sentence + i, suggestion);
            continue;
        }
        
        // If no suggestions are found, print an error message and return 0
        printf("Error: %s is misspelled\n", sentence + i);
        return 0;
    }
    
    return 1;
}

// Main function
int main()
{
    // Define the dictionary
    char *dictionary[] = {
        "apple", "apples",
        "banana", "bananas",
        "orange", "oranges",
        "grape", "grapes",
        "pear", "pears"
    };
    
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    scanf("%s", sentence);
    
    // Check if the sentence is spelled correctly
    if (checkSentence(sentence, dictionary)) {
        printf("The sentence is spelled correctly\n");
    } else {
        printf("The sentence is misspelled\n");
    }
    
    return 0;
}