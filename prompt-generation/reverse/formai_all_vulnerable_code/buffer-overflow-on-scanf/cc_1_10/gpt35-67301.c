//FormAI DATASET v1.0 Category: Email Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_EMAILS 100
#define MAX_SUBJECT_SIZE 50
#define MAX_BODY_SIZE 500

typedef struct {
    char subject[MAX_SUBJECT_SIZE];
    char body[MAX_BODY_SIZE];
    char to[MAX_INPUT_SIZE];
    char from[MAX_INPUT_SIZE];
} Email;

Email inbox[MAX_EMAILS];
int num_emails = 0;

void print_menu() {
    printf("1. Compose Email\n2. View Inbox\n3. Exit\n");
}

void compose_email() {
    Email new_email;

    printf("Enter To: ");
    fgets(new_email.to, MAX_INPUT_SIZE, stdin);

    printf("Enter From: ");
    fgets(new_email.from, MAX_INPUT_SIZE, stdin);

    printf("Enter Subject: ");
    fgets(new_email.subject, MAX_SUBJECT_SIZE, stdin);

    printf("Enter Body: ");
    fgets(new_email.body, MAX_BODY_SIZE, stdin);

    inbox[num_emails++] = new_email;
    printf("Email Sent Successfully!\n");
}

void view_inbox() {
    printf("Inbox:\n");

    for (int i = 0; i < num_emails; i++) {
        printf("To: %s", inbox[i].to);
        printf("From: %s", inbox[i].from);
        printf("Subject: %s", inbox[i].subject);
        printf("Body: %s\n", inbox[i].body);
    }
}

int main() {
    int choice;

    do {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // consume newline character left in the stdin buffer after scanf

        switch(choice) {
            case 1:
                compose_email();
                printf("\n");
                break;
            case 2:
                view_inbox();
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice. Try Again.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}