//FormAI DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX], front=-1, rear=-1;

void insert(){
    int val;
    if(rear==MAX-1)
        printf("\nQueue overflow.");
    else{
        if(front==-1)
            front=0;
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &val);
        rear++;
        queue[rear]=val;
        printf("\nElement inserted successfully.");
    }
}

void delete(){
    if(front==-1 || front>rear)
        printf("\nQueue underflow.");
    else{
        printf("\nElement deleted: %d", queue[front]);
        front++;
    }
}

void display(){
    if(front==-1)
        printf("\nQueue is empty.");
    else{
        printf("\nQueue elements are:\n");
        for(int i=front; i<=rear; i++)
            printf("%d\t", queue[i]);
    }
}

int main(){
    int ch;
    while(1){
        printf("\nQUEUE OPERATIONS:\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice. Try again.");
        }
    }

    return 0;
}