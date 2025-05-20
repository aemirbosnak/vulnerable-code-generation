//Falcon-180B DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {
    Node* head = NULL;

    // Allocate memory for 5 nodes
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));
    Node* node4 = (Node*)malloc(sizeof(Node));
    Node* node5 = (Node*)malloc(sizeof(Node));

    // Initialize data and next pointers for each node
    node1->data = 1;
    node1->next = NULL;
    node2->data = 2;
    node2->next = node1;
    node3->data = 3;
    node3->next = node2;
    node4->data = 4;
    node4->next = node3;
    node5->data = 5;
    node5->next = node4;

    // Print the linked list
    printf("Linked List: ");
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free memory allocated for each node
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);

    return 0;
}