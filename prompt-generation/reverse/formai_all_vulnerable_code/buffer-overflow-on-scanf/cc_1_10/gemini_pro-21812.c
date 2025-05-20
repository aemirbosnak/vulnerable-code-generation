//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Romeo and Juliet
// Romeo and Juliet Spam Detection System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Montagues and Capulets
#define MONTAGUES "Montague"
#define CAPULETS "Capulet"

// Define the prohibited words
char *prohibited_words[] = {"hate", "kill", "death", "poison", "banish"};
int num_prohibited_words = 5;

// Function to check if a string contains a prohibited word
int contains_prohibited_word(char *str) {
    for (int i = 0; i < num_prohibited_words; i++) {
        if (strstr(str, prohibited_words[i])) {
            return 1;
        }
    }
    return 0;
}

// Function to classify a message as spam or not spam
int classify_message(char *message) {
    // Check if the message contains a prohibited word
    if (contains_prohibited_word(message)) {
        return 1;
    }

    // Check if the message is from a Montague or Capulet
    if (strstr(message, MONTAGUES) || strstr(message, CAPULETS)) {
        return 1;
    }

    // Otherwise, the message is not spam
    return 0;
}

// Main function
int main() {
    // Get the message from the user
    char message[256];
    printf("Enter the message: ");
    scanf("%s", message);

    // Classify the message
    int is_spam = classify_message(message);

    // Print the result
    if (is_spam) {
        printf("This message is spam.\n");
    } else {
        printf("This message is not spam.\n");
    }

    return 0;
}