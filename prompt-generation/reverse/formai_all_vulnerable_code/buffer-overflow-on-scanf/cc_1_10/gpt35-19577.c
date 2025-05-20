//FormAI DATASET v1.0 Category: Linked list operations ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the linked list structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; // Global variable to store the address of head node 

// Function prototypes
void insert(int data);
void delete(int pos);
void display();

int main()
{
    int choice, data, pos;

    // Display the menu
    printf("****** Linked List Operations ******\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert(data);
                break;

            case 2:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &pos);
                delete(pos);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to insert an element at the end of the linked list
void insert(int data)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        // If the linked list is empty, assign the new node as head node
        head = newNode;
    } else {
        // Traverse the linked list to find the last node
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Assign the new node as the next node of the last node
        temp->next = newNode;
    }

    printf("Element %d inserted successfully.\n", data);
}

// Function to delete an element from the linked list at a given position
void delete(int pos)
{
    if (head == NULL) {
        printf("The linked list is empty!\n");
        return;
    }

    if (pos == 1) {
        // If the head node is to be deleted
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        // Traverse the linked list to find the node at the given position
        struct Node* prev = NULL;
        struct Node* curr = head;
        int i;

        for (i = 1; i < pos; i++) {
            if (curr == NULL) {
                printf("Invalid position!\n");
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        // Delete the node at the given position
        prev->next = curr->next;
        free(curr);
    }

    printf("Element at position %d deleted successfully.\n", pos);
}

// Function to display the elements of the linked list
void display()
{
    if (head == NULL) {
        printf("The linked list is empty!\n");
        return;
    }

    struct Node* temp = head;

    printf("The linked list is: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}