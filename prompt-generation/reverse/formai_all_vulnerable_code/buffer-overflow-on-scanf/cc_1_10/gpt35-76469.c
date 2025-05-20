//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5 // size of queue 

int Q[SIZE]; // array implementation of queue
int front = -1;
int rear = -1;

// function to check if queue is empty
int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }else{
        return 0;
    }
}

// function to check if queue is full
int isFull(){
    if(rear == SIZE - 1){
        return 1;
    }else{
        return 0;
    }
}

// function to add element to queue
void enQueue(int data){
    if(isFull()){
        printf("\nLIMBO IS FULL. ELEMENT CANNOT BE ADDED.");
    }else if(isEmpty()){
        front = rear = 0;
        Q[rear] = data;
        printf("\n%d IS NOW IN LIMBO.",data);
    }else{
        rear++;
        Q[rear] = data;
        printf("\n%d IS NOW IN LIMBO.",data);
    }
}

// function to remove element from queue
int deQueue(){
    int element;
    if(isEmpty()){
        printf("\nLIMBO IS EMPTY. NO ELEMENT TO REMOVE.");
        return(-1);
    }else if(front == rear){
        element = Q[front];
        front = rear = -1;
        printf("\n%d HAS LEFT LIMBO.",element);
        return(element);
    }else{
        element = Q[front];
        front++;
        printf("\n%d HAS LEFT LIMBO.",element);
        return(element);
    }
}

// function to display the elements in queue
void display(){
    if(isEmpty()){
        printf("\nLIMBO IS EMPTY. NO ELEMENTS TO DISPLAY.\n");
    }else{
        printf("\nTHE ELEMENTS IN LIMBO ARE:\n");
        for(int i=front;i<=rear;i++){
            printf("%d\t",Q[i]);
        }
    }
}

// main function to test the queue implementation
int main(){
    int choice, data;
    printf("WELCOME TO LIMBO - THE QUEUE OF THE RESTLESS SOULS\n");
    do{
        printf("\n\n1. Arrive at Limbo\n2. Leave Limbo\n3. Display the souls in Limbo\n4. Exit\n\nChoose your fate: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("\nEnter your soul id: ");
                scanf("%d",&data);
                enQueue(data);
                break;
            }
            case 2:{
                deQueue();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
                printf("\nYOU HAVE CHOSEN TO EXIT LIMBO. WE HOPE YOU FIND YOUR PEACE.\n");
                break;
            }
            default:{
                printf("\nINVALID CHOICE. PLEASE ENTER A VALID OPTION.\n");
            }
        }
    }while(choice!=4);

    return 0;
}