//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[50];
    char email[50];
    char phone[20];
} contact;

contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact(char *name, char *email, char *phone) {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    strcpy(contacts[num_contacts].name, name);
    strcpy(contacts[num_contacts].email, email);
    strcpy(contacts[num_contacts].phone, phone);
    num_contacts++;
}

void print_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s - %s\n", contacts[i].name, contacts[i].email, contacts[i].phone);
    }
}

void delete_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            num_contacts--;
            printf("Contact deleted.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void find_contact(char *name) {
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Email: %s\n", contacts[i].email);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

int main() {
    int choice;
    char name[50], email[50], phone[20];

    while (1) {
        printf("\n1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Delete contact\n");
        printf("4. Find contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                printf("Enter phone: ");
                scanf("%s", phone);
                add_contact(name, email, phone);
                break;
            case 2:
                print_contacts();
                break;
            case 3:
                printf("Enter name of contact to delete: ");
                scanf("%s", name);
                delete_contact(name);
                break;
            case 4:
                printf("Enter name of contact to find: ");
                scanf("%s", name);
                find_contact(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}