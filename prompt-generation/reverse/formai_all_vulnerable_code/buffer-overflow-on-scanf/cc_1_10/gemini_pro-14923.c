//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 100

// Define the maximum number of words in a spam email
#define MAX_WORDS_IN_SPAM 20

// Define the maximum number of banned words in an email
#define MAX_BANNED_WORDS 10

// Define the array of banned words
const char *banned_words[] = {
    "free", "offer", "win", "prize", "money",
    "guarantee", "double", "your", "click", "here"
};

// Define the function to check if an email is spam
int is_spam(char *email) {
    // Get the number of words in the email
    int num_words = 0;
    char *word = strtok(email, " ");
    while (word != NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }

    // Check if the number of words in the email exceeds the maximum
    if (num_words > MAX_WORDS_IN_SPAM) {
        return 1;
    }

    // Check if the email contains any banned words
    for (int i = 0; i < MAX_BANNED_WORDS; i++) {
        if (strstr(email, banned_words[i]) != NULL) {
            return 1;
        }
    }

    // Otherwise, the email is not spam
    return 0;
}

// Define the main function
int main() {
    // Get the email from the user
    char email[MAX_EMAIL_LENGTH];
    printf("Enter the email: ");
    scanf("%s", email);

    // Check if the email is spam
    int is_spam_result = is_spam(email);

    // Print the result
    if (is_spam_result) {
        printf("The email is spam.\n");
    } else {
        printf("The email is not spam.\n");
    }

    return 0;
}