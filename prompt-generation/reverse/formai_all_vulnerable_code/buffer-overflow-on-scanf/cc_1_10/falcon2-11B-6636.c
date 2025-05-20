//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* current = head;

    while (1) {
        int data;
        printf("Enter data (-1 to end): ");
        scanf("%d", &data);

        if (data == -1) {
            break;
        }

        current = newNode(data);
        current->next = NULL;
        head = current;
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// Function to create a graph using a linked list
struct Node* createGraph(struct Node* head) {
    struct Node* node1 = newNode(1);
    struct Node* node2 = newNode(2);
    struct Node* node3 = newNode(3);
    struct Node* node4 = newNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    return head;
}

// Function to print the graph
void printGraph(struct Node* head) {
    struct Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = createLinkedList();
    createGraph(head);
    printGraph(head);

    return 0;
}