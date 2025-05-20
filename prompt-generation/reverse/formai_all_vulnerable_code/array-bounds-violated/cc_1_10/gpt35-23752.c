//FormAI DATASET v1.0 Category: Spell checking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the maximum length of each word
#define MAX_WORD_LEN 50

int main() {
    // Declare variables
    char word[MAX_WORD_LEN];
    int index, length, word_count = 1;
    FILE *file;
    
    // Open the file to be checked
    file = fopen("document.txt", "r");
    
    if (file) {
        // Read each line of the file
        while (fgets(word, MAX_WORD_LEN, file)) {
            // Get the length of the line
            length = strlen(word);
            
            // Loop through each character in the line
            for (index = 0; index < length; index++) {
                // Check if the current character is a letter
                if (isalpha(word[index])) {
                    // Convert the letter to lowercase
                    word[index] = tolower(word[index]);
                } else if (word[index] == '\n') {
                    // If we have reached the end of the line, reset the word count for the next line
                    word_count = 1;
                } else {
                    // If the character is not a letter or a newline, it is a space or punctuation mark
                    // Check if we have a complete word
                    if (word_count > 1) {
                        // Print the misspelled word
                        printf("Misspelled word: %s\n", word);
                    }
                    
                    // Reset the word count for the next word
                    word_count = 1;
                }
            }
            
            // Check if the last character in the line is a letter
            if (isalpha(word[length - 1])) {
                // Increment the word count for the last word in the line
                word_count++;
            }
        }
        
        // Close the file
        fclose(file);
    } else {
        // Error message if file is not found
        printf("Error: File not found.");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}