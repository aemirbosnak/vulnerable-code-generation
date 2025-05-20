//FormAI DATASET v1.0 Category: Email Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structs for email and account
typedef struct {
    char from[50];
    char to[50];
    char subject[100];
    char body[1000];
    char attachments[100][50];
    int num_attachments;
} email;

typedef struct {
    char email[50];
    char password[50];
} account;

// Declare global variables for program operation
account accounts[10];
int num_accounts = 0;

// Function to add a new email account
void add_account() {
    printf("\nEnter your email address: ");
    scanf("%s", accounts[num_accounts].email);
    printf("Enter your password: ");
    scanf("%s", accounts[num_accounts].password);
    num_accounts++;
    printf("\nAccount added successfully!\n");
}

// Function to prompt user to select an email account
int select_account() {
    printf("\nSelect an email account:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d. %s\n", i+1, accounts[i].email);
    }
    int choice = 0;
    scanf("%d", &choice);
    if (choice < 1 || choice > num_accounts) {
        printf("\nInvalid choice. Please try again.\n");
        return select_account();
    }
    return choice-1;
}

// Function to compose a new email
email new_email() {
    email e;
    int account_index = select_account();
    strcpy(e.from, accounts[account_index].email);
    printf("\nTo: ");
    scanf("%s", e.to);
    printf("Subject: ");
    scanf("%s", e.subject);
    printf("Body: ");
    scanf(" %[^\n]s", e.body);
    printf("Number of attachments (max 5): ");
    scanf("%d", &e.num_attachments);
    for (int i = 0; i < e.num_attachments; i++) {
        printf("Attachment %d: ", i+1);
        scanf("%s", e.attachments[i]);
    }
    printf("\nEmail has been composed successfully!\n");
    return e;
}

// Function to display an email
void display_email(email e) {
    printf("\nFrom: %s\n", e.from);
    printf("To: %s\n", e.to);
    printf("Subject: %s\n", e.subject);
    printf("Body: %s\n", e.body);
    printf("Attachments: ");
    for (int i = 0; i < e.num_attachments; i++) {
        printf("%s ", e.attachments[i]);
    }
    printf("\n");
}

// Function to receive new emails
void receive_emails() {
    int account_index = select_account();
    printf("\nReceiving emails for %s...\n", accounts[account_index].email);
    // TODO: Implement email receiving protocol here
    printf("\nNo new emails.\n");
}

// Main function to handle program flow
int main() {
    printf("Welcome to the Cheerful C Email Client!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new email account\n");
        printf("2. Compose a new email\n");
        printf("3. Receive new emails\n");
        printf("4. Exit\n");
        int choice = 0;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                display_email(new_email());
                break;
            case 3:
                receive_emails();
                break;
            case 4:
                printf("\nThanks for using the Cheerful C Email Client!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}