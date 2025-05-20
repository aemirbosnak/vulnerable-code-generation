//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to add an element to the end of the queue
void enqueue(struct node** front_ref, int data) {
    struct node* node = newNode(data);
    if (*front_ref == NULL) {
        *front_ref = node;
        return;
    }
    struct node* last = *front_ref;
    while (last->next!= NULL)
        last = last->next;
    last->next = node;
}

// Function to remove an element from the front of the queue
int dequeue(struct node** front_ref) {
    if (*front_ref == NULL)
        return -1;
    struct node* temp = *front_ref;
    *front_ref = (*front_ref)->next;
    int data = temp->data;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void display(struct node* node) {
    while (node!= NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Main function
int main() {
    struct node* front = NULL;
    enqueue(&front, 10);
    enqueue(&front, 20);
    enqueue(&front, 30);
    enqueue(&front, 40);
    printf("Queue elements are: ");
    display(front);
    printf("\n");
    int dequeued_data = dequeue(&front);
    printf("Dequeued element is: %d\n", dequeued_data);
    printf("Queue elements after dequeue are: ");
    display(front);
    printf("\n");
    return 0;
}