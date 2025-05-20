//FormAI DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECT_SIZE 256
#define MAX_MESSAGE_SIZE 1024
#define MAX_EMAILS 10

struct Email {
    char subject[MAX_SUBJECT_SIZE];
    char message[MAX_MESSAGE_SIZE];
};

struct EmailCollection {
    struct Email emails[MAX_EMAILS];
    int count;
};

void displayWelcomeMessage() {
    printf("\nWelcome to Minimalist Email Client!\n\n");
}

int readIntInput() {
    int n;
    scanf("%d", &n);
    return n;
}

void readSubject(char* subject) {
    printf("Enter subject: ");
    scanf("%s", subject);
}

void readMessage(char* message) {
    printf("Enter message: ");
    scanf(" %[^\n]", message);
}

void composeEmail(struct EmailCollection* collection) {
    printf("---Compose Email---\n");
    if (collection->count < MAX_EMAILS) {
        readSubject(collection->emails[collection->count].subject);
        readMessage(collection->emails[collection->count].message);
        collection->count++;
        printf("Email sent!\n");
    } else {
        printf("You have reached the limit of emails that can be stored.\n");
    }
}

void displayEmails(struct EmailCollection* collection) {
    printf("---Emails---\n");
    if (collection->count == 0) {
        printf("You have no emails.\n");
    } else {
        for (int i = 0; i < collection->count; i++) {
            printf("Subject: %s\n", collection->emails[i].subject);
            printf("Message: %s\n\n", collection->emails[i].message);
        }
    }
}

void menu(struct EmailCollection* collection) {
    int choice;
    do {
        printf("\n---Menu---\n");
        printf("1. Compose Email\n");
        printf("2. Display Emails\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        choice = readIntInput();
        switch (choice) {
            case 1:
                composeEmail(collection);
                break;
            case 2:
                displayEmails(collection);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);
}

int main(int argc, char* argv[]) {
    struct EmailCollection emails = { .count = 0 };
    displayWelcomeMessage();
    menu(&emails);
    return 0;
}