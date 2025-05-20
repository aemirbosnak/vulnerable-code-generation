//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to hold the data of a potential spam message
typedef struct {
    char sender[100];
    char subject[100];
    char body[1000];
} Email;

// A function to check if an email is spam
int isSpam(Email email) {

    // Check the reputation of the sender
    if (strcmp(email.sender, "nigerianprince@yahoo.com") == 0) {
        return 1;
    }

    // Check the subject line for trigger words
    if (strstr(email.subject, "FREE MONEY") != 0 || strstr(email.subject, "CLICK HERE") != 0) {
        return 1;
    }

    // Check the body of the email for trigger words
    if (strstr(email.body, "URGENT") != 0 || strstr(email.body, "ACT NOW") != 0) {
        return 1;
    }

    // Check the email for any suspicious links
    if (strstr(email.body, "http://www.suspiciouslink.com") != 0) {
        return 1;
    }

    // If none of the above checks trigger, the email is not spam
    return 0;
}

//A function to print out all the words that triggered the spam detection
void printSpamWords(Email email) {
    // Check the reputation of the sender
    if (strcmp(email.sender, "nigerianprince@yahoo.com") == 0) {
        printf("The sender is a known spammer.\n");
    }

    // Check the subject line for trigger words
    if (strstr(email.subject, "FREE MONEY") != 0) {
        printf("The subject line contains the trigger word 'FREE MONEY'.\n");
    }
    if (strstr(email.subject, "CLICK HERE") != 0) {
        printf("The subject line contains the trigger word 'CLICK HERE'.\n");
    }

    // Check the body of the email for trigger words
    if (strstr(email.body, "URGENT") != 0) {
        printf("The body of the email contains the trigger word 'URGENT'.\n");
    }
    if (strstr(email.body, "ACT NOW") != 0) {
        printf("The body of the email contains the trigger word 'ACT NOW'.\n");
    }

    // Check the email for any suspicious links
    if (strstr(email.body, "http://www.suspiciouslink.com") != 0) {
        printf("The email contains a suspicious link.\n");
    }
}

int main() {

    // Create an email struct
    Email email;

    // Get the email sender from the user
    printf("Enter the email sender: ");
    scanf("%s", email.sender);

    // Get the email subject from the user
    printf("\nEnter the email subject: ");
    scanf(" %[^\n]%*c", email.subject);

    // Get the email body from the user
    printf("\nEnter the email body: ");
    scanf(" %[^\n]%*c", email.body);

    // Check if the email is spam
    int isSpamResult = isSpam(email);

    // Print out the result
    if (isSpamResult == 1) {
        printf("\nThis email is spam.\n");
        printSpamWords(email);
    } else {
        printf("\nThis email is not spam.\n");
    }

    return 0;
}