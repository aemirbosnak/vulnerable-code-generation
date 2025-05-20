//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* next;
} Node;

// Create a new node with the given data
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Print the linked list
void print_list(Node* head) {
    Node* current = head;
    printf("Linked List: ");
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Reverse the linked list
void reverse_list(Node** head_ref) {
    Node* prev = NULL;
    Node* current = *head_ref;
    while (current!= NULL) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Shuffle the linked list
void shuffle_list(Node* head) {
    srand(time(NULL));
    Node* current = head;
    while (current!= NULL) {
        int rand_index = rand() % (current->data + 1);
        Node* temp = current->next;
        current->next = temp->next;
        temp->next = current;
        current = temp;
    }
}

// Sort the linked list
void sort_list(Node* head) {
    Node* current = head;
    while (current!= NULL) {
        Node* next = current->next;
        while (next!= NULL && next->data < current->data) {
            int temp_data = current->data;
            current->data = next->data;
            next->data = temp_data;
            current = next;
            next = current->next;
        }
        current = next;
    }
}

int main() {
    // Create a linked list with random data
    Node* head = NULL;
    for (int i = 0; i < 10; i++) {
        head = create_node(rand() % 100);
    }
    printf("Original List: ");
    print_list(head);

    // Reverse the linked list
    reverse_list(&head);
    printf("Reversed List: ");
    print_list(head);

    // Shuffle the linked list
    shuffle_list(head);
    printf("Shuffled List: ");
    print_list(head);

    // Sort the linked list
    sort_list(head);
    printf("Sorted List: ");
    print_list(head);

    return 0;
}