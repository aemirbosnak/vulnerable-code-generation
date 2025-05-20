//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MIN_FLOORS 2

// Define the elevator struct
typedef struct {
    int currentFloor;
    int destFloor;
    int isMoving;
} Elevator;

// Define the floor queue struct
typedef struct {
    int floor;
    struct FloorQueue *next;
} FloorQueue;

// Add a floor to the queue
void addToQueue(FloorQueue **head, int newFloor) {
    FloorQueue *newNode = malloc(sizeof(FloorQueue));
    newNode->floor = newFloor;
    newNode->next = *head;
    *head = newNode;
}

// Move the elevator to the next floor
void moveElevator(Elevator *elevator, FloorQueue **queue) {
    if (*queue == NULL) {
        elevator->isMoving = 0;
        printf("Elevator is now idle.\n");
        return;
    }
    int floorDiff = (*queue)->floor - elevator->currentFloor;
    if (floorDiff > 0) {
        printf("Elevator moving up to floor %d.\n", (*queue)->floor);
    } else if (floorDiff < 0) {
        printf("Elevator moving down to floor %d.\n", (*queue)->floor);
    }
    elevator->currentFloor = (*queue)->floor;
    FloorQueue *temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

// Print the elevator status
void printStatus(Elevator *elevator, FloorQueue *queue) {
    printf("Elevator is currently on floor %d.\n", elevator->currentFloor);
    if (elevator->isMoving) {
        printf("Elevator is currently moving to floor %d.\n", queue->floor);
    } else {
        printf("Elevator is currently idle.\n");
    }
    printf("Queue: ");
    FloorQueue *temp = queue;
    while (temp != NULL) {
        printf("%d ", temp->floor);
        temp = temp->next;
    }
    printf("\n\n");
}

int main() {
    int numFloors = 0;
    while (numFloors < MIN_FLOORS || numFloors > MAX_FLOORS) {
        printf("Enter the number of floors in the building (between %d and %d): ", MIN_FLOORS, MAX_FLOORS);
        scanf("%d", &numFloors);
    }

    Elevator myElevator = {1, 1, 0};
    FloorQueue *queueHead = NULL;

    int choice = 0;
    int newDestination = 0;

    while (1) {
        printStatus(&myElevator, queueHead);
        printf("1. Add a destination floor\n");
        printf("2. Move the elevator\n");
        printf("3. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                while (newDestination < 1 || newDestination > numFloors || newDestination == myElevator.currentFloor) {
                    printf("Enter the destination floor (between 1 and %d, not the current floor): ", numFloors);
                    scanf("%d", &newDestination);
                }
                addToQueue(&queueHead, newDestination);
                newDestination = 0;
                break;
            case 2:
                if (!myElevator.isMoving && queueHead != NULL) {
                    myElevator.destFloor = queueHead->floor;
                    myElevator.isMoving = 1;
                }
                moveElevator(&myElevator, &queueHead);
                break;
            case 3:
                printf("Quitting program.\n");
                return 0;
            default:
                printf("Invalid choice, please enter 1, 2, or 3.\n");
                break;
        }
    }
}