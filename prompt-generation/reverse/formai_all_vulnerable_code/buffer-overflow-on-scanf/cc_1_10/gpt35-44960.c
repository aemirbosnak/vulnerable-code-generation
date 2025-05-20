//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

struct email_t {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

void add_email(struct email_t emails[], int *count);
void view_all_emails(struct email_t emails[], int count);
void search_by_name(struct email_t emails[], int count);

int main() {
    struct email_t emails[MAX_EMAILS];
    int count = 0;
    int option = 0;

    do {
        printf("\n1. Add email\n");
        printf("2. View all emails\n");
        printf("3. Search by name\n");
        printf("4. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_email(emails, &count);
                break;
            case 2:
                view_all_emails(emails, count);
                break;
            case 3:
                search_by_name(emails, count);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option entered. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

void add_email(struct email_t emails[], int *count) {
    if (*count >= MAX_EMAILS) {
        printf("Maximum number of emails reached.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", emails[*count].name);

    printf("Enter email: ");
    scanf("%s", emails[*count].email);

    printf("Email added successfully.\n");
    (*count)++;
}

void view_all_emails(struct email_t emails[], int count) {
    if (count == 0) {
        printf("No emails added yet.\n");
        return;
    }

    printf("All emails:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", emails[i].name, emails[i].email);
    }
}

void search_by_name(struct email_t emails[], int count) {
    if (count == 0) {
        printf("No emails added yet.\n");
        return;
    }

    char search_name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(emails[i].name, search_name) == 0) {
            printf("%s - %s\n", emails[i].name, emails[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No matches found.\n");
    }
}