//FormAI DATASET v1.0 Category: Linked list operations ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

// Define the linked list node structure 
struct node {
    int data;
    struct node* next;
};

// Define the start node of the linked list 
struct node *start = NULL;

// Function to insert a node at the beginning of the linked list 
void insertAtBeginning(int val) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = start;
    start = newNode;
    printf("\nNode inserted at the beginning!\n");
}

// Function to insert a node at the end of the linked list 
void insertAtEnd(int val) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if(start == NULL) {
        start = newNode;
        printf("\nNode inserted at the end!\n");
        return;
    }
    struct node* temp = start;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("\nNode inserted at the end!\n");
}

// Function to delete a node from the linked list 
void deleteNode(int val) {
    struct node* temp = start;
    struct node* prev = NULL;
    if(temp == NULL) {
        printf("\nLinked list is empty!\n");
        return;
    }
    if(temp->data == val) {
        start = temp->next;
        free(temp);
        printf("\nNode deleted!\n");
        return;
    }
    while(temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("\nNode not found!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nNode deleted!\n");
}

// Function to display the linked list 
void display() {
    struct node* temp = start;
    if(temp == NULL) {
        printf("\nLinked list is empty!\n");
        return;
    }
    printf("\nLinked list: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the linked list operations 
int main() {
    int option, val;
    do {
        printf("**********************************************\n");
        printf("*************** Linked List Demo **************\n");
        printf("**********************************************\n");
        printf("1.Insert node at the beginning\n");
        printf("2.Insert node at the end\n");
        printf("3.Delete a node\n");
        printf("4.Display the linked list\n");
        printf("5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("\nEnter the value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("\nEnter the value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while(option != 5);
    return 0;
}