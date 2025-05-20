//FormAI DATASET v1.0 Category: Queue Implementation ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 10

int circular_queue[QUEUE_SIZE], front = -1, rear = -1;

int is_empty(){
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}

int is_full(){
    if ((rear + 1) % QUEUE_SIZE == front)
        return 1;
    return 0;
}

void enqueue(int element){
    if (is_full())
        printf("Queue is full\n");
    else if (is_empty()){
        front = rear = 0;
        circular_queue[rear] = element;
    }
    else{
        rear = (rear+1) % QUEUE_SIZE;
        circular_queue[rear] = element;
    }
}

void dequeue(){
    if (is_empty())
        printf("Queue is empty\n");
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % QUEUE_SIZE;
}

void display(){
    if(is_empty())
        printf("Queue is empty\n");
    else{
        int i;
        printf("Queue elements are\n");
        for (i = front; i != rear; i = (i + 1) % QUEUE_SIZE)
            printf("%d ", circular_queue[i]);
        printf("%d ", circular_queue[i]);
        printf("\n");
    }
}

int main(){
    int choice, element;
    while (1){
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter the element to be enqueued\n");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}