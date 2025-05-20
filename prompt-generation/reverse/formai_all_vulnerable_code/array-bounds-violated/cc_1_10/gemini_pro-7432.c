//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input message
#define MAX_SIZE 1024

// Define the number of allowed consecutive occurrences of the same character
#define MAX_CONSECUTIVE 3

// Recursive function to check for spam
int check_spam(char *message, int index, int consecutive) {
    // Base case: Reached the end of the message
    if (message[index] == '\0') {
        // Return 1 if more than MAX_CONSECUTIVE consecutive identical characters were found
        return consecutive > MAX_CONSECUTIVE;
    }

    // Check if the current character is the same as the previous one
    if (message[index] == message[index - 1]) {
        // Increment the count of consecutive identical characters
        consecutive++;
    } else {
        // Reset the count of consecutive identical characters
        consecutive = 1;
    }

    // Recursively check the rest of the message
    return check_spam(message, index + 1, consecutive);
}

int main() {
    // Get the input message from the user
    char message[MAX_SIZE];
    printf("Enter the message to check: ");
    fgets(message, MAX_SIZE, stdin);

    // Remove the newline character at the end of the message
    if (message[strlen(message) - 1] == '\n') {
        message[strlen(message) - 1] = '\0';
    }

    // Check if the message contains spam
    int is_spam = check_spam(message, 0, 0);

    // Print the result
    if (is_spam) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}