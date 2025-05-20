//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>

// Constants for elevator and floors
#define NUM_FLOORS 10
#define ELEV_CAPACITY 8

// States for elevator object
#define IDLE 0
#define UP 1
#define DOWN 2

// Elevator object type
typedef struct {
    int currentFloor;
    int state;
    int numPassengers;
    int passengers[ELEV_CAPACITY];
} Elevator;

// Function prototypes
void initializeElevator(Elevator *elevator);
void simulateElevator(Elevator *elevator);

int main() {
    // Create elevator object
    Elevator elevator;
    
    // Initialize elevator object
    initializeElevator(&elevator);
    
    // Simulate elevator behavior
    simulateElevator(&elevator);
    
    return 0;
}

// Initialize elevator object
void initializeElevator(Elevator *elevator) {
    elevator->currentFloor = 1;
    elevator->state = IDLE;
    elevator->numPassengers = 0;
    
    // Initialize passengers array to -1
    for(int i = 0; i < ELEV_CAPACITY; i++) {
        elevator->passengers[i] = -1;
    }
}

// Simulate elevator behavior
void simulateElevator(Elevator *elevator) {
    int destination, passengerCount;
    
    while(1) {
        printf("Elevator at floor %d\n", elevator->currentFloor);
        
        // Check if any passengers need to exit at current floor
        for(int i = 0; i < ELEV_CAPACITY; i++) {
            if(elevator->passengers[i] == elevator->currentFloor) {
                elevator->passengers[i] = -1;
                elevator->numPassengers--;
                printf("Passenger %d has exited at floor %d\n", i, elevator->currentFloor);
            }
        }
        
        // Check if elevator is full
        if(elevator->numPassengers == ELEV_CAPACITY) {
            printf("Elevator is full\n");
            continue;
        }
        
        // Check for passengers waiting at current floor
        printf("Enter number of passengers waiting: ");
        scanf("%d", &passengerCount);
        
        if(passengerCount > 0) {
            printf("Enter destination(s) for passengers (separated by spaces): ");
            for(int i = 0; i < passengerCount; i++) {
                scanf("%d", &destination);
                
                // Add passenger if there's room
                if(elevator->numPassengers < ELEV_CAPACITY) {
                    printf("Passenger %d has entered elevator\n", elevator->numPassengers);
                    elevator->passengers[elevator->numPassengers] = destination;
                    elevator->numPassengers++;
                } else {
                    printf("Elevator is full, passenger %d has not entered\n", i);
                }
            }
        }
        
        // Check for floors above and below with passengers waiting
        int upQueue[NUM_FLOORS];
        int downQueue[NUM_FLOORS];
        int upCount = 0, downCount = 0;
        
        for(int i = 1; i <= NUM_FLOORS; i++) {
            upQueue[i-1] = 0;
            downQueue[i-1] = 0;
        }
        
        for(int i = 0; i < ELEV_CAPACITY; i++) {
            if(elevator->passengers[i] > elevator->currentFloor) {
                upQueue[elevator->passengers[i]-1]++;
                upCount++;
            } else if(elevator->passengers[i] < elevator->currentFloor) {
                downQueue[elevator->passengers[i]-1]++;
                downCount++;
            }
        }
        
        if(upCount > 0) {
            elevator->state = UP;
        } else if(downCount > 0) {
            elevator->state = DOWN;
        } else {
            elevator->state = IDLE;
        }
        
        int destinationFloor = 0;
        
        if(elevator->state == UP) {
            printf("Elevator is going up\n");
            
            // Find floor with most passengers waiting to go up
            for(int i = elevator->currentFloor; i < NUM_FLOORS; i++) {
                if(upQueue[i] > upQueue[destinationFloor]) {
                    destinationFloor = i;
                }
            }
            
            // If no passengers waiting up, find floor with passengers waiting to go down
            if(destinationFloor == elevator->currentFloor) {
                for(int i = elevator->currentFloor; i >= 1; i--) {
                    if(downQueue[i-1] > downQueue[destinationFloor-1]) {
                        destinationFloor = i;
                        elevator->state = DOWN;
                    }
                }
            }
        } else if(elevator->state == DOWN) {
            printf("Elevator is going down\n");
            
            // Find floor with most passengers waiting to go down
            for(int i = elevator->currentFloor-2; i >= 0; i--) {
                if(downQueue[i] > downQueue[destinationFloor]) {
                    destinationFloor = i+1;
                }
            }
            
            // If no passengers waiting down, find floor with passengers waiting to go up
            if(destinationFloor == elevator->currentFloor) {
                for(int i = elevator->currentFloor; i < NUM_FLOORS; i++) {
                    if(upQueue[i] > upQueue[destinationFloor-1]) {
                        destinationFloor = i+1;
                        elevator->state = UP;
                    }
                }
            }
        } else {
            printf("Elevator is idle\n");
        }
        
        if(destinationFloor != elevator->currentFloor) {
            printf("Elevator moving to floor %d\n", destinationFloor);
            elevator->currentFloor = destinationFloor;
        } else {
            printf("Elevator is already at destination floor\n");
        }
    }
}