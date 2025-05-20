//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phonebook is full!\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", phonebook[num_contacts].name);

    printf("Enter contact phone number: ");
    scanf("%s", phonebook[num_contacts].phone);

    num_contacts++;
}

void remove_contact() {
    int index;

    printf("Enter index of contact to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_contacts) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < num_contacts - 1; i++) {
        phonebook[i] = phonebook[i + 1];
    }

    num_contacts--;
}

void search_contact() {
    char name[MAX_NAME_LENGTH];

    printf("Enter contact name to search for: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }
}

void print_phonebook() {
    printf("Phonebook:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Search contact\n");
        printf("4. Print phonebook\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                print_phonebook();
                break;
            case 5:
                printf("Exiting phonebook...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}