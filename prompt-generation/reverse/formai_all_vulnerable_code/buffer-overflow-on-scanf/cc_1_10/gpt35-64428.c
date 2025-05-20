//FormAI DATASET v1.0 Category: Queue Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5      //setting the size of queue as 5

int front=-1, rear=-1, q[SIZE];     //initializing front and rear to -1

void enqueue(int x){        //function to insert an element into the queue
    if(rear==SIZE-1){       
        printf("\nQueue is full!");        
    }
    else{
        rear++;
        q[rear]=x;
        if(front==-1){
            front=0;
        }
    }
}

void dequeue(){        //function to remove an element from the queue
    if(front==-1){
        printf("\nQueue is empty!");
    }
    else{
        printf("\nDeleted element is %d", q[front]);
        front++;
        if(front>rear){
            front=rear=-1;
        }
    }
}

void display(){         //function to display the elements in the queue
    int i;
    if(front==-1){
        printf("\nQueue is empty!");
    }
    else{
        printf("\nElements in the queue are: ");
        for(i=front;i<=rear;i++){
            printf("%d ", q[i]);
        }
    }
}

int main(){
    int ch, x;
    while(1){           //using a while loop to keep the program running until the user exits
        printf("\n1. Insert element");
        printf("\n2. Delete element");
        printf("\n3. Display queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){        //using switch case for different operations
            case 1: printf("\nEnter the element to be inserted: ");
                    scanf("%d", &x);
                    enqueue(x);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}