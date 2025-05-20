//FormAI DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the structure for our list nodes
struct Node {
    int data;
    struct Node* next;
};

// Function to add a new node to the end of the list
void append(struct Node** headRef, int newData) 
{
    // Allocate memory for the new node and initialize it
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*headRef == NULL) {
        *headRef = newNode;
    } 
    else {
        // Otherwise, traverse the list until the end and add the new node
        struct Node* current = *headRef;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the contents of the list
void printList(struct Node* head) 
{
    // If the list is empty, print a sad message
    if (head == NULL)
    {
        printf("Sorry, the list is empty :(\n");
        return;
    }

    // Otherwise, traverse the list and print each node
    printf("Here are the contents of the list:\n");
    struct Node* current = head;
    while (current != NULL) 
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

// Function to delete a specific node from the list
void deleteNode(struct Node** headRef, int key) 
{
    // If the list is empty, print a n angry message and return
    if (*headRef == NULL) 
    {
        printf("You can't delete from an empty list, silly!\n");
        return;
    }

    // If the head node is the one to be deleted, update the head
    if ((*headRef)->data == key) 
    {
        struct Node* temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        printf("The node containing %d was deleted!\n", key);
        return;
    }

    // Otherwise, traverse the list and find the node to be deleted
    struct Node* current = *headRef;
    while (current->next != NULL && current->next->data != key) 
    {
        current = current->next;
    }

    // If the node wasn't found, print a sarcastic message and return
    if (current->next == NULL) 
    {
        printf("I'm sorry, didn't find any node containing %d. Did you make it up?\n", key);
        return;
    }

    // Otherwise, delete the node
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("The node containing %d was deleted!\n", key);
}

int main() 
{
    // Initialize an empty list
    struct Node* head = NULL;

    // Display a welcome message
    printf("Welcome to the Linked List!\n");

    // Display the menu
    printf("What would you like to do?\n");
    printf("1. Add a node\n");
    printf("2. Delete a node\n");
    printf("3. Print the list\n");
    printf("4. Exit the program\n");

    // Loop through the menu until the user exits
    int choice = 0;
    while (choice != 4) 
    {
        // Get the user's choice
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) 
        {
            case 1:
                // Prompt the user for the data and add a new node to the list
                printf("\nEnter the data for the new node: ");
                int data;
                scanf("%d", &data);
                append(&head, data);
                printf("%d was added to the list!\n", data);
                break;

            case 2:
                // Prompt the user for the data to be deleted and delete the node
                printf("\nEnter the data to be deleted: ");
                int key;
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 3:
                // Print the contents of the list
                printList(head);
                break;

            case 4:
                // Exit the program
                printf("Thanks for playing! Goodbye!\n");
                break;

            default:
                // Inform the user of their mistake and prompt them again
                printf("I'm sorry, that's not a valid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}