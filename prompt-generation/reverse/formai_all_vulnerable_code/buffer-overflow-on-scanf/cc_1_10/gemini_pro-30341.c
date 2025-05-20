//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_EMAILS 1000

typedef struct {
    char name[50];
    char email[50];
    int subscribed;
} user;

typedef struct {
    char subject[50];
    char body[1000];
    int sent;
} email;

user users[MAX_USERS];
email emails[MAX_EMAILS];

int num_users = 0;
int num_emails = 0;

void add_user(char *name, char *email) {
    if (num_users >= MAX_USERS) {
        printf("Error: Maximum number of users reached.\n");
        return;
    }

    strcpy(users[num_users].name, name);
    strcpy(users[num_users].email, email);
    users[num_users].subscribed = 1;

    num_users++;

    printf("User added successfully.\n");
}

void remove_user(char *name) {
    int i;

    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            break;
        }
    }

    if (i == num_users) {
        printf("Error: User not found.\n");
        return;
    }

    for (; i < num_users - 1; i++) {
        users[i] = users[i + 1];
    }

    num_users--;

    printf("User removed successfully.\n");
}

void send_email(char *subject, char *body) {
    int i;

    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].sent = 0;

    num_emails++;

    printf("Email sent successfully.\n");
}

void print_users() {
    int i;

    printf("Users:\n");
    for (i = 0; i < num_users; i++) {
        printf(" - %s (%s)\n", users[i].name, users[i].email);
    }
}

void print_emails() {
    int i;

    printf("Emails:\n");
    for (i = 0; i < num_emails; i++) {
        printf(" - %s\n", emails[i].subject);
    }
}

int main() {
    int choice;
    char name[50];
    char email[50];
    char subject[50];
    char body[1000];

    while (1) {
        printf("Mailing List Manager\n");
        printf("1. Add user\n");
        printf("2. Remove user\n");
        printf("3. Send email\n");
        printf("4. Print users\n");
        printf("5. Print emails\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                add_user(name, email);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                remove_user(name);
                break;
            case 3:
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter body: ");
                scanf("%s", body);
                send_email(subject, body);
                break;
            case 4:
                print_users();
                break;
            case 5:
                print_emails();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}