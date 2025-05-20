//FormAI DATASET v1.0 Category: Phone Book ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20
#define MAX_CONTACTS 100

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

Contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];

    printf("Enter contact name: ");
    scanf("%s", name);

    printf("Enter contact number: ");
    scanf("%s", number);

    Contact new_contact;
    strcpy(new_contact.name, name);
    strcpy(new_contact.number, number);

    phone_book[num_contacts++] = new_contact;

    printf("Contact added successfully!\n");
}

void print_contacts() {
    printf("Phone Book:\n");
    printf("-------------\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
    }

    printf("-------------\n");
}

void search_contact() {
    char query[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", query);

    int found = 0;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, query) == 0) {
            printf("%s: %s\n", phone_book[i].name, phone_book[i].number);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found.\n");
    }
}

void delete_contact() {
    char query[MAX_NAME_LEN];
    printf("Enter name to delete: ");
    scanf("%s", query);

    int found = 0;

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, query) == 0) {
            found = 1;

            for (int j = i; j < num_contacts - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }

            num_contacts--;
            printf("Contact deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    int choice = 0;

    while (1) {
        printf("Menu:\n");
        printf("1. Add contact\n");
        printf("2. Print contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                print_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}