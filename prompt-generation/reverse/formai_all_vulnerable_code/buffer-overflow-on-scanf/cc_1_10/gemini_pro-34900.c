//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a spam message.
#define SPAM_MESSAGE_LENGTH 1024

// Define the maximum number of spam words.
#define SPAM_WORDS_COUNT 100

// Define the spam words.
const char *spam_words[] = {
    "free",
    "money",
    "win",
    "lose",
    "prize",
    "offer",
    "sale",
    "discount",
    "click",
    "here",
    "now"
};

// Function to classify a message as spam or not.
int is_spam(const char *message) {
    // Calculate the number of spam words in the message.
    int spam_words_count = 0;
    for (int i = 0; i < SPAM_WORDS_COUNT; i++) {
        if (strstr(message, spam_words[i]) != NULL) {
            spam_words_count++;
        }
    }

    // If the number of spam words is greater than or equal to 3, the message is classified as spam.
    if (spam_words_count >= 3) {
        return 1;
    }

    // Otherwise, the message is classified as not spam.
    return 0;
}

// Main function.
int main() {
    // Get the message from the user.
    char message[SPAM_MESSAGE_LENGTH];
    printf("Enter a message: ");
    scanf("%s", message);

    // Classify the message as spam or not.
    int is_spam_result = is_spam(message);

    // Print the result.
    if (is_spam_result == 1) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}