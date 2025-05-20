//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int queue[MAX_SIZE], front = -1, rear = -1;

void insert(int value){
    if(rear == MAX_SIZE - 1){
        printf("Queue is full!\n");
    }else{
        if(front == -1){
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Inserted the value %d in to the queue\n", value);
    }
}

void delete(){
    if(front == -1 || front > rear){
        printf("Queue is empty!\n");
    }else{
        printf("Deleted value %d from the queue\n", queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 || front > rear){
        printf("Queue is empty!\n");
    }else{
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main(){
    int choice, value;
    while(1){
        printf("\nEnter the choice:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to be inserted to the queue:\n");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid input!\n");
        }
    }
    return 0;
}