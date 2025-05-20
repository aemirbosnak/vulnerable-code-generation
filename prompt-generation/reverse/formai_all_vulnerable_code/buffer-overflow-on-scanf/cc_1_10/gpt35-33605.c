//FormAI DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Function to get email list from server
void fetchEmails() {
    printf("\nFetching emails from server...");
    // Code to fetch emails from server goes here
}

// Function to compose and send an email
void sendEmail() {
    printf("\nCompose a new email:");
    // Code to compose email goes here
    // Once the email is composed, code to send email goes here
    printf("\nEmail sent successfully!");
}

// Function to read and display a specific email
void readEmail() {
    printf("\nEnter email id to read: ");
    // Code to read email from server goes here
    printf("\nFrom: John Doe");
    printf("\nTo: Jane Smith");
    printf("\nSubject: Meeting Request");
    printf("\nBody: Please let me know your availability for the upcoming meeting.");
}

// Main function
int main() {
    printf("\nWelcome to My Email Client!");
    int choice;
    do {
        printf("\n\n1. Fetch emails\n2. Send email\n3. Read email\n4. Quit\nSelect an option: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                fetchEmails();
                break;
            case 2:
                sendEmail();
                break;
            case 3:
                readEmail();
                break;
            case 4:
                printf("\nQuitting My Email Client...");
                break;
            default:
                printf("\nInvalid choice! Please try again...");
        }
    } while(choice != 4);

    return 0;
}