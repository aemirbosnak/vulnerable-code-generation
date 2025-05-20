//FormAI DATASET v1.0 Category: Spam Detection System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum message length
#define MAX_MSG_LENGTH 1000

// Define maximum number of repeated characters
#define MAX_REPEAT_CHARS 3

// Define minimum length of repeated characters sequence
#define MIN_REPEAT_SEQUENCE_LENGTH 4

// Define function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    // Define variables
    char message[MAX_MSG_LENGTH + 1];
    int repeatCount = 1, repeatCharCount = 0;
    int i, j, len;

    // Ask user for message input
    printf("Enter message: ");
    fgets(message, MAX_MSG_LENGTH + 1, stdin);

    // Remove newline character from message
    len = strlen(message);
    if (message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // Check for repeated characters
    for (i = 0; message[i] != '\0'; i++) {
        // Check if current character is a letter
        if (isLetter(message[i])) {
            // Check if current character is the same as the previous one
            if (message[i] == message[i - 1]) {
                // Increment repeat count
                repeatCount++;

                // Check if repeat count exceeds maximum allowed value
                if (repeatCount > MAX_REPEAT_CHARS) {
                    // Increment repeated character count
                    repeatCharCount++;
                }
            } else {
                // Reset repeat count
                repeatCount = 1;
            }
        }
    }

    // Check for repeated character sequences
    for (i = 0; message[i] != '\0'; i++) {
        // Check if current character is a letter
        if (isLetter(message[i])) {
            // Check for repeated character sequences
            for (j = i + 1; message[j] != '\0'; j++) {
                // Check if current character is the same as the previous one
                if (message[j] == message[j - 1]) {
                    // Increment repeat count
                    repeatCount++;

                    // Check if repeat count exceeds minimum allowed sequence length
                    if (repeatCount >= MIN_REPEAT_SEQUENCE_LENGTH) {
                        // Increment repeated character count
                        repeatCharCount++;
                    }
                } else {
                    // Reset repeat count
                    repeatCount = 1;
                }
            }
        }
    }

    // Check if number of repeated characters exceeds threshold
    if (repeatCharCount > 0) {
        printf("The message contains %d repeated characters or sequences and may be spam.\n", repeatCharCount);
    } else {
        printf("The message does not contain any repeated characters or sequences and is not spam.\n");
    }

    // Exit program
    return 0;
}