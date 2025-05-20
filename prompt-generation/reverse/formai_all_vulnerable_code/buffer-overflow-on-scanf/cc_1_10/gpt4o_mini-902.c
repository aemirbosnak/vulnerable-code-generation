//GPT-4o-mini DATASET v1.0 Category: Elevator Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FLOORS 10
#define MAX_CAPACITY 5

typedef struct {
    int floor;
    int passengers;
} Elevator;

void greet();
void operateElevator(Elevator *elevator);
void boardPassengers(Elevator *elevator);
void disembarkPassengers(Elevator *elevator);
void romanticMessage();

int main() {
    Elevator elevator = {0, 0};
    greet();
    operateElevator(&elevator);
    return 0;
}

void greet() {
    printf("Welcome to Love Lift, your romantic elevator journey!\n");
    printf("Let's embark on this enchanting adventure to the heights of passion...\n\n");
}

void operateElevator(Elevator *elevator) {
    int destinationFloor;
    while (1) {
        printf("You are currently on the %d floor.\n", elevator->floor);
        romanticMessage();

        if (elevator->passengers < MAX_CAPACITY) {
            boardPassengers(elevator);
        } else {
            printf("The Lift is full of lovebirds! No more passengers can join.\n");
        }
        printf("Select your destination floor (0-%d, or -1 to exit): ", MAX_FLOORS - 1);
        scanf("%d", &destinationFloor);

        if (destinationFloor == -1) {
            printf("Exiting the Love Lift. May your love journey be eternal!\n");
            break;
        } else if (destinationFloor < 0 || destinationFloor >= MAX_FLOORS) {
            printf("Invalid floor! Please choose a floor between 0 and %d.\n", MAX_FLOORS - 1);
            continue;
        }

        printf("Moving from floor %d to %d...\n", elevator->floor, destinationFloor);
        sleep(2);  // Simulate movement time
        elevator->floor = destinationFloor;

        disembarkPassengers(elevator);
    }
}

void boardPassengers(Elevator *elevator) {
    int newPassengers;
    printf("How many passengers are ready to board (1-%d)? ", MAX_CAPACITY - elevator->passengers);
    scanf("%d", &newPassengers);

    if (newPassengers < 1 || newPassengers > (MAX_CAPACITY - elevator->passengers)) {
        printf("How unfortunate! Not a valid number of lovebirds...\n");
        return;
    }

    elevator->passengers += newPassengers;
    printf("%d lovely soul(s) have boarded the Love Lift. Total: %d.\n\n", newPassengers, elevator->passengers);
}

void disembarkPassengers(Elevator *elevator) {
    int departingPassengers;
    if (elevator->passengers > 0) {
        printf("How many passengers want to disembark the Love Lift? (1-%d): ", elevator->passengers);
        scanf("%d", &departingPassengers);

        if (departingPassengers < 1 || departingPassengers > elevator->passengers) {
            printf("Alas! Such a number cannot be.\n");
            return;
        }

        elevator->passengers -= departingPassengers;
        printf("%d loving heart(s) have departed from the Love Lift. Remaining: %d.\n\n", departingPassengers, elevator->passengers);
    } else {
        printf("No one is here to leave! The lift is still filled with love...\n");
    }
}

void romanticMessage() {
    printf("Every journey shared in this Love Lift must be cherished...\n");
    printf("As we rise together, our hearts intertwine in a symphony of love.\n");
    printf("Take a moment, hold hands, and share your sweetest whispers...\n");
    printf("Love is the elevator that lifts us to new heights.\n\n");
}