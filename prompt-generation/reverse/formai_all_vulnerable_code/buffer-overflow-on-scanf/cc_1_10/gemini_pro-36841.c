//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: peaceful
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
}

void remove_user(char *name) {
    int i;

    for (i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            users[i].subscribed = 0;
            return;
        }
    }

    printf("Error: User not found.\n");
}

void add_email(char *subject, char *body) {
    if (num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    strcpy(emails[num_emails].subject, subject);
    strcpy(emails[num_emails].body, body);
    emails[num_emails].sent = 0;
    num_emails++;
}

void send_email(char *subject, char *body) {
    int i;

    for (i = 0; i < num_users; i++) {
        if (users[i].subscribed) {
            printf("To: %s <%s>\n", users[i].name, users[i].email);
            printf("Subject: %s\n", subject);
            printf("Body: %s\n\n", body);
        }
    }

    emails[num_emails - 1].sent = 1;
}

void print_help() {
    printf("Commands:\n");
    printf("add user <name> <email>\n");
    printf("remove user <name>\n");
    printf("add email <subject> <body>\n");
    printf("send email\n");
    printf("help\n");
    printf("quit\n");
}

int main() {
    char input[100];

    while (strcmp(input, "quit") != 0) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "add user") == 0) {
            char name[50];
            char email[50];

            scanf("%s %s", name, email);
            add_user(name, email);
        } else if (strcmp(input, "remove user") == 0) {
            char name[50];

            scanf("%s", name);
            remove_user(name);
        } else if (strcmp(input, "add email") == 0) {
            char subject[50];
            char body[1000];

            scanf("%s %[^\n]", subject, body);
            add_email(subject, body);
        } else if (strcmp(input, "send email") == 0) {
            send_email(emails[num_emails - 1].subject, emails[num_emails - 1].body);
        } else if (strcmp(input, "help") == 0) {
            print_help();
        }
    }

    return 0;
}