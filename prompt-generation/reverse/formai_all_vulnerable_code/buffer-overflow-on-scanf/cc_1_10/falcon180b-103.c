//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

//Function to create a new node with given data
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory could not be allocated\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to add a node at the end of the list
void addNode(Node** head, char data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
}

//Main function
int main() {
    Node* head = NULL;
    char choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Add a character\n");
        printf("2. Print the list\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
        switch(choice) {
            case '1': {
                char data;
                printf("Enter the character to be added: ");
                scanf("%c", &data);
                addNode(&head, data);
                break;
            }
            case '2': {
                printList(head);
                break;
            }
            case '3': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    } while (choice!= '3');
    return 0;
}