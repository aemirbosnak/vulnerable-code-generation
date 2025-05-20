//FormAI DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 12
#define MAX_CONTACTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

Contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

int menu() {
    int choice;
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Print all contacts\n");
    printf("4. Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    return choice;
}

int add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phonebook is full\n");
        return 0;
    }
    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);
    printf("Enter phone number: ");
    scanf("%s", new_contact.phone);
    phonebook[num_contacts] = new_contact;
    num_contacts++;
    printf("Contact added\n");
    return 1;
}

int search_contact() {
    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(search_name, phonebook[i].name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone: %s\n", phonebook[i].phone);
            return 1;
        }
    }
    printf("Contact not found\n");
    return 0;
}

void print_all() {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Phone: %s\n", phonebook[i].phone);
    }
}

int main() {
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                print_all();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}