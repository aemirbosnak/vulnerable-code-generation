//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store a mailing list node
typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Function to insert a new node at the end of the list
void insert(Node** head) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter the name of the recipient: ");
    scanf("%s", newNode->name);

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

// Function to traverse the list and print the names of all recipients
void traverse(Node* head) {
    while (head) {
        printf("%s\n", head->name);
        head = head->next;
    }
}

// Function to delete a node from the list
void delete(Node** head) {
    char name[50];
    printf("Enter the name of the recipient to be deleted: ");
    scanf("%s", name);

    Node* prev = NULL;
    Node* current = *head;

    while (current) {
        if (strcmp(current->name, name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                *head = current->next;
            }
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No recipient found with that name.\n");
    }
}

int main() {
    Node* head = NULL;

    while (1) {
        printf("Enter 1 to insert, 2 to traverse, 3 to delete, or 4 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert(&head);
                break;
            case 2:
                traverse(head);
                break;
            case 3:
                delete(&head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}