//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure definition
struct node {
    int data;
    struct node* next;
};

void enqueue(struct node** front_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if(*front_ref == NULL) {
        new_node->next = new_node;
        *front_ref = new_node;
    }
    else {
        struct node* last = *front_ref;
        while(last->next!= *front_ref)
            last = last->next;

        last->next = new_node;
        new_node->next = *front_ref;
    }
}

void dequeue(struct node** front_ref) {
    if(*front_ref == NULL)
        return;

    struct node* temp = *front_ref;
    *front_ref = (*front_ref)->next;

    free(temp);
}

void display(struct node* front) {
    struct node* last;
    if(front == NULL)
        return;

    printf("Queue elements are: ");
    last = front;
    do {
        printf("%d ", last->data);
        last = last->next;
    } while(last!= front);

    printf("\n");
}

int main() {
    struct node* front = NULL;
    int choice, data;

    while(1) {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(&front, data);
                break;

            case 2:
                dequeue(&front);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}