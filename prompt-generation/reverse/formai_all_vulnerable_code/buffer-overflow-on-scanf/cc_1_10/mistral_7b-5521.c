//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct Contact {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node *next;
} Node;

Node *head = NULL;

void add_contact() {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory error!\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", new_node->contact.name);

    printf("Enter contact phone number: ");
    scanf("%s", new_node->contact.phone);

    new_node->next = head;
    head = new_node;

    printf("Contact added successfully!\n");
}

void remove_contact() {
    Node *current = head;
    Node *previous = NULL;

    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Enter contact name to remove: ");
    char name[NAME_LENGTH];
    scanf("%s", name);

    while (current != NULL) {
        if (strcmp(current->contact.name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Contact removed successfully!\n");
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Contact not found!\n");
}

void search_contact() {
    Node *current = head;

    if (head == NULL) {
        printf("Phone book is empty!\n");
        return;
    }

    printf("Enter contact name to search for: ");
    char name[NAME_LENGTH];
    scanf("%s", name);

    while (current != NULL) {
        if (strcmp(current->contact.name, name) == 0) {
            printf("Name: %s\n", current->contact.name);
            printf("Phone: %s\n", current->contact.phone);
            return;
        }
        current = current->next;
    }

    printf("Contact not found!\n");
}

void print_menu() {
    printf("\n---- Phone Book Menu ----\n");
    printf("1. Add Contact\n");
    printf("2. Remove Contact\n");
    printf("3. Search Contact\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}