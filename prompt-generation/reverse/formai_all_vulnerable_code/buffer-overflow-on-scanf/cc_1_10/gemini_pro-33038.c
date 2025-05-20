//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct contact {
    char name[50];
    char phone_number[20];
    char email[50];
} contact;

contact phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full!\n");
        return;
    }

    printf("Enter contact name: ");
    scanf(" %[^\n]%*c", phone_book[num_contacts].name);

    printf("Enter contact phone number: ");
    scanf(" %[^\n]%*c", phone_book[num_contacts].phone_number);

    printf("Enter contact email: ");
    scanf(" %[^\n]%*c", phone_book[num_contacts].email);

    num_contacts++;
}

void search_contact() {
    char search_name[50];

    printf("Enter contact name to search for: ");
    scanf(" %[^\n]%*c", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_number);
            printf("Email: %s\n", phone_book[i].email);
            return;
        }
    }

    printf("Contact not found!\n");
}

void edit_contact() {
    char search_name[50];

    printf("Enter contact name to edit: ");
    scanf(" %[^\n]%*c", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Contact found!\n");

            printf("Enter new contact name: ");
            scanf(" %[^\n]%*c", phone_book[i].name);

            printf("Enter new contact phone number: ");
            scanf(" %[^\n]%*c", phone_book[i].phone_number);

            printf("Enter new contact email: ");
            scanf(" %[^\n]%*c", phone_book[i].email);

            printf("Contact edited successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

void delete_contact() {
    char search_name[50];

    printf("Enter contact name to delete: ");
    scanf(" %[^\n]%*c", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("Contact found!\n");

            for (int j = i; j < num_contacts - 1; j++) {
                phone_book[j] = phone_book[j + 1];
            }

            num_contacts--;

            printf("Contact deleted successfully!\n");
            return;
        }
    }

    printf("Contact not found!\n");
}

void list_contacts() {
    printf("Contacts:\n");

    for (int i = 0; i < num_contacts; i++) {
        printf("%s\n", phone_book[i].name);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Edit contact\n");
        printf("4. Delete contact\n");
        printf("5. List contacts\n");
        printf("6. Exit\n");

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
                edit_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                list_contacts();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}