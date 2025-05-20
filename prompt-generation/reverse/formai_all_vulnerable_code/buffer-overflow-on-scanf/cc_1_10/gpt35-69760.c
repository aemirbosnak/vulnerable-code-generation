//FormAI DATASET v1.0 Category: Mailing list manager ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_EMAIL_LENGTH 50
#define MAX_NAME_LENGTH 20

struct Email {
    char name[MAX_NAME_LENGTH];
    char address[MAX_EMAIL_LENGTH];
};

struct MailingList {
    struct Email emails[MAX_EMAILS];
    int num_emails;
};

void add_email(struct MailingList *list, char *name, char *address) {
    if (list->num_emails < MAX_EMAILS) {
        strcpy(list->emails[list->num_emails].name, name);
        strcpy(list->emails[list->num_emails].address, address);
        list->num_emails++;
    } else {
        printf("Max number of emails reached.\n");
    }
}

void print_list(struct MailingList list) {
    printf("Mailing List:\n");
    for (int i = 0; i < list.num_emails; i++) {
        printf("%s - %s\n", list.emails[i].name, list.emails[i].address);
    }
}

int main() {
    struct MailingList list = {0};
    char name[MAX_NAME_LENGTH];
    char address[MAX_EMAIL_LENGTH];
    char choice;

    printf("Mailing List Manager\n");

    do {
        printf("\nOptions:\n");
        printf("1. Add Email\n");
        printf("2. Print List\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter address: ");
                scanf("%s", address);
                add_email(&list, name, address);
                break;
            case '2':
                print_list(list);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != '3');

    return 0;
}