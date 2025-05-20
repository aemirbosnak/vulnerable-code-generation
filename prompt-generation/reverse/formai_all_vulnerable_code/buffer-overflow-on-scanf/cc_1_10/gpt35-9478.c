//FormAI DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct queue_node{
    int data;
    struct queue_node *next;
};

struct queue{
    struct queue_node *front;
    struct queue_node *rear;
};

struct queue* create_queue(){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int data){
    struct queue_node *new_node = (struct queue_node*)malloc(sizeof(struct queue_node));
    new_node->data = data;
    new_node->next = NULL;
    if(q->rear == NULL){
        q->front = new_node;
        q->rear = new_node;
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

void dequeue(struct queue *q){
    if(q->front == NULL){
        printf("Queue is empty!\n");
        return;
    }
    int popped_value = q->front->data;
    struct queue_node *temp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    printf("%d has been removed from the queue.\n", popped_value);
}

void display_queue(struct queue *q){
    if(q->front == NULL){
        printf("Queue is empty!\n");
        return;
    }
    struct queue_node *temp = q->front;
    printf("Queue: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct queue *q = create_queue();
    int choice, data;
    while(1){
        printf("\nQueue Operations:\n");
        printf("==================\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be added to the queue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display_queue(q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}