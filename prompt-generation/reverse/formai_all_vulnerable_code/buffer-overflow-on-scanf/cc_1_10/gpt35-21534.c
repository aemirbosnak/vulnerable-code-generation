//FormAI DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct Node { // Creating a structure called Node for holding data and data pointers
    int data; // Data integer variable for holding integer values
    struct Node* next; // Next pointer variable for holding the address of next node
};

struct Node* head; // Head pointer variable to store the address of first node

void Insert(int x) { // This function is for inserting node at end of the linked list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // Creating a new node using malloc function
    temp->data = x; // Assigning the data to newly created node
    temp->next = NULL; // Assigning null to the next pointer of newly create node
    if(head == NULL) { // Checking if head is null, then the newly created node will be the first node
        head = temp; // Assigning the address of newly created node to head
        return; // Returning back to main
    }
    struct Node* temp1 = head; // Creating new variable and assigning the address of head to it
    while(temp1->next != NULL) { // Checking for the last node
        temp1 = temp1->next; // Moving the pointer to the next node
    }
    temp1->next = temp; // Assigning the address of newly created node to the next pointer of last node
}

void Delete(int n) { // This function is for deleting a node from the linked list
    struct Node* temp1 = head; // Creating a new variable and assigning the address of head to it
    if(n == 1) { // Checking if we want to delete first node
        head = temp1->next; // Assigning the address of second node to head
        free(temp1); // Deleting the first node
        return; // Returning back to main
    }
    int i;
    for(i = 0; i < n-2; i++) { // Looping till the second last node before the node we want to delete
        temp1 = temp1->next; // Moving the pointer to the next node
    }
    struct Node* temp2 = temp1->next; // Creating a new variable and assigning the address of node to delete
    temp1->next = temp2->next; // Assigning the address of next to next node to the next pointer of the previous node
    free(temp2); // Deleting the node
}

void Print() { // This function is for printing all the nodes data
    printf("List is: ");
    struct Node* temp = head; // Creating a new variable and assigning the address of head to it
    while(temp != NULL) { // Looping till the last node
        printf("%d ",temp->data); // Printing the data of current node
        temp = temp->next; // Moving the pointer to the next node
    }
    printf("\n"); // Giving new line character after printing all data
}

int main() { // Main function
    head = NULL; // Assigning null to head pointer variable
    printf("Enter the number of elements in the linked list: "); // Asking user for number of elements
    int n,x,i;
    scanf("%d",&n); // Taking input from user for number of elements
    for(i = 0; i < n; i++) { // Looping till the number of elements entered by user
        printf("Enter the element: "); // Asking user for the element
        scanf("%d",&x); // Taking input from user for the element
        Insert(x); // Calling the Insert function for inserting the element into the linked list
        printf("Current status of the linked list: ");
        Print(); // Calling the Print function for printing the current status of the linked list
    }
    printf("Enter the node position to delete: "); // Asking user for the node position to delete
    int pos;
    scanf("%d",&pos); // Taking input from user for the node position to delete
    Delete(pos); // Calling the Delete function for deleting the specified node from the linked list
    printf("Current status of the linked list: ");
    Print(); // Calling the Print function for printing the current status of the linked list after deleting the node

    return 0; // Giving zero as exit status
}