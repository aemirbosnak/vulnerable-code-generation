//FormAI DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to send an email
void send_email() {
    printf("Sending email...just a moment!\n");
    // Some code to send email goes here
    printf("Email sent successfully!\n");
}

// Function to read emails
void read_email() {
    printf("Fetching emails...hang tight!\n");
    // Some code to read emails goes here
    printf("You have 5 new emails!\n");
}

// Function to write emails
void write_email() {
    printf("Let's write a new email!\n");
    printf("Type in the recipient's email address: ");
    char recipient[50];
    scanf("%s", recipient);
    printf("What is the subject of your email? ");
    char subject[50];
    scanf("%s", subject);
    printf("Type in your message: ");
    char message[1000];
    scanf("%s", message);
    printf("Writing email...almost there!\n");
    // Some code to write email goes here
    printf("Email sent successfully to %s with subject %s and message %s!\n", recipient, subject, message);
}

void main() {
    char choice;    
    printf("Welcome to the Simple C Email Client!\n\n");
    do {
        printf("What would you like to do? (S)end, (R)ead, or (W)rite an email? ");
        scanf("%c", &choice);
        switch (choice) {
            case 's':
            case 'S':
                send_email();
                break;
            case 'r':
            case 'R':
                read_email();
                break;
            case 'w':
            case 'W':
                write_email();
                break;
            default:
                printf("Sorry, I did not understand your choice. Please try again.\n");
                break;
        }
        printf("Would you like to continue? (Y)es or (N)o: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    printf("Thank you for using the Simple C Email Client!\n");
}