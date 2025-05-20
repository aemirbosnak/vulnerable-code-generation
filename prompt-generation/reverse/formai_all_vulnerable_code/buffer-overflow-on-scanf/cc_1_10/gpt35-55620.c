//FormAI DATASET v1.0 Category: Linked list operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    newNode->data = data; // Assign data to new node
    newNode->next = NULL; // Set next pointer of new node to NULL
    return newNode;
}

// Function to add a new node at the end of the linked list
struct Node* addNode(struct Node* head, int data) {
    struct Node *current = head, *newNode = createNode(data);
    if(!head) {
        head = newNode;
    } else {
        while(current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Node added successfully!\n");
    return head;
}

// Function to delete a node from the linked list
struct Node* deleteNode(struct Node* head, int data) {
    struct Node *current = head, *prev;
    if(!head) {
        printf("Linked list is empty!\n");
    } else if(head->data == data) {
        head = head->next;
        free(current);
        printf("Node deleted successfully!\n");
    } else {
        while(current && current->data != data) {
            prev = current;
            current = current->next;
        }
        if(!current) {
            printf("Node not found!\n");
        } else {
            prev->next = current->next;
            free(current);
            printf("Node deleted successfully!\n");
        }
    }
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node *current = head;
    if(!head) {
        printf("Linked list is empty!\n");
    } else {
        printf("Linked list:\n");
        while(current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Node* head = NULL; // Initialize head pointer of linked list to NULL
    int choice, data;
    while(1) {
        printf("\nOperations on Linked List:\n");
        printf("\n1. Add a Node");
        printf("\n2. Delete a Node");
        printf("\n3. Display the Linked List");
        printf("\n4. Exit");
        printf("\n\nEnter your choice:\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter data to add:\n");
                scanf("%d", &data);
                head = addNode(head, data);
                break;
            case 2:
                printf("\nEnter data to delete:\n");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("\nExiting the program. Bye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}