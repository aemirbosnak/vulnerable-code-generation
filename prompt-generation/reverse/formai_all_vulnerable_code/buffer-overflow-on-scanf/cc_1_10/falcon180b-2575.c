//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 30
#define MAX_PHONE_NUMBER_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
} contact;

contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void print_menu() {
    printf("\n");
    printf("1. Add contact\n");
    printf("2. Search contact\n");
    printf("3. Print all contacts\n");
    printf("4. Exit\n");
    printf("\n");
}

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phone_book[num_contacts].name);

    printf("Enter phone number: ");
    scanf("%s", phone_book[num_contacts].phone_number);

    num_contacts++;
    printf("Contact added successfully.\n");
}

void search_contact() {
    printf("Enter name to search: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
            found = 1;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void print_all_contacts() {
    if (num_contacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("Phone book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                print_all_contacts();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}