//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void add_contact(Contact contacts[], int *num_contacts, const char *name, const char *phone);
void display_contacts(Contact contacts[], int num_contacts);
void search_contact(Contact contacts[], int num_contacts, const char *name);

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    while (1) {
        printf("\n1. Add contact\n2. Display contacts\n3. Search contact\n4. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                char name[NAME_LENGTH];
                char phone[PHONE_LENGTH];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                add_contact(contacts, &num_contacts, name, phone);
                break;
            }
        case 2:
            display_contacts(contacts, num_contacts);
            break;
        case 3:
            {
                char name[NAME_LENGTH];
                printf("Enter name to search: ");
                scanf("%s", name);
                search_contact(contacts, num_contacts, name);
                break;
            }
        case 4:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void add_contact(Contact contacts[], int *num_contacts, const char *name, const char *phone) {
    if (*num_contacts < MAX_CONTACTS) {
        strcpy(contacts[*num_contacts].name, name);
        strcpy(contacts[*num_contacts].phone, phone);
        (*num_contacts)++;
        printf("Contact added successfully!\n");
    } else {
        printf("Maximum number of contacts reached!\n");
    }
}

void display_contacts(Contact contacts[], int num_contacts) {
    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void search_contact(Contact contacts[], int num_contacts, const char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact found:\nName: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("\nContact not found!\n");
}