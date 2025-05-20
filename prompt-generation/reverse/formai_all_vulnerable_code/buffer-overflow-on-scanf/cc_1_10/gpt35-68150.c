//FormAI DATASET v1.0 Category: Data structures visualization ; Style: inquisitive
#include <stdio.h>

// Define a singly-linked list structure for demonstration purposes
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to add a new node to the linked list
void addNode(Node **head, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to print the contents of the linked list
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int input;
    Node *list = NULL;
    
    // Prompt user for input and add to linked list
    printf("Enter a value to add to the list (-1 to stop): ");
    scanf("%d", &input);
    while (input != -1) {
        addNode(&list, input);
        printf("Enter another value (-1 to stop): ");
        scanf("%d", &input);
    }
    
    // Print the linked list before sorting
    printf("Linked list before sorting: ");
    printList(list);
    
    // TODO: Implement sorting algorithm here
    
    // Print the linked list after sorting
    printf("Linked list after sorting: ");
    printList(list);
    
    return 0;
}