//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL) {
        printf("Queue is full\n");
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if(front == NULL)
        front = rear = new_node;
    else
        rear->next = new_node;
    rear = new_node;
    printf("%d enqueued to the queue\n", data);
}

void dequeue() {
    if(front == NULL)
        printf("Queue is empty\n");
    else {
        printf("%d dequeued from the queue\n", front->data);
        node* temp = front;
        front = front->next;
        free(temp);
        if(front == NULL)
            rear = NULL;
    }
}

void display() {
    node* temp = front;
    printf("Queue elements are: ");
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while(1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}