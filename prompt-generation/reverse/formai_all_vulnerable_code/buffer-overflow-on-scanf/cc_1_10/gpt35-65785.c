//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAP 6 //maximum capacity of elevator
#define MAX_FLOOR 12 //maximum floor the elevator can go to
#define WAIT_TIME 3 //time elevator waits at each floor

int queue[MAX_CAP]; //array to hold queue of floors
int front = -1, rear = -1; //pointers for queue
int currFloor = 1; //current floor of elevator

void enQueue(int floor) { //function to add floor to queue
    if(front == -1 && rear == -1) { //if queue is empty
        front++;
        rear++;
        queue[rear] = floor;
    }
    else if(rear == MAX_CAP - 1) { //if queue is full
        printf("Queue is full. Cannot add floor.\n");
    }
    else {
        rear++;
        queue[rear] = floor;
    }
}

int deQueue() { //function to remove floor from queue
    int floor;
    if(front == -1 || front > rear) { //if queue is empty
        floor = -1;
    }
    else {
        floor = queue[front];
        front++;
    }
    return floor;
}

void simulate() { //function to simulate elevator
    int nextFloor;
    while(front <= rear) { //while there are floors in the queue
        nextFloor = deQueue();
        if(nextFloor == -1 || nextFloor > MAX_FLOOR || nextFloor < 1) { //if floor is invalid
            printf("Invalid floor requested. Skipping...\n");
        }
        else if(nextFloor == currFloor) { //if elevator is already on requested floor
            printf("Elevator is already on floor %d\n", currFloor);
        }
        else {
            if(nextFloor > currFloor) { //if requested floor is above current floor
                printf("Elevator going up...\n");
                while(currFloor != nextFloor) { //while elevator is not at requested floor
                    currFloor++;
                    printf("Elevator at floor %d\n", currFloor);
                    sleep(WAIT_TIME); //wait
                }
            }
            else { //if requested floor is below current floor
                printf("Elevator going down...\n");
                while(currFloor != nextFloor) { //while elevator is not at requested floor
                    currFloor--;
                    printf("Elevator at floor %d\n", currFloor);
                    sleep(WAIT_TIME); //wait
                }
            }
            printf("Elevator arrived at floor %d\n", currFloor);
        }
    }
}

int main() {
    int choice, floor;
    while(1) { //Infinite loop until user decides to exit
        printf("\nElevator Simulation\n");
        printf("--------------------\n");
        printf("1. Add floor to queue\n");
        printf("2. Simulate elevator\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter floor to go to: ");
                scanf("%d", &floor);
                enQueue(floor);
                printf("Floor added to queue.\n");
                break;
            case 2:
                simulate();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}