//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_EMAILS 10

typedef struct {
    char from[50];
    char subject[100];
    char body[200];
} Email;

Email stack[MAX_EMAILS];
int top = -1;

void push_email(Email email) {
    if (top >= MAX_EMAILS - 1) {
        printf("Your inbox is full! Keep shining!\n");
        return;
    }
    stack[++top] = email;
}

Email pop_email() {
    if (top < 0) {
        printf("Your inbox is empty! Keep shining and sending love!\n");
        Email empty_email = {"", "", ""};
        return empty_email;
    }
    return stack[top--];
}

void display_email(Email email) {
    printf("\nFrom: %s", email.from);
    printf("\nSubject: %s", email.subject);
    printf("\nBody:\n%s\n", email.body);
}

int main() {
    int choice;
    Email new_email;

    printf("Welcome to GratiMail! A simple and grateful email client.\n");

    while (true) {
        printf("\nSelect an option:\n1. Write a new email\n2. Read last email\n3. Delete last email\n0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Who is this email for? ");
                scanf("%s", new_email.from);
                printf("What's the subject? ");
                scanf("%s", new_email.subject);
                printf("Write your message:\n");
                scanf("%[^\n]", new_email.body);
                push_email(new_email);
                printf("Email sent with love! Keep shining!\n");
                break;
            case 2:
                if (top < 0) {
                    printf("Your inbox is empty! Keep shining and sending love!\n");
                    break;
                }
                display_email(pop_email());
                break;
            case 3:
                if (top < 0) {
                    printf("Your inbox is empty! Keep shining and sending love!\n");
                    break;
                }
                printf("Email deleted with gratitude.\n");
                top--;
                break;
            case 0:
                printf("Thanks for using GratiMail! Have a great day!\n");
                return 0;
            default:
                printf("Invalid option! Keep shining.\n");
        }
    }

    return 0;
}