//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LEN 100
#define MAX_NAME_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

contact *create_contact(char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->email, email);
    return new_contact;
}

void print_contact(contact *contact) {
    printf("Name: %s\nEmail: %s\n", contact->name, contact->email);
}

int compare_contacts(contact *a, contact *b) {
    return strcmp(a->name, b->name);
}

void sort_contacts(contact *contacts, int num_contacts) {
    qsort(contacts, num_contacts, sizeof(contact), compare_contacts);
}

int main() {
    int num_contacts = 0;
    contact *contacts = NULL;

    printf("Enter number of contacts: ");
    scanf("%d", &num_contacts);

    contacts = (contact *)malloc(num_contacts * sizeof(contact));

    for (int i = 0; i < num_contacts; i++) {
        printf("Enter name and email for contact %d:\n", i+1);
        scanf(" %[^\n]", contacts[i].name);
        contacts[i].name[strcspn(contacts[i].name, "\n")] = '\0';
        scanf(" %[^\n]", contacts[i].email);
        contacts[i].email[strcspn(contacts[i].email, "\n")] = '\0';
    }

    sort_contacts(contacts, num_contacts);

    printf("Sorted contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        print_contact(&contacts[i]);
    }

    free(contacts);
    return 0;
}