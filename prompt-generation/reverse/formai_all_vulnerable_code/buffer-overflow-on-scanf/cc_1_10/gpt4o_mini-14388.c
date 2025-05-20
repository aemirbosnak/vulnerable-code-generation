//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Declare a structure for linked list nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed! Why did I even try?\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    printf("Node with data: %d created! What a masterpiece!\n", data);
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Inserting %d at the beginning! A bold move indeed!\n", data);
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserting %d at the end, but guess what? It's the only node!\n", data);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end! It's the new 'tail' of this linked list prestigious!\n", data);
}

// Function to delete a node by value
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("Like a ghost, %d has vanished! List is empty!\n", data);
        return;
    }
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        printf("%d has been banished from the list! Bye-bye!\n", data);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with %d not found! It must be on a vacation!\n", data);
        return;
    }
    
    prev->next = temp->next;
    free(temp);
    printf("%d has also been kicked out! What a scandal!\n", data);
}

// Function to display the linked list
void displayList(Node* node) {
    if (node == NULL) {
        printf("The list is as empty as my social life...\n");
        return;
    }
    printf("Current Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the list memory
void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    *head = NULL;
    printf("All nodes have been freed! Seeking new adventures!\n");
}

int main() {
    Node* head = NULL;
    int choice, data;

    printf("Welcome to the Amazing Linked List Adventure!\n\n");

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete a Node\n");
        printf("4. Display List\n");
        printf("5. Quit\n");
        printf("What will it be? (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Ending this legendary journey!\n");
                freeList(&head);
                exit(0);
            default:
                printf("Wrong choice! Try again, don't drown in your confusion!\n");
                break;
        }
        printf("\n");
    }

    return 0;
}