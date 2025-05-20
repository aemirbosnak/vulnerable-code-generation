//FormAI DATASET v1.0 Category: Email Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BODY_LENGTH 500
#define MAX_SUBJECT_LENGTH 100

typedef struct email {
    char sender[50];
    char recipient[50];
    char subject[MAX_SUBJECT_LENGTH];
    char body[MAX_BODY_LENGTH];
} Email;

void print_menu();
void send_email();
void view_inbox();

int main() {
    int option;
    do {
        print_menu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                send_email();
                break;
            case 2:
                view_inbox();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option, try again.\n");
        }
    } while (1);
    
    return 0;
}

void print_menu() {
    printf("----------------------------\n");
    printf("      EMAIL CLIENT MENU     \n");
    printf("----------------------------\n");
    printf("1 - Send Email\n");
    printf("2 - View Inbox\n");
    printf("3 - Exit\n");
}

void send_email() {
    Email* email = (Email*) malloc(sizeof(Email));
    printf("Enter sender email: ");
    scanf("%s", email->sender);
    printf("Enter recipient email: ");
    scanf("%s", email->recipient);
    printf("Enter email subject: ");
    scanf("%s", email->subject);
    printf("Enter email body: ");
    scanf("%s", email->body);

    printf("\nEmail Sent!\n");

    free(email);
}

void view_inbox() {
    printf("Fetching emails...\n");
    printf("No emails found. Try again later.\n");
}