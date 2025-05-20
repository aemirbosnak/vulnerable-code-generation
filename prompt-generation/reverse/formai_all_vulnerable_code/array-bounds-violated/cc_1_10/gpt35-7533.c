//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    // Declare variables
    char text[1000]; // Maximum allowable length of text
    char word[100]; // Maximum allowable length of word
    int count = 0;
    int i, j;
    
    // Print instructions
    printf("Welcome to the Medieval Word Count Tool!\n");
    printf("Please enter the text you would like to count:\n");
    
    // Read in the text
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character from text
    text[strlen(text) - 1] = '\0';
    
    // Convert text to lowercase
    for (i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }
    
    // Print instructions for word input
    printf("Please enter the word you would like to count:\n");
    
    // Read in the word
    fgets(word, sizeof(word), stdin);
    
    // Remove newline character from word
    word[strlen(word) - 1] = '\0';
    
    // Convert word to lowercase
    for (i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
    
    // Count occurrences of word in text
    for (i = 0; i < strlen(text); i++) {
        if (text[i] == word[0]) {
            for (j = 0; j < strlen(word); j++) {
                if (text[i+j] != word[j]) {
                    break;
                }
                if (j == strlen(word) - 1) {
                    count++;
                }
            }
        }
    }
    
    // Print result
    printf("The word '%s' appears %d times in the text.\n", word, count);
    
    return 0;
}