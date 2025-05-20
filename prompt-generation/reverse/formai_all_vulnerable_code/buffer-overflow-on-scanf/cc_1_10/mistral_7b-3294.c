//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Email {
    char subject[100];
    char sender[50];
    char body[500];
    struct Email *next;
} Email;

Email *emails = NULL;
int num_emails = 0;

void add_email(char *subject, char *sender, char *body) {
    Email *new_email = (Email *) malloc(sizeof(Email));
    strcpy(new_email->subject, subject);
    strcpy(new_email->sender, sender);
    strcpy(new_email->body, body);
    new_email->next = emails;
    emails = new_email;
    num_emails++;
}

void delete_email(int index) {
    if (index < 0 || index >= num_emails) {
        printf("Invalid email index\n");
        return;
    }

    Email *current = emails;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    Email *to_delete = current->next;
    current->next = to_delete->next;
    free(to_delete);
    num_emails--;
}

void display_emails() {
    printf("\nEmail List:\n");
    Email *current = emails;
    for (int i = 0; i < num_emails; i++) {
        printf("%d. Subject: %s, Sender: %s\n", i + 1, current->subject, current->sender);
        current = current->next;
    }
}

int main() {
    char cmd[50], subject[100], sender[50], body[500];
    int choice, index;

    while (1) {
        printf("\nEmail Client\n1. Add Email\n2. Delete Email\n3. Display Emails\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter subject: ");
                scanf("%s", subject);
                printf("Enter sender: ");
                scanf("%s", sender);
                printf("Enter body: ");
                scanf("%[^\n]s", body);
                add_email(subject, sender, body);
                break;
            case 2:
                printf("Enter email index to delete: ");
                scanf("%d", &index);
                delete_email(index);
                break;
            case 3:
                display_emails();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}