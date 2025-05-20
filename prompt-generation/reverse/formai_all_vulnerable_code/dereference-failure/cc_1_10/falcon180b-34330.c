//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node with given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the end of the linked list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* current = head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node with given data from the linked list
Node* deleteNode(Node* head, int data) {
    Node* current = head;
    if (current!= NULL && current->data == data) {
        head = current->next;
        free(current);
        return head;
    }
    while (current->next!= NULL && current->next->data!= data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return head;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

// Function to search for a node with given data in the linked list
Node* searchList(Node* head, int data) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to sort the linked list
Node* sortList(Node* head) {
    Node* current = head;
    while (current!= NULL && current->next!= NULL) {
        if (current->data > current->next->data) {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
        }
        current = current->next;
    }
    return head;
}

// Main function to test the linked list operations
int main() {
    Node* head = NULL;
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    printList(head);
    head = deleteNode(head, 2);
    printList(head);
    head = reverseList(head);
    printList(head);
    Node* searchResult = searchList(head, 3);
    if (searchResult!= NULL) {
        printf("Found node with data %d\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }
    head = sortList(head);
    printList(head);
    return 0;
}