//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    int choice = 0;
    while (choice!= 5) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Is Queue Empty\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                Node* new_node = create_node(data);
                if (rear == NULL) {
                    front = new_node;
                    rear = new_node;
                } else {
                    rear->next = new_node;
                    rear = rear->next;
                }
                break;
            }
            case 2: {
                if (front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    int data = front->data;
                    Node* temp = front;
                    front = front->next;
                    free(temp);
                    printf("Dequeued data: %d\n", data);
                }
                break;
            }
            case 3: {
                if (front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    Node* temp = front;
                    while (temp!= NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                }
                break;
            }
            case 4: {
                if (front == NULL) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            }
            case 5: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}