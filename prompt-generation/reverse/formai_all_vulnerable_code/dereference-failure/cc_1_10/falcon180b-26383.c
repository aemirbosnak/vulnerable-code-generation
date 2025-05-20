//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    if(front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if(front == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }

    struct node* temp = front;
    front = front->next;

    if(front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    struct node* temp = front;

    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}