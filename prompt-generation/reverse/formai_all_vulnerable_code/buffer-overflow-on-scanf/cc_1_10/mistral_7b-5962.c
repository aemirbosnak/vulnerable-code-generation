//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char address[100];
} Contact;

void searchContact(Contact contacts[], char name[]) {
    int i;
    for (i = 0; i < MAX_CONTACTS; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Address: %s\n", contacts[i].address);
            return;
        }
    }
    printf("Contact not found.\n");
}

void addContact(Contact contacts[], char name[], char phone[], char address[]) {
    if (MAX_CONTACTS == sizeof(contacts) / sizeof(Contact)) {
        printf("Phone book is full.\n");
        return;
    }

    strcpy(contacts[MAX_CONTACTS].name, name);
    strcpy(contacts[MAX_CONTACTS].phone, phone);
    strcpy(contacts[MAX_CONTACTS].address, address);

    printf("Contact added successfully.\n");
}

int main() {
    Contact phoneBook[MAX_CONTACTS];
    int choice;
    char name[50], phone[20], address[100];

    while (1) {
        printf("\n--- SHERLOCK HOLMES'S PHONE BOOK ---");
        printf("\n1. Add Contact\n2. Search Contact\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%s", phone);
                printf("Enter Address: ");
                scanf("%s", address);

                addContact(phoneBook, name, phone, address);
                break;
            case 2:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                searchContact(phoneBook, name);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}