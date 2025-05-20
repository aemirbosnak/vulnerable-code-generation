//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone[20];
};

void add_contact(struct contact *contacts, int count, char *name, char *phone) {
    if (count < MAX_CONTACTS) {
        strcpy(contacts[count].name, name);
        strcpy(contacts[count].phone, phone);
        count++;
    } else {
        printf("Phone book is full.\n");
    }
}

void display_contacts(struct contact *contacts, int count) {
    printf("Phone book:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", contacts[i].name, contacts[i].phone);
    }
}

void search_contact(struct contact *contacts, int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found contact: %s - %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    struct contact contacts[MAX_CONTACTS];
    int count = 0;

    char choice;
    do {
        printf("\nPhone book menu:\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter name: ");
            char name[50];
            scanf("%s", name);
            printf("Enter phone number: ");
            char phone[20];
            scanf("%s", phone);
            add_contact(contacts, count, name, phone);
            break;
        case '2':
            if (count == 0) {
                printf("Phone book is empty.\n");
            } else {
                display_contacts(contacts, count);
            }
            break;
        case '3':
            printf("Enter name to search: ");
            char search_name[50];
            scanf("%s", search_name);
            search_contact(contacts, count, search_name);
            break;
        case '4':
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}