//FormAI DATASET v1.0 Category: Queue Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

struct queue{
    int data[MAX];
    int front;
    int rear;            
};

void init(struct queue* pq){
    pq->front = -1;
    pq->rear = -1;
}

int isFull(struct queue* pq){
    if(pq->front == (pq->rear + 1) % MAX){  // Checking if front and rear are at the same index
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue* pq){
    if(pq->front == -1 && pq->rear == -1){  // Checking if the queue is empty
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* pq, int x){
    if(isFull(pq)){                         //If queue is full, print an error message
        printf("Queue is full!\n");
    }
    else if(isEmpty(pq)){                   //If the queue is empty, set front and rear to index 0 and add the element
        pq->front = 0;
        pq->rear = 0;
        pq->data[pq->rear] = x;
    }
    else{
        pq->rear = (pq->rear + 1) % MAX;    //Otherwise move rear to the next index in a circular fashion and add the element
        pq->data[pq->rear] = x;            
    }
}

void dequeue(struct queue* pq){
    if(isEmpty(pq)){                       //If queue is empty, print an error message
        printf("Queue is empty!\n");
    }
    else if(pq->front == pq->rear){        //If there is only one element in the queue, set front and rear to -1
        pq->front = -1;
        pq->rear = -1;
    }
    else{
        pq->front = (pq->front + 1) % MAX;  //Otherwise move front to the next index in a circular fashion
    }
}

void display(struct queue* pq){
    int i;
    if(isEmpty(pq)){                      //If queue is empty, print an error message
        printf("Queue is empty!\n");
    }
    else{
        printf("Queue elements are:\n");
        i = pq->front;
        while(i != pq->rear){              //While i is not equal to rear, print the element and move to the next index in a circular fashion
            printf("%d ", pq->data[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", pq->data[pq->rear]); //Print the last element
    }
}

int main(){

    struct queue q;
    init(&q);
    int choice, x;

    printf("*****QUEUE PROGRAM*****\n");

    do{
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                enqueue(&q, x);
                break;

            case 2:
                dequeue(&q);
                break;
                
            case 3:
                display(&q);
                break;
                
            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }

    }while(choice != 4);

    return 0;
}