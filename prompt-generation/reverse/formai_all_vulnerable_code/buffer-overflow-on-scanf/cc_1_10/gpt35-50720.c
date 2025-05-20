//FormAI DATASET v1.0 Category: Mailing list manager ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char email[MAX_EMAIL_LENGTH];
} MailingList;

int num_emails = 0;

void add_email(MailingList *list, char *email) {
    if (num_emails < MAX_EMAILS) {
        strcpy(list[num_emails].email, email);
        num_emails++;
        printf("Email added to list: %s\n", email);
    } else {
        printf("Mailing list is full.\n");
    }
}

void remove_email(MailingList *list, char *email) {
    int index = -1;
    for (int i = 0; i < num_emails; i++) {
        if (strcmp(list[i].email, email) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < num_emails - 1; i++) {
            strcpy(list[i].email, list[i+1].email);
        }
        num_emails--;
        printf("Email removed from list: %s\n", email);
    } else {
        printf("Email not found in list.\n");
    }
}

void print_list(MailingList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < num_emails; i++) {
        printf("%d: %s\n", i+1, list[i].email);
    }
}

int main() {
    MailingList list[MAX_EMAILS];

    char command[10];
    char email[MAX_EMAIL_LENGTH];

    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("Enter command (add, remove, print, exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            add_email(list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            remove_email(list, email);
        } else if (strcmp(command, "print") == 0) {
            print_list(list);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting Mailing List Manager...\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}