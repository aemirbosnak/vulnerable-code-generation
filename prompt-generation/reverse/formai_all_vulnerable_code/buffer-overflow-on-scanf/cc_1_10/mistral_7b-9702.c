//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 10

typedef struct {
    char name[50];
    char phone[20];
} Contact;

Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phone book is full.\n");
        return;
    }
    printf("Enter contact name: ");
    scanf("%s", contacts[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[num_contacts].phone);
    num_contacts++;
}

void display_contacts() {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }
    printf("\nContacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%d. %s - %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void search_contact() {
    char name[50];
    int found = 0;
    printf("Enter contact name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Contact found: %s - %s\n", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void delete_contact() {
    char name[50];
    int index = -1;
    printf("Enter contact name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Contact not found.\n");
        return;
    }
    for (int i = index; i < num_contacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }
    num_contacts--;
}

int main() {
    int choice;
    while (1) {
        printf("\nPhone book menu:\n1. Add contact\n2. Display contacts\n3. Search contact\n4. Delete contact\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
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
                printf("Invalid choice.\n");
        }
    }
    return 0;
}