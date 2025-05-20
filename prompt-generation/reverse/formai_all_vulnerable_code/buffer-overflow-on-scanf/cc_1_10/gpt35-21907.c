//FormAI DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a node structure for a singly linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
struct node* insertBeginning(struct node *head, int data) {
    struct node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the list
struct node* insertEnd(struct node *head, int data) {
    struct node *newNode = createNode(data);
    if(head == NULL) {
        head = newNode;
    }
    else {
        struct node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to delete a node from the list given the value
struct node* deleteNode(struct node *head, int value) {
    struct node *temp = head;
    struct node *prev = NULL;
    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Value not found in list.\n");
    }
    else {
        if(prev == NULL) {
            head = temp->next;
        }
        else {
            prev->next = temp->next;
        }
        printf("Deleted %d from the list.\n", value);
        free(temp);
    }
    return head;
}

// Function to display all the nodes in the list
void displayList(struct node *head) {
    struct node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, value;
    while(1) {
        printf("Select an operation:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Display the list\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertBeginning(head, value);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;
            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}