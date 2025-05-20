//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of an email address
#define MAX_EMAIL_LEN 100

// Define the maximum number of spammy words
#define MAX_SPAM_WORDS 10

// Define the list of spammy words
char *spammy_words[] = {"free", "money", "click", "win", "prize", "urgent", "limited time", "act now", "don't miss out", "subscribe"};

// Check if an email address is spammy
int is_spam(char *email) {
    // Check if the email address is valid
    if (!strchr(email, '@')) {
        return 1;
    }

    // Check if the email address contains any spammy words
    for (int i = 0; i < MAX_SPAM_WORDS; i++) {
        if (strstr(email, spammy_words[i])) {
            return 1;
        }
    }

    // Otherwise, the email address is not spammy
    return 0;
}

// Get an email address from the user
char *get_email() {
    char *email = malloc(MAX_EMAIL_LEN);

    printf("Enter an email address: ");
    scanf("%s", email);

    return email;
}

// Main function
int main() {
    // Get an email address from the user
    char *email = get_email();

    // Check if the email address is spammy
    int is_spammy = is_spam(email);

    // Print the result
    if (is_spammy) {
        printf("The email address is spammy.\n");
    } else {
        printf("The email address is not spammy.\n");
    }

    // Free the memory allocated for the email address
    free(email);

    return 0;
}