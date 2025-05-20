//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: rigorous
#include<stdio.h>
#define MAX 5

struct baggage { //defining baggage structure
    int bag_num;
    int bag_weight;
};

struct conveyor_belt { //defining conveyor belt structure
    struct baggage belt[MAX]; //maximum bags capable of fitting
    int front, rear; //queue implementation for adding/deleting bags
};

void initialize(struct conveyor_belt*);
void add_bag(struct conveyor_belt*, int, int);
void remove_bag(struct conveyor_belt*);

void main(){
    struct conveyor_belt cb; //initializing conveyor belt
    int control_sum = 0, option;
    int bag_num, bag_weight;
    printf("\n=================================\n");
    printf("\nWelcome to the Airport Baggage Handling Simulation!\n");
    printf("\n=================================\n");
    initialize(&cb); //initializing empty conveyor belt
    do{
        printf("\nEnter the option: \n1. Add Baggage\n2. Remove Baggage\n3. Exit\n"); //options to add/delete/check bags
        scanf("%d",&option);
        switch(option){
            case 1: printf("Enter the baggage number and weight: ");
                    scanf("%d %d",&bag_num,&bag_weight);
                    add_bag(&cb,bag_num,bag_weight);
                    control_sum += bag_weight; //calculating the sum(used to monitor luggage processing statistics)
                    break;
            case 2: remove_bag(&cb);
                    break;
            case 3: printf("Exiting simulation ...\n");
                    break;
            default: printf("\nIncorrect Option ... Exit Program ...\n");
        }
    }while(option!=3);
    printf("\n=================================\n");
    printf("\nTotal luggage processed: %d kg\n",control_sum);
    printf("\n=================================\n");
}

void initialize(struct conveyor_belt* cb){ //initializing empty conveyor belt queue
    cb->front = -1;
    cb->rear = -1;
}

void add_bag(struct conveyor_belt* cb, int bag_num, int bag_weight){ //add baggage to the conveyor belt queue
    if (cb->rear == MAX - 1) //checking for overflow
    {
        printf("\nQueue Overflow... Please check back later\n");
        return;
    }
    else{
        if (cb->front == -1) //if queue is empty
            cb->front = 0;
        cb->rear++;
        //adding baggage information to the queue end
        cb->belt[cb->rear].bag_num = bag_num;
        cb->belt[cb->rear].bag_weight = bag_weight;
        printf("\nBaggage %d with weight %d kg added to the conveyor belt!\n",bag_num,bag_weight);
    }
}

void remove_bag(struct conveyor_belt* cb) //remove baggage from the conveyor belt queue
{
    int bag_num, bag_weight;
    if (cb->front == -1) //checking for underflow
    {
        printf("\nQueue Underflow... The queue is empty!\n");
        return;
    }
    else //if queue isn't empty
    {
        bag_num = cb->belt[cb->front].bag_num;
        bag_weight = cb->belt[cb->front].bag_weight;
        cb->front++;
        printf("\nBaggage %d with weight %d kg has been removed from the conveyor belt!\n",bag_num,bag_weight);
    }
}