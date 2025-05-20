//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a node in a linked list
struct Node{
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
void insertNode(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to print the linked list
void printList(struct Node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    printf("Welcome to the linked list visualizer!\n\n");

    // Create an empty linked list
    struct Node* head = NULL;

    // Insert some nodes into the linked list
    insertNode(&head, 5);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);

    // Print the linked list
    printf("Your linked list looks like this:\n");
    printList(head);
    printf("\n");

    // Ask the user to add a node to the linked list
    printf("Would you like to add a new node? (y/n): ");
    char answer[2];
    scanf("%s", answer);

    // If the user says yes, prompt them for the new node's data and insert it into the linked list
    if(strcmp(answer, "y") == 0){
        printf("Please enter the data for the new node: ");
        int newData;
        scanf("%d", &newData);
        insertNode(&head, newData);

        // Print the updated linked list
        printf("\nYour linked list has been updated and now looks like this:\n");
        printList(head);
    }

    // If the user says no, say goodbye
    else{
        printf("\nGoodbye!\n");
    }

    return 0;
}