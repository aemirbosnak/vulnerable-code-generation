//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct node* next;
} node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** frontRef, int data) {
    node* newNode = createNode(data);
    if (*frontRef == NULL) {
        *frontRef = newNode;
        return;
    }
    node* last = *frontRef;
    while (last->next!= NULL) {
        last = last->next;
    }
    last->next = newNode;
}

int dequeue(node** frontRef) {
    if (*frontRef == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    node* temp = *frontRef;
    *frontRef = (*frontRef)->next;
    int data = temp->data;
    free(temp);
    return data;
}

void display(node* front) {
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
}

int main() {
    node* front = NULL;
    int choice, data;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;
            case 2:
                data = dequeue(&front);
                if (data!= -1) {
                    printf("Dequeued data: %d\n", data);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}