//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

struct Email {
    char sender[MAX];
    char recipient[MAX];
    char subject[MAX];
    char message[MAX];
};

struct Email inbox[MAX];
int emails = 0;

void receiveEmail(char sender[], char recipient[], char subject[], char message[]) {
    if(emails == MAX) {
        printf("Inbox is full!\n");
        return;
    }
    strcpy(inbox[emails].sender, sender);
    strcpy(inbox[emails].recipient, recipient);
    strcpy(inbox[emails].subject, subject);
    strcpy(inbox[emails].message, message);
    emails++;
    printf("Email received!\n");
}

void readEmail() {
    int i;
    if(emails == 0) {
        printf("Inbox is empty!\n");
        return;
    }
    for(i = 0; i < emails; i++) {
        printf("\nEmail %d:\nSender: %s\nRecipient: %s\nSubject: %s\nMessage: %s\n", i+1, inbox[i].sender, inbox[i].recipient, inbox[i].subject, inbox[i].message);
    }
}

int main() {
    printf("Welcome to the Post-Apocalyptic Email Client!\n");
    printf("Please enter your username: ");
    char username[MAX];
    fgets(username, MAX, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Logged in as %s\n", username);

    while(1) {
        printf("\nPlease choose an option:\n1. Receive Email\n2. Read Email\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); // consumes newline character after scanf
        if(choice == 1) {
            char sender[MAX], recipient[MAX], subject[MAX], message[MAX];
            printf("Enter sender name: ");
            fgets(sender, MAX, stdin);
            sender[strcspn(sender, "\n")] = 0;
            printf("Enter recipient name: ");
            fgets(recipient, MAX, stdin);
            recipient[strcspn(recipient, "\n")] = 0;
            printf("Enter subject: ");
            fgets(subject, MAX, stdin);
            subject[strcspn(subject, "\n")] = 0;
            printf("Enter message: ");
            fgets(message, MAX, stdin);
            message[strcspn(message, "\n")] = 0;
            receiveEmail(sender, recipient, subject, message);
        }
        else if(choice == 2) {
            readEmail();
        }
        else if(choice == 3) {
            printf("Exiting...\n");
            exit(0);
        }
        else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}