//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Spam detection function
int isSpam(char *message) {
    
    // Check for common spam words
    char *spamWords[] = {"free", "offer", "discount", "win", "prize"};
    int numSpamWords = 5;

    for (int i = 0; i < numSpamWords; i++) {
        if (strstr(message, spamWords[i]) != NULL) {
            return 1;
        }
    }

    // Check for excessive punctuation
    int numPunctuation = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == '!' || message[i] == '?' || message[i] == ',') {
            numPunctuation++;
        }
    }

    if (numPunctuation > 5) {
        return 1;
    }

    // Check for all caps
    if (strcspn(message, "abcdefghijklmnopqrstuvwxyz") == strlen(message)) {
        return 1;
    }

    // All checks passed, message is likely not spam
    return 0;
}

int main() {
    
    // Get the message from the user
    char message[1024];
    printf("Enter the message: ");
    scanf("%s", message);

    // Check if the message is spam
    int isSpamResult = isSpam(message);

    // Print the result
    if (isSpamResult) {
        printf("The message is likely spam.\n");
    } else {
        printf("The message is likely not spam.\n");
    }

    return 0;
}