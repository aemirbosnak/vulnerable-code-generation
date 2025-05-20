//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
struct Node {
    char name[50];
    int age;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(char name[], int age) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strncpy(newNode->name, name, sizeof(newNode->name) - 1);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, char name[], int age) {
    struct Node* newNode = createNode(name, age);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by name
void deleteNode(struct Node** head, char name[]) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If head node itself holds the name to be deleted
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next; // Changed head
        free(temp);
        return;
    }

    // Search for the name to be deleted
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If name was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to display the list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List:\n");
    while (node != NULL) {
        printf("Name: %s, Age: %d\n", node->name, node->age);
        node = node->next;
    }
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL;
    char name[50];
    int age, choice;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                insertEnd(&head, name, age);
                break;
            case 2:
                printf("Enter name to delete: ");
                scanf("%s", name);
                deleteNode(&head, name);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                // Free the entire list before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}