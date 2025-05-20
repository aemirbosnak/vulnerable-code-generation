//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of an email message
#define MAX_EMAIL_SIZE 1024

// Define the number of spam filters
#define NUM_FILTERS 5

// Define the spam filters
char *filters[] = {
    "Viagra",
    "Cialis",
    "Levitra",
    "penis enlargement",
    "make money fast"
};

// Define the function to check if an email is spam
int is_spam(char *email) {
    // Check if the email contains any of the spam filters
    for (int i = 0; i < NUM_FILTERS; i++) {
        if (strstr(email, filters[i]) != NULL) {
            return 1;
        }
    }

    // The email does not contain any of the spam filters
    return 0;
}

// Define the main function
int main() {
    // Get the email message from the user
    char email[MAX_EMAIL_SIZE];
    printf("Enter the email message: ");
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