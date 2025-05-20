//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void enqueue(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    if (new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = value;
    new_node->next = NULL;

    pthread_mutex_lock(&mutex);

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }

    pthread_mutex_unlock(&mutex);
}

int dequeue() {
    int value;
    struct node *temp_node;

    pthread_mutex_lock(&mutex);

    if (front == NULL) {
        printf("Queue is empty\n");
        pthread_mutex_unlock(&mutex);
        return -1;
    } else if (front == rear) {
        temp_node = front;
        value = front->data;
        free(front);
        front = NULL;
        rear = NULL;
    } else {
        temp_node = front;
        value = front->data;
        front = front->next;
        free(temp_node);
    }

    pthread_mutex_unlock(&mutex);

    return value;
}

void display() {
    struct node *temp_node = front;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");

    while (temp_node!= NULL) {
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be added: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value!= -1)
                    printf("The dequeued value is %d\n", value);
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