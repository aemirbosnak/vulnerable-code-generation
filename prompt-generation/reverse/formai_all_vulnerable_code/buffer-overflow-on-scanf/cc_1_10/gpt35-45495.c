//FormAI DATASET v1.0 Category: Email Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

// Function prototypes
void printMenu();
void sendEmail();
void displayEmail();

// Global variables
char sender[MAX_LEN];
char recipient[MAX_LEN];
char subject[MAX_LEN];
char message[MAX_LEN];

int main() {
    int choice = 0;

    // Prompt user for email sender and recipient
    printf("Enter your email address: ");
    fgets(sender, MAX_LEN, stdin);
    printf("Enter recipient's email address: ");
    fgets(recipient, MAX_LEN, stdin);

    // Remove newline characters from sender and recipient
    sender[strcspn(sender, "\n")] = 0;
    recipient[strcspn(recipient, "\n")] = 0;

    // Main loop for email client
    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer
        printf("\n");

        // Switch statement for different options
        switch (choice) {
            case 1:
                sendEmail();
                break;
            case 2:
                displayEmail();
                break;
            case 3:
                printf("Exiting email client...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

// Prints the email client menu options
void printMenu() {
    printf("Email Client Menu\n");
    printf("-----------------\n");
    printf("1. Send Email\n");
    printf("2. Display Received Email\n");
    printf("3. Exit Email Client\n");
}

// Prompts user for email subject and message then sends the email
void sendEmail() {
    // Prompt user for email subject and message
    printf("Enter email subject: ");
    fgets(subject, MAX_LEN, stdin);
    printf("Enter email message: ");
    fgets(message, MAX_LEN, stdin);

    // Remove newline characters from subject and message
    subject[strcspn(subject, "\n")] = 0;
    message[strcspn(message, "\n")] = 0;

    // Construct email message
    char emailMessage[MAX_LEN*2];
    sprintf(emailMessage, "To: %s\nFrom: %s\nSubject: %s\n\n%s\n", recipient, sender, subject, message);

    // Open sendmail command for sending email
    FILE* sendmail = popen("/usr/sbin/sendmail -t", "w");

    // Check for errors with opening sendmail
    if (!sendmail) {
        perror("Error opening sendmail command");
        exit(EXIT_FAILURE);
    }

    // Write email message to sendmail command
    fprintf(sendmail, "%s", emailMessage);

    // Close sendmail command
    if (pclose(sendmail) == -1) {
        perror("Error closing sendmail command");
        exit(EXIT_FAILURE);
    }

    printf("Email sent to %s\n", recipient);
}

// Displays the last received email in full
void displayEmail() {
    // Open file for reading last email
    FILE* emailFile = fopen("inbox.txt", "r");

    // Check for errors with opening email file
    if (!emailFile) {
        perror("Error opening inbox.txt file");
        exit(EXIT_FAILURE);
    }

    // Read in last email header and message
    char emailHeader[MAX_LEN*2];
    char emailMessage[MAX_LEN*2];
    fgets(emailHeader, MAX_LEN*2, emailFile);
    fgets(emailMessage, MAX_LEN*2, emailFile);

    // Remove newline characters from email header and message
    emailHeader[strcspn(emailHeader, "\n")] = 0;
    emailMessage[strcspn(emailMessage, "\n")] = 0;

    // Print out last email in full
    printf("\nLast email received:\n\n");
    printf("%s\n%s\n", emailHeader, emailMessage);

    // Close email file
    if (fclose(emailFile) == EOF) {
        perror("Error closing inbox.txt file");
        exit(EXIT_FAILURE);
    }
}