//FormAI DATASET v1.0 Category: Phone Book ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// contact struct holds the contact details
struct contact {
    char name[50];
    char phone_num[15];
};

// function to display the main menu
void display_menu() {
    printf("Phone Book\n");
    printf("1. Add contact\n");
    printf("2. Display all contacts\n");
    printf("3. Search contact by name\n");
    printf("4. Exit\n");
}

// function to add a new contact
void add_contact(struct contact *contacts, int *num_contacts) {
    printf("Enter name: ");
    scanf("%s", contacts[*num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*num_contacts].phone_num);
    (*num_contacts)++;
}

// function to display all contacts
void display_contacts(struct contact *contacts, int num_contacts) {
    printf("Name\t\tPhone Number\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t\t%s\n", contacts[i].name, contacts[i].phone_num);
    }
}

// function to search for a contact by name
void search_contact(struct contact *contacts, int num_contacts) {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name:\t\t%s\nPhone Number:\t%s\n", contacts[i].name, contacts[i].phone_num);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    struct contact *contacts = malloc(100 * sizeof(struct contact));
    int num_contacts = 0;
    
    while (1) {
        display_menu();
        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(contacts, &num_contacts);
                break;
            case 2:
                display_contacts(contacts, num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                free(contacts);
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}