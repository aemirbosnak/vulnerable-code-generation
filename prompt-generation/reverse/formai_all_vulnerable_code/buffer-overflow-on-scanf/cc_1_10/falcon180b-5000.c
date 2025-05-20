//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
    int baggageId;
    char destination[20];
    int flightId;
    int status;
}Baggage;

Baggage baggage[MAX];

void enqueue(int baggageId, char destination[20], int flightId){
    int rear = -1;
    for(int i=0; i<MAX; i++){
        if(baggage[i].status == 0){
            rear = i;
            break;
        }
    }
    if(rear == -1){
        printf("\n\t\tThe baggage system is full!!");
    }
    else{
        baggage[rear].baggageId = baggageId;
        strcpy(baggage[rear].destination, destination);
        baggage[rear].flightId = flightId;
        baggage[rear].status = 1;
        printf("\n\t\tBaggage with id %d has been added to the queue!!", baggageId);
    }
}

void dequeue(int flightId){
    int front = -1;
    for(int i=0; i<MAX; i++){
        if(baggage[i].flightId == flightId && baggage[i].status == 1){
            front = i;
            break;
        }
    }
    if(front == -1){
        printf("\n\t\tBaggage not found in the queue!!");
    }
    else{
        baggage[front].status = 0;
        printf("\n\t\tBaggage with id %d has been removed from the queue!!", baggage[front].baggageId);
    }
}

void display(){
    printf("\n\t\tBaggage ID\tDestination\tFlight ID\tStatus");
    for(int i=0; i<MAX; i++){
        if(baggage[i].status == 1){
            printf("\n\t\t%d\t\t%s\t\t%d\t\t1", baggage[i].baggageId, baggage[i].destination, baggage[i].flightId);
        }
    }
}

int main(){
    int choice, baggageId, flightId;
    char destination[20];
    do{
        printf("\n\t\tEnter your choice\n\t\t1.Add Baggage\n\t\t2.Remove Baggage\n\t\t3.Display Baggage\n\t\t4.Exit");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\n\t\tEnter baggage id\n\t\t");
                scanf("%d", &baggageId);
                printf("\n\t\tEnter destination\n\t\t");
                scanf("%s", destination);
                printf("\n\t\tEnter flight id\n\t\t");
                scanf("%d", &flightId);
                enqueue(baggageId, destination, flightId);
                break;
            case 2:
                printf("\n\t\tEnter flight id\n\t\t");
                scanf("%d", &flightId);
                dequeue(flightId);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\t\tInvalid choice!!");
        }
    }while(choice!= 4);
    return 0;
}