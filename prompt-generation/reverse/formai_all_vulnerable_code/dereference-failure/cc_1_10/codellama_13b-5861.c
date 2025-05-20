//Code Llama-13B DATASET v1.0 Category: Mailing list manager ; Style: high level of detail
// mailing_list_manager.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

// Struct for storing email information
typedef struct {
    char *name;
    char *email;
} Email;

// Struct for storing list of emails
typedef struct {
    Email *emails;
    int num_emails;
} EmailList;

// Function to create a new email list
EmailList *create_email_list() {
    EmailList *list = (EmailList *)malloc(sizeof(EmailList));
    list->emails = (Email *)malloc(MAX_EMAILS * sizeof(Email));
    list->num_emails = 0;
    return list;
}

// Function to add an email to the list
void add_email(EmailList *list, char *name, char *email) {
    if (list->num_emails >= MAX_EMAILS) {
        printf("Error: Maximum number of emails reached.\n");
        return;
    }

    list->emails[list->num_emails].name = name;
    list->emails[list->num_emails].email = email;
    list->num_emails++;
}

// Function to remove an email from the list
void remove_email(EmailList *list, char *name) {
    int index = -1;
    for (int i = 0; i < list->num_emails; i++) {
        if (strcmp(list->emails[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: Email not found.\n");
        return;
    }

    for (int i = index; i < list->num_emails - 1; i++) {
        list->emails[i] = list->emails[i + 1];
    }
    list->num_emails--;
}

// Function to display the list of emails
void display_emails(EmailList *list) {
    for (int i = 0; i < list->num_emails; i++) {
        printf("%s (%s)\n", list->emails[i].name, list->emails[i].email);
    }
}

int main() {
    EmailList *list = create_email_list();

    add_email(list, "John", "john@example.com");
    add_email(list, "Jane", "jane@example.com");
    add_email(list, "Bob", "bob@example.com");

    remove_email(list, "Bob");

    display_emails(list);

    return 0;
}