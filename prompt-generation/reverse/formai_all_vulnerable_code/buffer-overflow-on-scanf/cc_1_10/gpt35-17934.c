//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#define MAX 10

int front = -1;
int rear = -1;
int queue[MAX];

// Function to insert an element to the queue
void enqueue(int x){
    if(rear == MAX-1){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = x;
    printf("%d is enqueued into the queue\n", x);
}

// Function to delete an element from the queue
void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    printf("%d is dequeued from the queue\n", queue[front]);
    front++;
}

// Function to display the elements of the queue
void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty\n");
        return;
    }
    printf("Elements in the queue are: ");
    for(int i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    printf("------------------------\n");
    printf("Welcome to Queue Example\n");
    printf("------------------------\n");

    int option, num;

    do{
        printf("\nEnter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display\n");
        printf("Enter 4 to Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d", &num);
                enqueue(num);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid option\n");
        }
        
    }while(option != 4);

    return 0;
}