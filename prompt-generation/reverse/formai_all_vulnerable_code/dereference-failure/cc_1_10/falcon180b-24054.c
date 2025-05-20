//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// Node structure for linked list
typedef struct node {
    char name[50];
    char number[15];
    struct node* next;
} Node;

// Function to add a new contact to the phone book
void add_contact(Node** head) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    printf("Enter name: ");
    scanf("%s", new_node->name);
    printf("Enter phone number: ");
    scanf("%s", new_node->number);
    new_node->next = *head;
    *head = new_node;
    printf("Contact added successfully.\n");
}

// Function to search for a contact in the phone book
Node* search_contact(Node* head, char* name) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to delete a contact from the phone book
void delete_contact(Node** head, char* name) {
    Node* current = *head;
    Node* previous = NULL;
    while (current!= NULL && strcmp(current->name, name)!= 0) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Contact not found.\n");
    } else {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        printf("Contact deleted successfully.\n");
    }
}

// Function to display all contacts in the phone book
void display_contacts(Node* head) {
    printf("Name\tPhone Number\n");
    Node* current = head;
    while (current!= NULL) {
        printf("%s\t%s\n", current->name, current->number);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Search contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(&head);
                break;
            case 2:
                printf("Enter name to search: ");
                char name[50];
                scanf("%s", name);
                Node* result = search_contact(head, name);
                if (result!= NULL) {
                    printf("Name: %s\nPhone Number: %s\n", result->name, result->number);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 3:
                printf("Enter name to delete: ");
                char name_to_delete[50];
                scanf("%s", name_to_delete);
                delete_contact(&head, name_to_delete);
                break;
            case 4:
                display_contacts(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);
    return 0;
}