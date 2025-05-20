//FormAI DATASET v1.0 Category: Queue Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element){
    if ((front == 0 && rear == MAX_SIZE - 1) || front == rear + 1){
        printf("Queue is full!\n");
        return;
    }
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }else{
        if(rear == MAX_SIZE - 1){
            rear = 0;
        }else{
            rear++;
        }
    }
    queue[rear] = element;
    printf("Added %d to the queue!\n", element);
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("Removed %d from the queue!\n", queue[front]);
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        if(front == MAX_SIZE - 1){
            front = 0;
        }else{
            front++;
        }
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("Current queue: ");
    int i = front;
    if(front <= rear){
        while(i <= rear){
            printf("%d ", queue[i]);
            i++;
        }
    }else{
        while(i <= MAX_SIZE - 1){
            printf("%d ", queue[i]);
            i++;
        }
        i=0;
        while(i <= rear){
            printf("%d ", queue[i]);
            i++;
        }
    }
    printf("\n");
}

int main(){
    printf("Queue Implementation in C\n");
    printf("----------------------------\n");
    printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    
    while(1){
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice == 1){
            int element;
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
        }else if(choice == 2){
            dequeue();
        }else if(choice == 3){
            display();
        }else if(choice == 4){
            printf("Exiting the program\n");
            exit(0);
        }else{
            printf("Invalid Input!\n");
        }
    }
    return 0;
}