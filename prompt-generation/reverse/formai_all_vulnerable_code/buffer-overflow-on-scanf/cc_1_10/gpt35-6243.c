//FormAI DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_SUBJECT_LENGTH 50
#define MAX_BODY_LENGTH 1000

typedef struct Email {
    char sender[50];
    char receiver[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

Email inbox[MAX_EMAILS];
int num_emails = 0;

void show_inbox() {
    printf("\nINBOX\n\n");
    for (int i = 0; i < num_emails; i++) {
        printf("From: %s\n", inbox[i].sender);
        printf("Subject: %s\n", inbox[i].subject);
        printf("%s\n", inbox[i].body);
        printf("-----------------------------------\n");
    }
}

void send_email() {
    Email new_email;
    printf("Enter the receiver's email address: ");
    scanf("%s", new_email.receiver);
    printf("Enter the subject: ");
    scanf("%s", new_email.subject);
    printf("Enter your message: ");
    fgets(new_email.body, MAX_BODY_LENGTH, stdin);
    strcpy(new_email.sender, "youremail@domain.com");
    inbox[num_emails] = new_email;
    num_emails++;
    printf("\nSent!\n");
}

int main() {
    int option;
    printf("Welcome to the C Email Client!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. View inbox\n");
        printf("2. Send email\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                show_inbox();
                break;
            case 2:
                send_email();
                break;
            case 3:
                printf("\nGoodbye!");
                break;
            default:
                printf("\nInvalid option. Please choose again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}