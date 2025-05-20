//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure for Baggage
struct Baggage {
    int id;
    int weight;
    bool isLoaded;
};

// Structure for Conveyor Belt System
typedef struct {
    int size;
    int front; 
    int rear;  
    struct Baggage elements[MAX_SIZE];  
} conveyor;

// Function to initialize the conveyor belt system
void init(conveyor *q) {
    q->size = 0;
    q->front = 0;
    q->rear = -1;
}

// Function to check if the conveyor belt system is empty
bool isempty(conveyor *q) {
    return (q->size == 0);
}

// Function to check if the conveyor belt system is full
bool isfull(conveyor *q) {
    return (q->size == MAX_SIZE);
}

// Function to add a baggage to the conveyor belt system
void enqueue(conveyor *q, struct Baggage b) {
    if(isfull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    else {
        q->rear = (q->rear+1) % MAX_SIZE;
        q->elements[q->rear] = b;
        q->size++;
    }
}

// Function to remove a baggage from the conveyor belt system
struct Baggage dequeue(conveyor *q) {
    if(isempty(q)) {
        printf("Queue Underflow!\n");
        exit(EXIT_FAILURE);
    }
    else {
        struct Baggage removed = q->elements[q->front];
        q->front = (q->front+1) % MAX_SIZE;
        q->size--;
        return removed;
    }
}

// Function to display the conveyor belt system
void display(conveyor *q) {
    if(isempty(q))
        printf("Queue is Empty!\n");
    else {
        printf("Id\tWeight\tStatus\n");
        for(int i=q->front; i<=q->rear; i++) {
            printf("%d\t%d\t", q->elements[i].id, q->elements[i].weight);
            if(q->elements[i].isLoaded)
                printf("Loaded\n");
            else
                printf("Not Loaded\n");
        }
    }
}

// Main function
int main() {
    conveyor cq;
    init(&cq);
    int choice = 0;
    
    while(choice != 4) {
        printf("\n*********** Baggage Handling System ***********\n");
        printf("1. Add Baggage to Conveyor Belt System.\n");
        printf("2. Load Baggage to the Plane.\n");
        printf("3. Unload Baggage from the Plane.\n");
        printf("4. Exit the program.\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        
        switch(choice) {
            case 1: {
                struct Baggage b;
                printf("\nEnter Baggage Id: ");
                scanf("%d",&b.id);
                printf("Enter Baggage Weight: ");
                scanf("%d",&b.weight);
                b.isLoaded = false;
                enqueue(&cq,b);
                printf("\nBaggage Added to the Conveyor Belt System Successfully!!\n\n");
                display(&cq);
                break;
            }
            case 2: {
                if(isempty(&cq))
                    printf("\nConveyor Belt System is Empty!!\n\n");
                else {
                    struct Baggage loaded = dequeue(&cq);
                    loaded.isLoaded = true;
                    printf("\nBaggage Loaded to the Plane!!\n\n");
                    display(&cq);
                }
                break;
            }
            case 3: {
                struct Baggage unloaded;
                printf("\nEnter Baggage Id to Unload: ");
                scanf("%d",&unloaded.id);
                printf("Enter Baggage Weight to Unload: ");
                scanf("%d",&unloaded.weight);
                unloaded.isLoaded = false;
                enqueue(&cq,unloaded);
                printf("\nBaggage Unloaded from the Plane Successfully!!\n\n");
                display(&cq);
                break;
            }
            case 4:
                printf("\nExiting the Program!!\n");
                break;
            default:
                printf("\nInvalid Choice!! Please Try Again!!\n");
        }
    }
    return 0;
}