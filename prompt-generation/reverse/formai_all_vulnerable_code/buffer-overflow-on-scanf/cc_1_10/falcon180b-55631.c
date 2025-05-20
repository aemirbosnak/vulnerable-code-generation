//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** front, node** rear, int data) {
    node* newNode = createNode(data);
    if(*front == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(node** front, node** rear) {
    node* temp = *front;
    int data = temp->data;
    if(*front == *rear) {
        *front = NULL;
        *rear = NULL;
    } else {
        *front = temp->next;
    }
    free(temp);
    return data;
}

int peek(node* front) {
    return front->data;
}

int isEmpty(node* front) {
    return front == NULL;
}

int main() {
    node* front = NULL;
    node* rear = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&front, &rear, data);
                break;
            case 2:
                data = dequeue(&front, &rear);
                printf("Dequeued data: %d\n", data);
                break;
            case 3:
                if(isEmpty(front)) {
                    printf("Queue is empty\n");
                } else {
                    data = peek(front);
                    printf("Peeked data: %d\n", data);
                }
                break;
            case 4:
                printf("Queue: ");
                while(front!= NULL) {
                    printf("%d ", front->data);
                    front = front->next;
                }
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 5);

    return 0;
}