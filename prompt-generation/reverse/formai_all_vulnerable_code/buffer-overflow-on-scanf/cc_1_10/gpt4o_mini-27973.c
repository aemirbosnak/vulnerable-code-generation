//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
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

// Function to insert a node at the beginning of the linked list
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head, *prev = NULL;

    // Check if head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        free(temp);         // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Node with value %d not found in the list\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp); // Free memory
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to calculate the average of the linked list
float calculateAverage(struct Node* head) {
    if (head == NULL) return 0.0;

    int sum = 0, count = 0;
    struct Node* current = head;

    while (current != NULL) {
        sum += current->data;
        count++;
        current = current->next;
    }
    return (float)sum / count;
}

// Main function to execute linked list operations
int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Linked List Operations Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Beginning\n");
        printf("3. Delete a Node\n");
        printf("4. Print the List\n");
        printf("5. Calculate Average\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;
            case 3:
                printf("Enter value to delete from the list: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 4:
                printf("Current Linked List: ");
                printList(head);
                break;
            case 5:
                {
                    float average = calculateAverage(head);
                    printf("Average of the list: %.2f\n", average);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}