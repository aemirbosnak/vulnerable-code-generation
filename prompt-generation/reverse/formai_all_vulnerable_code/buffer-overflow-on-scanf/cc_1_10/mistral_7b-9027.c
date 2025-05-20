//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50

typedef struct {
    char name[50];
    char phone[20];
    int index;
} Contact;

Contact contacts[MAX_CONTACTS];
int count = 0;

void print_menu() {
    printf("\n============= Phone Book =============\n");
    printf("1. Add a contact\n");
    printf("2. Search for a contact\n");
    printf("3. Delete a contact\n");
    printf("4. Display all contacts\n");
    printf("5. Exit\n");
}

void add_contact() {
    if (count >= MAX_CONTACTS) {
        printf("Phone book is full. Cannot add a contact.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", contacts[count].name);

    printf("Enter contact phone number: ");
    scanf("%s", contacts[count].phone);

    contacts[count].index = count;
    count++;

    printf("Contact added successfully!\n");
}

int search_contact(char name[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return contacts[i].index;
        }
    }

    printf("Contact not found.\n");
    return -1;
}

void delete_contact(int index) {
    if (index < 0 || index >= count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    count--;

    printf("Contact deleted successfully!\n");
}

void display_all() {
    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n============= Phone Book =============\n");
    printf("Index | Name            | Phone\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d | %s | %s\n", i, contacts[i].name, contacts[i].phone);
    }
}

int main() {
    int choice;
    char name[50];
    int index;

    printf("============= Grateful Phone Book =============\n");
    printf("Welcome to the phone book program. I'm here to help you manage your contacts.\n");

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                printf("Enter contact name to search: ");
                scanf("%s", name);
                index = search_contact(name);
                if (index != -1) {
                    printf("Contact found at index %d.\n", index);
                }
                break;
            case 3:
                printf("Enter contact index to delete: ");
                scanf("%d", &index);
                delete_contact(index);
                break;
            case 4:
                display_all();
                break;
            case 5:
                printf("Thank you for using the phone book program. Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}