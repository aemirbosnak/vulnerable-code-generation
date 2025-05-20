//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSENGERS 10
#define MAX_FLOORS 5

int main() {
    srand(time(NULL));
    
    char* passengerNames[MAX_PASSENGERS] = {
        "Ripperdoc",
        "Fixer",
        "Samurai",
        "Goth",
        "Nomad",
        "Netrunner",
        "Mercenary",
        "Corpo",
        "Techie",
        "Hacker"
    };
    
    int passengerSeat[MAX_PASSENGERS] = {0};
    int passengerDestination[MAX_PASSENGERS] = {0};
    int currentFloor = 1;
    
    printf("Welcome to the Cyberpunk Elevator Simulation!\n");
    printf("Press enter to start the simulation.\n");
    getchar();
    
    while (currentFloor <= MAX_FLOORS) {
        printf("Floor %d\n", currentFloor);
        for (int i = 0; i < MAX_PASSENGERS; i++) {
            if (passengerSeat[i] == 0) {
                printf("%s enters the elevator.\n", passengerNames[i]);
                passengerSeat[i] = 1;
                passengerDestination[i] = currentFloor;
            } else if (passengerSeat[i] == 1) {
                printf("%s has been sitting on the elevator.\n", passengerNames[i]);
            } else {
                printf("%s leaves the elevator.\n", passengerNames[i]);
                passengerSeat[i] = 0;
            }
        }
        
        printf("Enter the destination floor (1-%d): ", MAX_FLOORS);
        int destinationFloor = 0;
        scanf("%d", &destinationFloor);
        if (destinationFloor <= MAX_FLOORS && destinationFloor > currentFloor) {
            printf("%s arrives at floor %d.\n", passengerNames[rand() % MAX_PASSENGERS], destinationFloor);
            printf("All passengers have arrived at their destination.\n");
            currentFloor = destinationFloor;
        } else {
            printf("%s tries to access a floor that is not in service.\n", passengerNames[rand() % MAX_PASSENGERS]);
            printf("All passengers have arrived at their destination.\n");
            currentFloor = destinationFloor;
        }
    }
    
    printf("Goodbye from the Cyberpunk Elevator Simulation!\n");
    
    return 0;
}