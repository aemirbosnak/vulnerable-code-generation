//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the function to count the words in a string
int count_words(char *string);

// Declare the main function
int main() {
    char *string;
    int word_count;

    // Get the string from the user
    printf("Enter a string: ");
    scanf("%s", string);

    // Count the words in the string
    word_count = count_words(string);

    // Print the word count
    printf("The string contains %d words.\n", word_count);

    return 0;
}

// Define the function to count the words in a string
int count_words(char *string) {
    int word_count = 0;
    int in_word = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(string); i++) {
        // If the current character is a space, and we were previously in a word, then we have found the end of a word
        if (string[i] == ' ' && in_word) {
            word_count++;
            in_word = 0;
        }
        // If the current character is not a space, and we were not previously in a word, then we have found the start of a word
        else if (string[i] != ' ' && !in_word) {
            in_word = 1;
        }
    }

    // If the last character of the string is not a space, then we have found the end of a word
    if (in_word) {
        word_count++;
    }

    return word_count;
}