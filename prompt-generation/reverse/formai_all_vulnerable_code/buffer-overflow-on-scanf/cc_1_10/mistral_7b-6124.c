//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void print_menu();
Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter contact name: ");
    fgets(contacts[num_contacts].name, NAME_LENGTH, stdin);
    contacts[num_contacts].name[strcspn(contacts[num_contacts].name, "\n")] = '\0';

    printf("Enter contact phone number: ");
    fgets(contacts[num_contacts].phone, PHONE_LENGTH, stdin);
    contacts[num_contacts].phone[strcspn(contacts[num_contacts].phone, "\n")] = '\0';

    num_contacts++;
    printf("Contact added successfully.\n");
}

void search_contact() {
    char search_name[NAME_LENGTH];

    printf("Enter contact name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Contact found:\nName: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                printf("Exiting phone book program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void print_menu() {
    printf("\nPhone Book Program\n");
    printf("1. Add a new contact\n");
    printf("2. Search for a contact\n");
    printf("3. Exit\n");
}