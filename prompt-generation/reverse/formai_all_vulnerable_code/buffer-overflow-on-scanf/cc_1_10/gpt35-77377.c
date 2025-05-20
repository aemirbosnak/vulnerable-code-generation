//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_PHONE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

Node* head = NULL;

void addContact(char name[], char email[], char phone[]) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    strncpy(newNode->contact.name, name, MAX_NAME_LEN);
    strncpy(newNode->contact.email, email, MAX_EMAIL_LEN);
    strncpy(newNode->contact.phone, phone, MAX_PHONE_LEN);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void removeContact(char name[]) {
    if (head == NULL) {
        printf("Contact list is empty!\n");
        return;
    }

    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->contact.name, name) == 0) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Contact not found!\n");
}

void printContacts() {
    if (head == NULL) {
        printf("Contact list is empty!\n");
        return;
    }

    Node* current = head;

    while (current != NULL) {
        printf("Name: %s\n", current->contact.name);
        printf("Email: %s\n", current->contact.email);
        printf("Phone: %s\n", current->contact.phone);
        printf("\n");
        current = current->next;
    }
}

int main() {
    char choice;
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN], phone[MAX_PHONE_LEN];

    printf("Welcome to the Mailing List Manager!\n");

    while (1) {
        printf("Please choose an option:\n");
        printf("1. Add contact\n");
        printf("2. Remove contact\n");
        printf("3. Print contacts\n");
        printf("4. Exit\n");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter email: ");
                scanf(" %[^\n]%*c", email);
                printf("Enter phone number: ");
                scanf(" %[^\n]%*c", phone);
                addContact(name, email, phone);
                printf("Contact added!\n");
                break;
            case '2':
                printf("Enter name: ");
                scanf(" %[^\n]%*c", name);
                removeContact(name);
                break;
            case '3':
                printContacts();
                break;
            case '4':
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}