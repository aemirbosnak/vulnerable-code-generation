//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;

void enqueue(int data);
void dequeue();
void display();

int main() {
    int choice, data;

    do {
        printf("\n\nEnter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the data to be enqueued: ");
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
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}

void enqueue(int data) {
    node* new_node = (node*) malloc(sizeof(node));

    if(new_node == NULL) {
        printf("\n\nError! Memory not allocated.\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if(front == NULL) {
        front = new_node;
        rear = new_node;
    }
    else {
        rear->next = new_node;
        rear = new_node;
    }

    printf("\n%d enqueued successfully!\n", data);
}

void dequeue() {
    if(front == NULL) {
        printf("\n\nError! Queue is empty.\n");
        return;
    }

    node* temp = front;
    int data = temp->data;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);

    printf("\n%d dequeued successfully!\n", data);
}

void display() {
    if(front == NULL) {
        printf("\n\nError! Queue is empty.\n");
        return;
    }

    printf("\nQueue elements are: ");
    node* temp = front;

    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}