//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int data);
void displayList(Node* head);
void freeList(Node* head);
void menu();

// Main function
int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Enter integer data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("The current linked list is: ");
                displayList(head);
                break;
            case 4:
                freeList(head);
                head = NULL; // Clear the linked list
                printf("Linked list freed.\n");
                break;
            case 5:
                freeList(head);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode; // If list is empty, new node is the head
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the end of the list
    }
    temp->next = newNode; // Link the new node
    printf("Inserted %d into the linked list.\n", data);
}

// Function to delete a node with the specified data
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty, cannot delete %d.\n", data);
        return;
    }
    
    Node* temp = *head;
    Node* prev = NULL;

    // Check if the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Change head
        free(temp); // Free old head
        printf("Deleted %d from the linked list.\n", data);
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found in the list
    if (temp == NULL) {
        printf("%d not found in the linked list.\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); // Free the memory of the node to be deleted
    printf("Deleted %d from the linked list.\n", data);
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the entire linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All nodes freed.\n");
}

// Function to display the menu options
void menu() {
    printf("\n******** Linked List Operations Menu ********\n");
    printf("1. Insert Node at End\n");
    printf("2. Delete Node by Value\n");
    printf("3. Display Linked List\n");
    printf("4. Free the Linked List\n");
    printf("5. Exit\n");
    printf("***************************************\n");
}