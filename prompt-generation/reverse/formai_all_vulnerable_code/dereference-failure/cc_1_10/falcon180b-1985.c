//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// node structure definition
struct node {
    int data;
    struct node* next;
};

// function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// function to add an element to the rear of the queue
void enqueue(struct node** front_ref, struct node** rear_ref, int data) {
    struct node* node = newNode(data);

    // check if the queue is empty
    if (*front_ref == NULL) {
        *front_ref = node;
        *rear_ref = node;
        return;
    }

    // add node to the rear of the queue
    (*rear_ref)->next = node;
    (*rear_ref) = node;
}

// function to remove an element from the front of the queue
int dequeue(struct node** front_ref, struct node** rear_ref) {
    char res;
    struct node* node = *front_ref;

    // check if the queue is empty
    if (*front_ref == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    // store the data of the node to be deleted
    int data = node->data;

    // move the front pointer to the next node
    *front_ref = node->next;

    // free the memory occupied by the deleted node
    free(node);

    // check if the queue is empty after deleting the node
    if (*front_ref == NULL) {
        *rear_ref = NULL;
    }

    return data;
}

// function to display the elements of the queue
void display(struct node* node) {
    if (node == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// main function
int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    // enqueue elements
    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);

    // display the elements of the queue
    printf("Elements of the queue after enqueue:\n");
    display(front);

    // dequeue elements
    int data = dequeue(&front, &rear);
    printf("Element dequeued: %d\n", data);

    // display the elements of the queue
    printf("Elements of the queue after dequeue:\n");
    display(front);

    return 0;
}