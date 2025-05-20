//FormAI DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[30];
    char phone_num[11];
    char email[50];
};

void add_contact(struct contact *contacts, int *num_contacts) {
    printf("Enter name: ");
    scanf(" %[^\n]s", contacts[*num_contacts].name);
    printf("Enter phone number: ");
    scanf(" %s", contacts[*num_contacts].phone_num);
    printf("Enter email address: ");
    scanf(" %s", contacts[*num_contacts].email);
    (*num_contacts)++;
}

void search_contact(struct contact *contacts, int num_contacts) {
    char name[30];
    printf("Enter name: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone Number: %s\n", contacts[i].phone_num);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    printf("Contact not found.\n");
}

void display_contacts(struct contact *contacts, int num_contacts) {
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d) %s, %s, %s\n", i+1, contacts[i].name, contacts[i].phone_num, contacts[i].email);
    }
}

int main() {
    struct contact contacts[50];
    int num_contacts = 0;
    int choice;
    while (1) {
        printf("Menu:\n");
        printf("1) Add contact\n");
        printf("2) Search contact\n");
        printf("3) Display contacts\n");
        printf("4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                search_contact(contacts, num_contacts);
                break;
            case 3:
                display_contacts(contacts, num_contacts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}