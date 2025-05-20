//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add a node at the beginning of the list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("%d is pushed to the stack\n", new_data);
}

// Function to add a node at the end of the list
void append(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    struct node* last = *head_ref;

    if (*head_ref == NULL) {
        new_node->next = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    printf("%d is appended to the stack\n", new_data);
}

// Function to delete a node from the list
void deleteNode(struct node **head_ref, int key) {
    struct node* temp = *head_ref, *prev;

    if (temp!= NULL && temp->data == key) {
        temp = temp->next;
        *head_ref = temp;
        free(prev);
        printf("%d is deleted from the stack\n", key);
        return;
    }

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("%d is not present in the stack\n", key);
    else {
        prev->next = temp->next;
        free(temp);
        printf("%d is deleted from the stack\n", key);
    }
}

// Function to display the list
void display(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above functions
int main() {
    struct node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    display(head);

    append(&head, 40);
    append(&head, 50);
    display(head);

    deleteNode(&head, 20);
    deleteNode(&head, 50);
    display(head);

    return 0;
}