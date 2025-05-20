//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
// A simple mailing list manager program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of emails that can be stored in the mailing list
#define MAX_EMAILS 100

// Define the maximum length of an email address
#define MAX_EMAIL_LENGTH 50

// Define the maximum length of a name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a message
#define MAX_MESSAGE_LENGTH 500

// Struct to define an email
typedef struct email {
    char name[MAX_NAME_LENGTH];
    char email_address[MAX_EMAIL_LENGTH];
} Email;

// Struct to define a message
typedef struct message {
    Email sender;
    Email recipient;
    char subject[MAX_NAME_LENGTH];
    char body[MAX_MESSAGE_LENGTH];
} Message;

// Function to add an email to the mailing list
void add_email(Email mailing_list[], int* num_emails) {
    if (*num_emails >= MAX_EMAILS) {
        printf("Mailing list is full!\n");
        return;
    }

    printf("Enter the name: ");
    scanf("%s", mailing_list[*num_emails].name);

    printf("Enter the email address: ");
    scanf("%s", mailing_list[*num_emails].email_address);

    printf("Email added!\n");

    (*num_emails)++;
}

// Function to send a message to an email address
void send_message(Email mailing_list[], int num_emails) {
    if (num_emails == 0) {
        printf("Mailing list is empty!\n");
        return;
    }

    Message message;

    printf("Enter your name: ");
    scanf("%s", message.sender.name);

    printf("Enter your email address: ");
    scanf("%s", message.sender.email_address);

    printf("Enter the recipient's name: ");
    scanf("%s", message.recipient.name);

    int found = 0;
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(message.recipient.name, mailing_list[i].name) == 0) {
            strcpy(message.recipient.email_address, mailing_list[i].email_address);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Recipient not found in mailing list!\n");
        return;
    }

    printf("Enter the subject: ");
    scanf("%s", message.subject);

    printf("Enter the message: ");
    scanf("%s", message.body);

    printf("Message sent to %s!\n", message.recipient.email_address);
}

// Function to print the mailing list
void print_mailing_list(const Email mailing_list[], int num_emails) {
    printf("Mailing List:\n");

    for (int i = 0; i < num_emails; i++) {
        printf("%s - %s\n", mailing_list[i].name, mailing_list[i].email_address);
    }
}

// Main function to run the program
int main() {
    Email mailing_list[MAX_EMAILS];
    int num_emails = 0;
    int choice;

    do {
        printf("\n");
        printf("1. Add an email to the mailing list\n");
        printf("2. Send a message to an email address in the mailing list\n");
        printf("3. Print the mailing list\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_email(mailing_list, &num_emails);
                break;
            case 2:
                send_message(mailing_list, num_emails);
                break;
            case 3:
                print_mailing_list(mailing_list, num_emails);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}