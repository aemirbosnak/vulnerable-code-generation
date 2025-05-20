//FormAI DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_MESSAGE_LENGTH 500

struct EmailInfo{
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
};

struct EmailBox{
    struct EmailInfo emails[MAX_EMAILS];
    int noOfEmails;
};

void printEmailBox(struct EmailBox emailBox);
void sendEmail(struct EmailBox* emailBox);
void deleteEmail(struct EmailBox* emailBox, int index);

int main() {
    struct EmailBox emailBox = {{0}, 0};
    int choice = 0;
    do {
        printf("\n1. Print email box\n");
        printf("2. Send email\n");
        printf("3. Delete email\n");
        printf("4. Quit\n");
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printEmailBox(emailBox);
                break;
            case 2:
                sendEmail(&emailBox);
                break;
            case 3:
                if (emailBox.noOfEmails == 0) {
                    printf("\nNo emails to delete!\n");
                } else {
                    int emailIndex;
                    printf("\nEnter email index (1-%d) you want to delete: ", emailBox.noOfEmails);
                    scanf("%d", &emailIndex);
                    deleteEmail(&emailBox, emailIndex - 1);
                }
                break;
            case 4:
                printf("\nQuitting...\n");
                break;
            default:
                printf("\nInvalid input! Please enter a digit between 1 and 4.\n");
                break;
        }
    }
    while (choice != 4);
    return 0;
}

void printEmailBox(struct EmailBox emailBox) {
    if (emailBox.noOfEmails == 0) {
        printf("\nNo emails in email box!\n");
    } else {
        printf("\nEmail box contents:\n");
        for (int i = 0; i < emailBox.noOfEmails; i++) {
            printf("------------------------\n");
            printf("From: %s\n", emailBox.emails[i].sender);
            printf("To: %s\n", emailBox.emails[i].receiver);
            printf("Subject: %s\n", emailBox.emails[i].subject);
            printf("Message: %s\n", emailBox.emails[i].message);
            printf("------------------------\n");
        }
    }
}

void sendEmail(struct EmailBox* emailBox) {
    if (emailBox->noOfEmails == MAX_EMAILS) {
        printf("\nEmail box is full! Cannot send email...\n");
    } else {
        struct EmailInfo email;
        fflush(stdin);
        printf("\nEnter sender name: ");
        gets(email.sender);
        printf("Enter receiver name: ");
        gets(email.receiver);
        printf("Enter subject (less than 50 characters): ");
        gets(email.subject);
        printf("Enter message (less than 500 characters): ");
        gets(email.message);
        emailBox->emails[emailBox->noOfEmails++] = email;
        printf("\nEmail sent successfully!\n");
    }
}

void deleteEmail(struct EmailBox* emailBox, int index) {
    if (index < 0 || index >= emailBox->noOfEmails) {
        printf("\nInvalid email index!\n");
    } else {
        for (int i = index; i < emailBox->noOfEmails - 1; i++) {
            emailBox->emails[i] = emailBox->emails[i+1];
        }
        emailBox->noOfEmails--;
        printf("\nEmail deleted successfully!\n");
    }
}