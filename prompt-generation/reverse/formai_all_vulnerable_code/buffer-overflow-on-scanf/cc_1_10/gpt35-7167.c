//FormAI DATASET v1.0 Category: Mailing list manager ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
    char name[MAX_LEN];
    char email[MAX_LEN];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;
int size = 0;

void insertContact() {
    Contact newContact;
    printf("Enter Contact Name: ");
    scanf("%s", newContact.name);
    printf("Enter Email: ");
    scanf("%s", newContact.email);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->contact = newContact;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
    printf("Successfully added %s to the mailing list!\n", newContact.name);
}

void deleteContact() {
    char name[MAX_LEN];
    printf("Enter the name of the Contact you want to remove: ");
    scanf("%s", name);

    if (size == 0) {
        printf("The mailing list is empty!\n");
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->contact.name, name) == 0) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            if (curr == tail) {
                tail = prev;
            }
            free(curr);
            size--;
            printf("Successfully removed %s from the mailing list!\n", name);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("%s is not in the mailing list!\n", name);
}


void printList() {
    if (size == 0) {
        printf("The mailing list is empty!\n");
        return;
    }

    printf("Contact Name\t\t\tEmail\n");
    printf("-----------------------------------------\n");

    Node* curr = head;
    while (curr != NULL) {
        printf("%-30s\t\t%s\n", curr->contact.name, curr->contact.email);
        curr = curr->next;
    }
}

void main() {
    printf("Welcome to the Mailing List Manager!\n");
    printf("------------------------------------\n");
    while (1) {
        printf("\nWhat would you like to do? (Enter '1', '2', '3', or '4')\n");
        printf("1. Add a Contact\n");
        printf("2. Remove a Contact\n");
        printf("3. View the Mailing List\n");
        printf("4. Exit Program\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Thank you for using the Mailing List Manager!\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1-4.\n");
        }
    }
}