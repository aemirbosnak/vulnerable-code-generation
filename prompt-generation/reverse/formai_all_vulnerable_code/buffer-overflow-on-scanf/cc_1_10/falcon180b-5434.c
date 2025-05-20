//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

void enqueue(struct node** front_ref, int new_data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    if (*front_ref == NULL)
        *front_ref = new_node;
    else {
        struct node* last = *front_ref;
        while (last->next!= NULL)
            last = last->next;
        last->next = new_node;
    }
}

int dequeue(struct node** front_ref) {
    char ch;
    struct node* temp = *front_ref;
    if (temp == NULL) {
        printf("Queue is empty\n");
        exit(0);
    }
    printf("Deleted element is %d\n", temp->data);
    temp = temp->next;
    *front_ref = temp;
    free(temp);
    return temp->data;
}

void display(struct node* front) {
    printf("Queue elements are: ");
    while (front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct node* front = NULL;
    int choice, value;
    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be enqueued: ");
                scanf("%d", &value);
                enqueue(&front, value);
                break;
            case 2:
                value = dequeue(&front);
                printf("Dequeued value is %d\n", value);
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 4);
    return 0;
}