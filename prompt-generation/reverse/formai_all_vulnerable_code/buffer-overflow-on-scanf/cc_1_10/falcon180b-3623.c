//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;
int size = 0;

void enqueue(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Heap overflow! ");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
    size++;
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty! ");
        exit(1);
    }
    Node *temp = front;
    front = front->next;
    free(temp);
    size--;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty! ");
        return;
    }
    printf("Queue elements are: ");
    Node *temp = front;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    char ch;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! ");
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');
    return 0;
}