//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Definition of a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void deleteNode(Node** head, int data);
Node* searchNode(Node* head, int data);
void displayList(Node* head);
void freeList(Node* head);

int main() {
    Node* head = NULL;
    int choice, data;

    do {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node\n");
        printf("3. Search Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Node with data %d inserted.\n", data);
                break;

            case 2:
                printf("Enter data of the node to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                Node* foundNode = searchNode(head, data);
                if (foundNode) {
                    printf("Node with data %d found.\n", foundNode->data);
                } else {
                    printf("Node with data %d not found.\n", data);
                }
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    freeList(head);  // Free the allocated memory before exit
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

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node with a given data
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == data) {
        *head = temp->next; // Changed head
        free(temp);
        printf("Node with data %d deleted.\n", data);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If data was not found in the list
    if (temp == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    // Unlink the node
    prev->next = temp->next;
    free(temp);
    printf("Node with data %d deleted.\n", data);
}

// Function to search for a node with a given data
Node* searchNode(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Node not found
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free allocated memory of the list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}