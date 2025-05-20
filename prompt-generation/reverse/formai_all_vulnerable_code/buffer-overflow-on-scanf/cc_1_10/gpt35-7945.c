//FormAI DATASET v1.0 Category: Queue Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int data){
    if(rear == MAX_SIZE-1){
        printf("\nQueue Overflow!\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = data;
    printf("\nEnqueued Element: %d\n", data);
}

void dequeue(){
    if(front == -1){
        printf("\nQueue Underflow!\n");
        return;
    }
    printf("\nDequeued Element: %d\n", queue[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
}

void display(){
    if(front == -1){
        printf("\nQueue is Empty!\n");
        return;
    }
    printf("\nElements in the Queue: ");
    for(int i = front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){

    int choice;
    int data;

    while(1){

        printf("\nEnter your Choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("\nEnter the Element to Enqueue: ");
                scanf("%d", &data);
                enqueue(data);
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
                printf("\nInvalid Choice!\n");

        }

    }

    return 0;
}