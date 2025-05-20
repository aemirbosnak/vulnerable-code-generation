//FormAI DATASET v1.0 Category: Spam Detection System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000   // Maximum email message length for spam detection

int main() {
    char email_message[MAX_SIZE];   // The email message to be analyzed
    int length;                     // Length of the email message
    int spam_count = 0;             // Count of spam words found
    int word_count = 0;             // Total word count
    float spam_percentage;          // Percentage of spam words in email

    char *spam_words[] = {"free", "discount", "offer", "credit", "sale"};   // List of spam words

    // Prompt user to input email message
    printf("Enter email message: \n");
    fgets(email_message, MAX_SIZE, stdin);

    // Remove newline character from message
    length = strlen(email_message);
    if (email_message[length - 1] == '\n') {
        email_message[length - 1] = '\0';
    }

    // Tokenize the email message
    char *token = strtok(email_message, " ");
    while (token != NULL) {
        for (int i = 0; i < sizeof(spam_words) / sizeof(spam_words[0]); i++) {
            if (strcmp(token, spam_words[i]) == 0) {   // Compare token with spam_word list
                spam_count++;
                break;                                  // Stop iterating through spam_word list
            }
        }
        word_count++;                                   // Increment word count
        token = strtok(NULL, " ");
    }

    // Calculate spam percentage
    spam_percentage = (float) spam_count / word_count * 100;

    // Print results
    printf("\nTotal words in email: %d\n", word_count);
    printf("Number of spam words found: %d\n", spam_count);
    printf("Percentage of spam words in email: %.2f%%\n", spam_percentage);

    // Determine whether email is spam based on percentage threshold
    if (spam_percentage >= 10) {
        printf("\nThis email is likely spam.\n");
    } else {
        printf("\nThis email is not likely spam.\n");
    }

    return 0;
}