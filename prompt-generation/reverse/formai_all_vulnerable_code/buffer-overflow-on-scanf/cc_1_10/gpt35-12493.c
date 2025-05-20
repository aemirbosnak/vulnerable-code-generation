//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of a doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// Function to insert a new node at the end of a doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return head;
}

// Function to delete the node at the beginning of a doubly linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head != NULL) {
        struct Node* toDelete = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(toDelete);
    }
    return head;
}

// Function to delete the node at the end of a doubly linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            struct Node* current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            free(current->next);
            current->next = NULL;
        }
    }
    return head;
}

// Function to display the elements of a doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
    } else {
        printf("The list elements are:\n");
        while (head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int option, data;
    do {
        // Display menu
        printf("\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete from the end\n");
        printf("5. Display the list elements\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        // Perform operation based on option
        switch (option) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                head = deleteAtBeginning(head);
                break;
            case 4:
                head = deleteAtEnd(head);
                break;  
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 6);

    return 0;
}