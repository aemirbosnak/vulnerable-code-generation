//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list
struct node {
    int data;
    struct node *next;
};

// Declare the global variable for the head node of the linked list
struct node *head = NULL;

// Declare function prototypes
void insert(int);
void delete(int);
void display();
void search(int);

// Define the main function
int main() {

    // Declare variables for user input and menu selection
    int choice, val;    

    // Display the menu
    do {
        printf("\nWelcome to the Paranoid Linked List Operations Program!");
        printf("\n----------------------------------------------------\n");
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Display Linked List");
        printf("\n4. Search Element");
        printf("\n5. Exit Program\n");
        printf("\nEnter your choice: ");

        // Read in the user's choice
        scanf("%d", &choice);

        // Choose an operation based on the user's choice
        switch(choice) {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("\nEnter the value to be deleted: ");
                scanf("%d", &val);
                delete(val);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nEnter the value to be searched: ");
                scanf("%d", &val);
                search(val);
                break;
            case 5:
                printf("\nExiting the program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// Define the insert function
void insert(int val) {
    // Allocate memory for new node
    struct node *new_node = (struct node*) malloc(sizeof(struct node));

    // Check if memory was allocated successfully
    if (new_node == NULL) {
        printf("\nMemory allocation error. Exiting the program.\n");
        exit(0);
    }

    // Set the data and next pointer for the new node
    new_node->data = val;
    new_node->next = NULL;

    // Check if the linked list is empty
    if (head == NULL) {
        head = new_node;
    } else {
        // Traverse the linked list to the end
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Set the next pointer of the last node to the new node
        temp->next = new_node;
    }

    printf("\n%d inserted into the linked list!\n", val);
}

// Define the delete function
void delete(int val) {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("\nThe linked list is empty. Cannot delete any element!\n");
        return;
    }

    // Check if the node to be deleted is the head node
    if (head->data == val) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        printf("\n%d deleted from the linked list!\n", val);
        return;
    }

    // Traverse the linked list to find the node to be deleted
    struct node *prev = head;
    struct node *curr = head->next;
    while (curr != NULL) {
        if (curr->data == val) {
            prev->next = curr->next;
            free(curr);
            printf("\n%d deleted from the linked list!\n", val);
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("\n%d not found in the linked list. Cannot delete any element!\n", val);
}

// Define the display function
void display() {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("\nThe linked list is empty. Cannot display any element!\n");
        return;
    } 

    // Traverse the linked list and print the nodes
    printf("\nThe linked list is: ");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Define the search function
void search(int val) {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("\nThe linked list is empty. Cannot search for any element!\n");
        return;
    }

    // Traverse the linked list and search for the element
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            printf("\n%d found in the linked list!\n", val);
            return;
        }
        temp = temp->next;
    }

    printf("\n%d not found in the linked list!\n", val);
}