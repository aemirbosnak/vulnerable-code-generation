//FormAI DATASET v1.0 Category: Linked list operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node of the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a new node at the beginning of the linked list
struct Node *insertBegin(struct Node *start, int newData) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    // Check if memory allocation was successful or not
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Save the data in the new node
    newNode->data = newData;
    // Make the new node point to the previously first node of the list
    newNode->next = start;
    // Make the start of the list point to the new node
    start = newNode;
    // Return the updated start pointer of the list
    return start;
}

// Function to insert a new node at the end of the linked list
struct Node *insertEnd(struct Node *start, int newData) {
    // Allocate memory for the new node
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    // Check if memory allocation was successful or not
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Save the data in the new node
    newNode->data = newData;
    // Set the next pointer of the new node to NULL since it will be the last one
    newNode->next = NULL;
    // If the list is empty, make the start point to the new node
    if (start == NULL) {
        start = newNode;
    } else {
        // Otherwise, traverse to the last node of the list
        struct Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Make the last node point to the new node
        temp->next = newNode;
    }
    // Return the updated start pointer of the list
    return start;
}

// Function to delete a node with the given data from the linked list
struct Node *deleteNode(struct Node *start, int key) {
    // Check if the list is empty
    if (start == NULL) {
        printf("The list is empty!\n");
    } else {
        // Check if the node to be deleted is the first one
        if (start->data == key) {
            struct Node *temp = start;
            start = start->next;
            free(temp);
        } else {
            // Otherwise, traverse the list to find the node
            struct Node *temp = start;
            while (temp->next != NULL && temp->next->data != key) {
                temp = temp->next;
            }
            if (temp->next == NULL) {
                printf("Data not found in the list!\n");
            } else {
                // Delete the matching node
                struct Node *temp2 = temp->next;
                temp->next = temp2->next;
                free(temp2);
            }
        }
    }
    // Return the updated start pointer of the list
    return start;
}

// Function to display the contents of the linked list
void displayList(struct Node *start) {
    // Check if the list is empty
    if (start == NULL) {
        printf("The list is empty!\n");
    } else {
        // Traverse the list and print the data of each node
        struct Node *temp = start;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // Initialize an empty linked list
    struct Node *start = NULL;
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Delete a node\n");
    printf("4. Display the list\n");
    printf("5. Exit\n");
    int choice, data;
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                start = insertBegin(start, data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                start = insertEnd(start, data);
                break;
            case 3:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                start = deleteNode(start, data);
                break;
            case 4:
                printf("The current list is: ");
                displayList(start);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    // Free the memory allocated for each node of the list
    struct Node *temp = start;
    while (start != NULL) {
        start = start->next;
        free(temp);
        temp = start;
    }
    return 0;
}