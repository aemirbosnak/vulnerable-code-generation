//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <stdbool.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int currentFloor;
    int passengers;
} Elevator;

void displayElevatorStatus(Elevator elevator) {
    printf("\n🚀 Current Floor: %d\n", elevator.currentFloor);
    printf("👨‍👩‍👦 Current Passengers: %d/%d\n", elevator.passengers, MAX_CAPACITY);
}

void callElevator(Elevator *elevator, int targetFloor) {
    printf("📞 Calling elevator to floor %d...\n", targetFloor);
    while (elevator->currentFloor != targetFloor) {
        if (elevator->currentFloor < targetFloor) {
            elevator->currentFloor++;
            printf("🔼 Elevator going up to floor %d...\n", elevator->currentFloor);
        } else {
            elevator->currentFloor--;
            printf("🔽 Elevator going down to floor %d...\n", elevator->currentFloor);
        }
        sleep(1);
    }
    printf("🎉 Elevator has arrived at floor %d!\n", elevator->currentFloor);
}

void enterElevator(Elevator *elevator) {
    if (elevator->passengers < MAX_CAPACITY) {
        elevator->passengers++;
        printf("🙋‍♂️ A new passenger entered the elevator! Now we have %d passengers.\n", elevator->passengers);
    } else {
        printf("🚫 Sorry! The elevator is at full capacity!\n");
    }
}

void exitElevator(Elevator *elevator) {
    if (elevator->passengers > 0) {
        elevator->passengers--;
        printf("🙋 A passenger has exited the elevator! Now we have %d passengers.\n", elevator->passengers);
    } else {
        printf("🚪 The elevator is empty! No one to exit.\n");
    }
}

void goToFloor(Elevator *elevator, int targetFloor) {
    printf("🛗 Going to floor %d...\n", targetFloor);
    callElevator(elevator, targetFloor);
}

int main() {
    Elevator elevator = {0, 0};
    int choice, targetFloor;

    printf("🎈 Welcome to the Fun Elevator Simulation! 🎈\n");
    printf("You can call the elevator, enter, exit, or go to a desired floor!\n");

    while (true) {
        displayElevatorStatus(elevator);
        printf("\nChoose an option:\n");
        printf("1. Call Elevator\n");
        printf("2. Enter Elevator\n");
        printf("3. Exit Elevator\n");
        printf("4. Go to Floor\n");
        printf("5. Exit Simulation\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the floor to call the elevator to (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &targetFloor);
                if (targetFloor >= 0 && targetFloor < MAX_FLOORS) {
                    callElevator(&elevator, targetFloor);
                } else {
                    printf("🚨 Invalid floor! Please enter a number between 0 and %d.\n", MAX_FLOORS - 1);
                }
                break;

            case 2:
                enterElevator(&elevator);
                break;

            case 3:
                exitElevator(&elevator);
                break;

            case 4:
                printf("Enter the floor to go to (0 to %d): ", MAX_FLOORS - 1);
                scanf("%d", &targetFloor);
                if (targetFloor >= 0 && targetFloor < MAX_FLOORS) {
                    goToFloor(&elevator, targetFloor);
                } else {
                    printf("🚨 Invalid floor! Please enter a number between 0 and %d.\n", MAX_FLOORS - 1);
                }
                break;

            case 5:
                printf("🎉 Thank you for using the Fun Elevator Simulation! Goodbye! 👋\n");
                exit(0);
                break;

            default:
                printf("❌ Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}