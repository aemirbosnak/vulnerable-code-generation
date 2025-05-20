//FormAI DATASET v1.0 Category: Queue Implementation ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int num){
    if( rear == MAX - 1){
        printf("Queue Overflow.");
        return;
    }
    if(front == -1)
        front = 0;
    rear++;
    queue[rear] = num;
}

int dequeue(){
    int item;
    if(front == -1 || front > rear){
        printf("Queue Underflow.");
        return -1;
    }
    item = queue[front];
    front++;
    return item;
}

void display(){
    int i;
    if(front == -1){
        printf("Queue is empty.");
        return;
    }
    for(i=front; i<=rear; i++)
        printf("%d ", queue[i]);
}

int main(){
    int choice, num;
    while(1){
        printf("\n\n----QUEUE MENU----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element to be enqueued: ");
                    scanf("%d", &num);
                    enqueue(num);
                    break;
            case 2: num = dequeue();
                    printf("\nThe element dequeued is %d", num);
                    break;
            case 3: printf("\nThe elements in the queue are: ");
                    display();
                    break;
            case 4: exit(1);
            default: printf("\nInvalid choice.");
        }
    }
    return 0;
}