//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Queue is full!");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if(front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if(front == NULL) {
        printf("Queue is empty!");
        return -1;
    }
    Node* temp = front;
    int value = front->data;
    front = front->next;
    free(temp);
    return value;
}

int peek() {
    if(front == NULL) {
        printf("Queue is empty!");
        return -1;
    }
    return front->data;
}

void display() {
    if(front == NULL) {
        printf("Queue is empty!");
        return;
    }
    Node* temp = front;
    printf("Queue elements are: ");
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\nEnter your choice:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value!= -1) {
                    printf("The dequeued value is: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if(value!= -1) {
                    printf("The front value is: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice!= 5);
    return 0;
}