//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAILS][MAX_NAME_LENGTH];
    int num_emails;
} contact;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

int compare_emails(const void *a, const void *b) {
    return strcmp(*(char **) a, *(char **) b);
}

void add_email(contact *c) {
    printf("Enter email address: ");
    scanf("%s", c->email[c->num_emails]);
    c->num_emails++;
}

int main() {
    contact contacts[MAX_EMAILS];
    int num_contacts = 0;

    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);
    num_contacts++;

    while (num_contacts < MAX_EMAILS) {
        printf("Enter another contact name? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Enter contact name: ");
            scanf("%s", contacts[num_contacts].name);
            num_contacts++;
        } else {
            break;
        }
    }

    qsort(contacts, num_contacts, sizeof(contact), compare_names);

    for (int i = 0; i < num_contacts; i++) {
        printf("Contact %d:\n", i+1);
        printf("Name: %s\n", contacts[i].name);

        qsort(contacts[i].email, contacts[i].num_emails, sizeof(char*), compare_emails);

        printf("Email addresses:\n");
        for (int j = 0; j < contacts[i].num_emails; j++) {
            printf("%s\n", contacts[i].email[j]);
        }
    }

    return 0;
}