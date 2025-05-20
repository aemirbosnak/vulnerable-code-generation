//Falcon-180B DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

void enqueue(struct node** front, struct node** rear, int val) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if (*front == NULL) {
        *front = new_node;
        *rear = new_node;
    }
    else {
        (*rear)->next = new_node;
        *rear = new_node;
    }
}

void dequeue(struct node** front, struct node** rear) {
    struct node* temp = *front;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}

void display(struct node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    struct node* front = NULL;
    struct node* rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 40);
    enqueue(&front, &rear, 50);

    display(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);

    display(front);

    return 0;
}