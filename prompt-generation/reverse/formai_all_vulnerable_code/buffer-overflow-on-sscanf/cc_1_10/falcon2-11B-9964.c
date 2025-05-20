//Falcon2-11B DATASET v1.0 Category: Spam Detection System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

// Define the function prototypes
int isSpam(char* email);

// Main function
int main() {
    // Read the email message from user input
    char email[256];
    printf("Enter the email message: ");
    fgets(email, sizeof(email), stdin);

    // Call the isSpam function to check if the email is spam
    int is_spam = isSpam(email);

    // Print the result
    if (is_spam) {
        printf("Spam detected.\n");
    } else {
        printf("No spam detected.\n");
    }

    return 0;
}

// Function to check if the email is spam
int isSpam(char* email) {
    // Initialize the confidence score to 0
    int confidence_score = 0;

    // Split the email message into individual words
    char* words[256];
    int num_words = sscanf(email, "%s", words);

    // Loop through each word and check if it contains a spam keyword
    for (int i = 0; i < num_words; i++) {
        // Check if the word is a spam keyword
        if (strstr(words[i], "viagra") || strstr(words[i], "cialis") || strstr(words[i], "pharmacy")) {
            // Increment the confidence score by 1
            confidence_score++;
        }
    }

    // Return the confidence score
    return confidence_score;
}