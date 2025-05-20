//FormAI DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include<stdio.h>
#define Max 5

int queue[Max]; //queue implementation using array
int front = -1, rear = -1;

void enqueue(int x){
    if(front == (rear+1)%Max){ //checks if the queue is full
        printf("Queue is full\n");
        return;
    }

    if(front == -1) front = 0; //checks if the queue is empty
    rear = (rear+1)%Max;
    queue[rear] = x;
    printf("%d is inserted into the queue\n", x);
}

void dequeue(){
    if(front == -1){ //checks if the queue is empty
        printf("Queue is empty\n");
        return;
    }

    printf("%d is removed from the queue\n", queue[front]);
    if(front == rear){ //if only one element is present in the queue
        front = -1;
        rear = -1;
    } else{
        front = (front+1)%Max;
    }
}

void display(){
    if(front == -1){ //checks if the queue is empty
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    do{
        printf("%d ", queue[i]);
        i = (i+1)%Max;
    }while(i != (rear+1)%Max); //printing from front to rear in circular way
}

int main(){
    int choice, element;

    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
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
                printf("Exiting now.....");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 4);

    return 0;
}