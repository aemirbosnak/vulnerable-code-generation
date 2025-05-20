//FormAI DATASET v1.0 Category: Word Count Tool ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char string[1000], word[50];
    int i, j, count = 0, len;

    printf("Welcome to the C Word Count Tool!\n");
    printf("Enter a string (max 1000 characters):\n");

    // Read the input string
    fgets(string, sizeof(string), stdin);

    // Remove the trailing newline character
    string[strcspn(string, "\n")] = 0;

    // Get the length of the input string
    len = strlen(string);

    // Traverse the input string character by character
    for (i = 0; i < len; i++) {

        // Check if the current character is a letter or a digit
        if (isalnum(string[i])) {
            word[count++] = string[i];
        }
        // If the current character is a non-alphanumeric character,
        // it marks the end of a word
        else {
            // Add a null terminator to the end of the current word
            word[count] = '\0';

            // If the current word is not empty
            if (strlen(word) > 0) {
                // Increase the word count
                j++;
            }

            // Reset the word count to 0 for the next word
            count = 0;
        }
    }

    // Check if there is a last word in the input string
    if (count > 0) {
        // Add a null terminator to the end of the last word
        word[count] = '\0';

        // If the last word is not empty
        if (strlen(word) > 0) {
            // Increase the word count
            j++;
        }
    }

    printf("The total number of words in the input string is: %d\n", j);

    return 0;
}