//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct Node{
    int data;
    struct Node* next;
};

void enqueue(struct Node** front_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*front_ref);
    (*front_ref) = new_node;
}

int dequeue(struct Node** front_ref) {
    struct Node* temp = *front_ref;
    int data = temp->data;
    if(temp == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    *front_ref = temp->next;
    free(temp);
    return data;
}

void display(struct Node* front) {
    printf("Queue elements are: ");
    while(front!= NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL, *rear = NULL;
    int choice, data;

    do {
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
                printf("Enqueued successfully\n");
                break;

            case 2:
                data = dequeue(&front);
                if(data!= -1)
                    printf("Dequeued element is: %d\n", data);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }while(1);

    return 0;
}