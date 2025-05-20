//FormAI DATASET v1.0 Category: Word Count Tool ; Style: automated
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

/* Function to count words in a string */
int countWords(char* string) {
    int count = 0;

    // Iterate through each character in the string
    for (int i = 0; string[i] != '\0'; i++) {

        // If there is a space or a newline character, it means a new word starts
        if (string[i] == ' ' || string[i] == '\n') {
            count++;
        }
    }

    // Return the total word count
    return count;
}

int main() {
    char userInput[MAX_WORDS][MAX_WORD_LENGTH];
    int count[MAX_WORDS], wordCount = 0;

    // Read user input lines until no input is provided
    while (fgets(userInput[wordCount], MAX_WORD_LENGTH, stdin) != NULL) {
        int inputLength = strlen(userInput[wordCount]);

        // If the input has a newline character at the end, replace it with null character
        if (userInput[wordCount][inputLength - 1] == '\n') {
            userInput[wordCount][inputLength - 1] = '\0';
        }

        // Count the number of words in the user input and save it to an array
        count[wordCount] = countWords(userInput[wordCount]);
        wordCount++;

        // If the user input limit is reached, break out of the loop
        if (wordCount == MAX_WORDS) {
            break;
        }
    }

    // Output the word count for each input string
    for (int i = 0; i < wordCount; i++) {
        printf("Line %d has %d words.\n", i + 1, count[i]);
    }

    return 0;
}