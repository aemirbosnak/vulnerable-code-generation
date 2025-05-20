//FormAI DATASET v1.0 Category: Queue Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct queue {
    Node *front;
    Node *back;
} Queue;

void enqueue(Queue *q, int data) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(q->back != NULL) {
        q->back->next = new_node;
    }

    q->back = new_node;

    if(q->front == NULL) {
        q->front = new_node;
    }
}

int dequeue(Queue *q) {
    if(q->front == NULL) {
        printf("ERROR: Queue is empty\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;

    q->front = q->front->next;
    free(temp);

    if(q->front == NULL) {
        q->back = NULL;
    }

    return data;
}

void print_queue(Queue *q) {
    if(q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    Node *current = q->front;
    printf("Queue: ");

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    Queue my_queue = {NULL, NULL};

    printf("Welcome to the Cyberpunk Queue:\n");

    while(1) {
        int choice, item;

        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the item to be enqueued: ");
                scanf("%d", &item);
                enqueue(&my_queue, item);
                printf("%d has been enqueued.\n", item);
                break;

            case 2:
                item = dequeue(&my_queue);
                if(item != -1) {
                    printf("%d has been dequeued.\n", item);
                }
                break;

            case 3:
                print_queue(&my_queue);
                break;

            case 4:
                printf("Goodbye.\n");
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}