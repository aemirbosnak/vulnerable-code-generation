//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Define a linked list node
typedef struct node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct node *next;
} Node;

// Declare the head of the linked list
Node *head = NULL;

/**
 * Function to add a new subscriber to the mailing list
 */
void addSubscriber() {
    // Allocate memory for a new node
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->next = NULL;

    // Prompt the user for the name and email
    printf("Enter name: ");
    scanf("%s", newNode->name);
    printf("Enter email: ");
    scanf("%s", newNode->email);

    // If the list is empty, set the head to the new node
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse the list until the end and add the new node
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

/**
 * Function to remove a subscriber from the mailing list
 */
void removeSubscriber() {
    // Prompt the user for the email of the subscriber to remove
    char email[MAX_EMAIL_LENGTH];
    printf("Enter email: ");
    scanf("%s", email);

    // Traverse the list to find the node with the matching email
    Node *current = head;
    Node *previous = NULL;
    while (current != NULL && strcmp(current->email, email) != 0) {
        previous = current;
        current = current->next;
    }

    // If the node was found, remove it from the list
    if (current != NULL) {
        if (previous == NULL) {
            head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

/**
 * Function to print the entire mailing list
 */
void printMailingList() {
    Node *current = head;
    while (current != NULL) {
        printf("%s <%s>\n", current->name, current->email);
        current = current->next;
    }
}

/**
 * Main function to run the mailing list manager program.
 * Prompts the user to choose from a menu of options.
 */
int main() {
    int choice;
    do {
        printf("Choose an option:\n1. Add subscriber\n2. Remove subscriber\n3. Print mailing list\n4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                printMailingList();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    // Free the memory used by the linked list
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}