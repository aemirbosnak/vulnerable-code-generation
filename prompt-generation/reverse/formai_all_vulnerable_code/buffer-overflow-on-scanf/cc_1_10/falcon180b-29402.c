//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int data) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&lock);
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    pthread_mutex_unlock(&lock);
}

int dequeue() {
    int data;
    Node *temp;
    pthread_mutex_lock(&lock);
    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&lock);
        return -1;
    }
    temp = front;
    data = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    pthread_mutex_unlock(&lock);
    return data;
}

void display() {
    Node *temp = front;
    printf("Queue: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data!= -1)
                    printf("Dequeued data: %d\n", data);
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