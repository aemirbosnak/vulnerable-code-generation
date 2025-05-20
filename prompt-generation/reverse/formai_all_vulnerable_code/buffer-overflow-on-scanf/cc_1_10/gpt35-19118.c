//FormAI DATASET v1.0 Category: Queue Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item){
    if(rear == MAX_SIZE - 1){
        printf("Sorry, the queue is full.\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("%d has been enqueued.\n", item);
    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Sorry, the queue is empty.\n");
        front = -1;
        rear = -1;
    }
    else{
        printf("%d has been dequeued.\n", queue[front]);
        front++;
    }
}

int main(){
    while(1){
        int choice, item;
        printf("\nPlease choose an option:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the item to be enqueued: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Sorry, I didn't understand that.\n");
                break;
        }
    }
    return 0;
}