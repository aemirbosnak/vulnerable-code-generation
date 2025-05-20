//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

void enqueue(struct node** front_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Queue is full\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    if (*front_ref == NULL) {
        new_node->next = new_node;
        *front_ref = new_node;
    } else {
        new_node->next = *front_ref;
        *front_ref = new_node;
    }
}

int dequeue(struct node** front_ref) {
    struct node* temp = *front_ref;
    int data = temp->data;
    if (temp == temp->next) {
        *front_ref = NULL;
    } else {
        *front_ref = temp->next;
        temp->next = temp->next->next;
    }
    free(temp);
    return data;
}

int is_empty(struct node* front) {
    if (front == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int peek(struct node* front) {
    if (is_empty(front)) {
        printf("Queue is empty\n");
        exit(0);
    }
    return front->data;
}

void display(struct node* front) {
    if (is_empty(front)) {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Queue elements are: ");
    struct node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp!= front);
    printf("\n");
}

int main() {
    struct node* front = NULL;
    int choice, data;

    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;

            case 2:
                data = dequeue(&front);
                printf("Dequeued element is %d\n", data);
                break;

            case 3:
                data = peek(front);
                printf("Front element is %d\n", data);
                break;

            case 4:
                display(front);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}