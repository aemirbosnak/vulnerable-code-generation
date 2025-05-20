//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 20

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void print_menu() {
    printf("\n--- Phone Book Menu ---\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Exit\n");
}

void add_contact(Contact contacts[], int* current_contact) {
    if (*current_contact >= MAX_CONTACTS) {
        printf("Phone Book is Full. Unable to Add Contact.\n");
        return;
    }

    printf("Enter Contact Name: ");
    fgets(contacts[*current_contact].name, NAME_LENGTH, stdin);
    contacts[*current_contact].name[strcspn(contacts[*current_contact].name, "\n")] = '\0';

    printf("Enter Contact Phone Number: ");
    fgets(contacts[*current_contact].phone, PHONE_LENGTH, stdin);
    contacts[*current_contact].phone[strcspn(contacts[*current_contact].phone, "\n")] = '\0';

    (*current_contact)++;
}

void delete_contact(Contact contacts[], int* current_contact, char name[]) {
    int index = -1;

    for (int i = 0; i < *current_contact; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Contact Not Found.\n");
        return;
    }

    for (int i = index; i < *current_contact - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    (*current_contact)--;
}

void search_contact(Contact contacts[], int current_contact, char name[]) {
    for (int i = 0; i < current_contact; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact Not Found.\n");
}

void display_all_contacts(Contact contacts[], int current_contact) {
    printf("\nContacts:\n");

    for (int i = 0; i < current_contact; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int current_contact = 0;

    while (1) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(contacts, &current_contact);
                break;
            case 2: {
                char name[NAME_LENGTH];
                printf("Enter Name of Contact to Delete: ");
                scanf("%s", name);
                delete_contact(contacts, &current_contact, name);
                break;
            }
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter Name of Contact to Search: ");
                scanf("%s", name);
                search_contact(contacts, current_contact, name);
                break;
            }
            case 4:
                display_all_contacts(contacts, current_contact);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Option. Please Try Again.\n");
                break;
        }
    }

    return 0;
}