//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int compare_emails(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void print_contact(contact c) {
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
}

int main() {
    int num_contacts;
    contact contacts[100];
    int i;

    printf("Enter number of contacts: ");
    scanf("%d", &num_contacts);

    for (i = 0; i < num_contacts; i++) {
        printf("Enter name for contact %d: ", i+1);
        scanf("%s", contacts[i].name);
        printf("Enter email for contact %d: ", i+1);
        scanf("%s", contacts[i].email);
    }

    qsort(contacts, num_contacts, sizeof(contact), compare_names);
    printf("Sorted by name:\n");
    for (i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    qsort(contacts, num_contacts, sizeof(contact), compare_emails);
    printf("\nSorted by email:\n");
    for (i = 0; i < num_contacts; i++) {
        print_contact(contacts[i]);
    }

    return 0;
}