//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function declarations
Node* createNode(int data);
void insertAtBeginning(Node** head, int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int key);
Node* search(Node* head, int key);
void displayList(Node* head);
void freeList(Node** head);

int main() {
    Node* head = NULL;  // Initialize the head of the list
    int choice, data;

    do {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Search a Node\n");
        printf("5. Display List\n");
        printf("6. Free List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter an integer to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter an integer to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                printf("Enter an integer to search: ");
                scanf("%d", &data);
                Node* foundNode = search(head, data);
                if (foundNode) {
                    printf("Node with data %d found.\n", foundNode->data);
                } else {
                    printf("Node with data %d not found.\n", data);
                }
                break;
            case 5:
                printf("Displaying the linked list:\n");
                displayList(head);
                break;
            case 6:
                freeList(&head);
                printf("List freed successfully.\n");
                break;
            case 7:
                printf("Exiting the program.\n");
                freeList(&head);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node %d inserted at the beginning.\n", data);
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Node %d inserted at the end.\n", data);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node %d inserted at the end.\n", data);
}

// Function to delete a node with a given key from the linked list
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // Change head if node to be deleted is the head
        free(temp);
        printf("Node %d deleted.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
        return;
    }
    
    prev->next = temp->next;  // Unlink the node from the linked list
    free(temp);  // Free memory
    printf("Node %d deleted.\n", key);
}

// Function to search for a node with a given key in the linked list
Node* search(Node* head, int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;  // Return the node if found
        }
        current = current->next;
    }
    return NULL;  // Return NULL if the node is not found
}

// Function to display all nodes in the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
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
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    *head = NULL;  // Set head to NULL after freeing
}