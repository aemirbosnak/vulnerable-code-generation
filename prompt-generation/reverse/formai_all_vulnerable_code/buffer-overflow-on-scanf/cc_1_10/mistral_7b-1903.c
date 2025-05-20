//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    char phone[20];
    struct Node *next;
} Node;

Node *head = NULL;

void addContact(char name[], char phone[]) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = head;
    head = newNode;
}

Node *searchContact(char name[]) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void deleteContact(char name[]) {
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Contact not found.\n");
}

void displayContacts() {
    Node *current = head;
    printf("\nPhone Book:\n");
    while (current != NULL) {
        printf("%s: %s\n", current->name, current->phone);
        current = current->next;
    }
}

int main() {
    int choice;
    char name[50], phone[20];
    while (1) {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Contact\n");
        printf("2. Delete Contact\n");
        printf("3. Search Contact\n");
        printf("4. Display Contacts\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Phone Number: ");
                scanf("%s", phone);
                addContact(name, phone);
                break;
            case 2:
                printf("Enter Name to Delete: ");
                scanf("%s", name);
                deleteContact(name);
                break;
            case 3:
                printf("Enter Name to Search: ");
                scanf("%s", name);
                Node *found = searchContact(name);
                if (found != NULL) {
                    printf("Name: %s, Phone: %s\n", found->name, found->phone);
                } else {
                    printf("Contact not found.\n");
                }
                break;
            case 4:
                displayContacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}