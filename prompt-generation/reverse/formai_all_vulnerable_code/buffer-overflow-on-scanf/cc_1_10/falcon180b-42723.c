//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[15];
} Contact;

void add_contact(Contact phonebook[], int count) {
    printf("Enter name: ");
    scanf("%s", phonebook[count].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[count].phone);

    printf("Contact added successfully.\n");
}

void view_contacts(Contact phonebook[], int count) {
    printf("Name\t\tPhone Number\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact(Contact phonebook[], int count) {
    char name[50];

    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nPhone Number: %s\n", phonebook[i].name, phonebook[i].phone);
            return;
        }
    }

    printf("Contact not found.\n");
}

void delete_contact(Contact phonebook[], int count) {
    char name[50];

    printf("Enter name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                strcpy(phonebook[j].name, phonebook[j + 1].name);
                strcpy(phonebook[j].phone, phonebook[j + 1].phone);
            }

            printf("Contact deleted successfully.\n");
            count--;
            break;
        }
    }
}

int main() {
    Contact phonebook[MAX_CONTACTS];
    int count = 0;

    while (1) {
        printf("\nPhone Book\n");
        printf("1. Add Contact\n2. View Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count >= MAX_CONTACTS) {
                printf("Phone book is full.\n");
            } else {
                add_contact(phonebook, count);
                count++;
            }
            break;

        case 2:
            view_contacts(phonebook, count);
            break;

        case 3:
            search_contact(phonebook, count);
            break;

        case 4:
            delete_contact(phonebook, count);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}