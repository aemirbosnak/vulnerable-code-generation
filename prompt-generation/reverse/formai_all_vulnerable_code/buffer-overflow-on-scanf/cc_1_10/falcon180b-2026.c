//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;
int count = 0;

void enqueue(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    count++;
    printf("Element %d enqueued successfully. ", data);
}

int dequeue() {
    int data;
    Node* temp = front;
    if (front == NULL || front == rear) {
        printf("Queue is empty. ");
        return -1;
    } else {
        data = front->data;
        front = front->next;
        free(temp);
        count--;
        printf("Element %d dequeued successfully. ", data);
        return data;
    }
}

void display() {
    Node* temp = front;
    if (front == NULL) {
        printf("Queue is empty. ");
    } else {
        printf("Queue elements are: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    int choice, data;
    do {
        printf("Enter 1 to enqueue an element. ");
        printf("Enter 2 to dequeue an element. ");
        printf("Enter 3 to display the queue. ");
        printf("Enter 4 to exit. ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data!= -1) {
                    printf("Dequeued element is: %d. ", data);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting... ");
                break;
            default:
                printf("Invalid choice. Please try again. ");
        }
    } while (choice!= 4);
    return 0;
}