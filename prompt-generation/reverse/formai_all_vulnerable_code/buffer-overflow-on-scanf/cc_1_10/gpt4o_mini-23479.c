//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAILS 100
#define MAX_LENGTH 100

typedef struct {
    char emails[MAX_MAILS][MAX_LENGTH];
    int count;
} MailList;

void add_email(MailList *list, const char *email) {
    if (list->count < MAX_MAILS) {
        strncpy(list->emails[list->count++], email, MAX_LENGTH);
        printf("Added: %s\n", email);
    } else {
        printf("Mailing list is full!\n");
    }
}

void remove_email(MailList *list, const char *email) {
    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            // Shift emails down to remove the selected email
            for (int j = i; j < list->count - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->count--;
            printf("Removed: %s\n", email);
            return;
        }
    }
    printf("Email not found: %s\n", email);
}

void display_emails(const MailList *list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: %s\n", i + 1, list->emails[i]);
    }
}

int main() {
    MailList list = { .count = 0 };
    char command[10];
    char email[MAX_LENGTH];

    printf("Welcome to the Simple Mailing List Manager!\n");

    while (1) {
        printf("Enter command (add/remove/display/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter email to add: ");
            scanf("%s", email);
            add_email(&list, email);
        } else if (strcmp(command, "remove") == 0) {
            printf("Enter email to remove: ");
            scanf("%s", email);
            remove_email(&list, email);
        } else if (strcmp(command, "display") == 0) {
            display_emails(&list);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    return 0;
}