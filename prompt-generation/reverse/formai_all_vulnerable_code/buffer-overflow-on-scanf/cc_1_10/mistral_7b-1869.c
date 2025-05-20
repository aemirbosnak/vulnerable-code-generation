//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

typedef struct Node {
    Contact data;
    struct Node *next;
} Node;

Node *head = NULL;

void addContact(Contact contact) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory error! Cannot add contact.\n");
        return;
    }

    newNode->data = contact;
    newNode->next = head;
    head = newNode;
}

void searchContact(char name[]) {
    Node *current = head;

    if (head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            printf("Name: %s\nPhone: %s\n", current->data.name, current->data.phone);
            return;
        }
        current = current->next;
    }

    printf("Contact not found.\n");
}

void displayContacts() {
    Node *current = head;

    if (head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }

    printf("Phonebook:\n");

    while (current != NULL) {
        printf("Name: %s\nPhone: %s\n", current->data.name, current->data.phone);
        current = current->next;
    }
}

int main() {
    char command[10], name[50], phone[15];

    while (1) {
        printf("\nPhonebook Menu:\n1. Add Contact\n2. Search Contact\n3. Display All Contacts\n4. Exit\nEnter your command: ");
        scanf("%s", command);

        switch (command[0]) {
            case '1':
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);

                Contact newContact = {name, phone};
                addContact(newContact);
                break;
            case '2':
                printf("Enter name to search: ");
                scanf("%s", name);
                searchContact(name);
                break;
            case '3':
                displayContacts();
                break;
            case '4':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}