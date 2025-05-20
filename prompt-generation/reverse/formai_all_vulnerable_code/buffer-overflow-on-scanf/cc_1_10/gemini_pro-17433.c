//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone_number[20];
} Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts == MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", phone_book[num_contacts].name);

    printf("Enter contact phone number: ");
    scanf("%s", phone_book[num_contacts].phone_number);

    num_contacts++;
}

void search_contact() {
    char name[50];

    printf("Enter contact name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            return;
        }
    }

    printf("Contact not found.\n");
}

void remove_contact() {
    char name[50];

    printf("Enter contact name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            for (int j = i + 1; j < num_contacts; j++) {
                phone_book[j - 1] = phone_book[j];
            }
            num_contacts--;
            printf("Contact removed.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void print_all_contacts() {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add contact\n2. Search contact\n3. Remove contact\n4. Print all contacts\n5. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                remove_contact();
                break;
            case 4:
                print_all_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}