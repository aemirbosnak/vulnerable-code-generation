//FormAI DATASET v1.0 Category: Email Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUBJECT_SIZE 100
#define MAX_MESSAGE_SIZE 500

struct Email {
    char subject[MAX_SUBJECT_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char sender[50];
    char recipient[50];
    bool read;
};

void sendEmail(struct Email* email) {
    /* Function that sends the email */
    printf("----------------------------\n");
    printf("Sending email...\n");
    printf("To: %s\n", email->recipient);
    printf("From: %s\n", email->sender);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
    printf("----------------------------\n");
}

void readEmail(struct Email* email) {
    /* Function that displays the email on the screen */
    printf("----------------------------\n");
    printf("From: %s\n", email->sender);
    printf("Subject: %s\n", email->subject);
    printf("Message: %s\n", email->message);
    printf("----------------------------\n");
    email->read = true; // Mark email as read
}

int main() {
    int choice;
    int counter = 0; // Counter for number of emails
    struct Email* emailList = malloc(sizeof(struct Email)); // Allocate memory
    while (true) { // Loop until user exits
        printf("Main Menu:\n");
        printf("1. Compose New Email\n");
        printf("2. Check Inbox\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Sending Email:\n");
                printf("Enter recipient: ");
                scanf("%s", emailList[counter].recipient);
                printf("Enter subject: ");
                scanf("%s", emailList[counter].subject);
                printf("Enter message: ");
                scanf("%s", emailList[counter].message);
                strcpy(emailList[counter].sender, "user@example.com"); // Set sender as user's email
                sendEmail(&emailList[counter]); // Call sendEmail function to send email
                counter++; // Increment counter
                emailList = realloc(emailList, (counter + 1) * sizeof(struct Email)); // Resize email list
                break;
            case 2:
                printf("Inbox:\n");
                for (int i = 0; i < counter; i++) {
                    if (!emailList[i].read) {
                        readEmail(&emailList[i]); // Call readEmail function to display email
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                free(emailList); // Free allocated memory before exiting
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}