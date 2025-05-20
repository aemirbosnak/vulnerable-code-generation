//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int baggageCount = 0;
    int conveyorBeltCapacity = 5;
    int conveyorBeltContents[5] = {0};
    int checkInCapacity = 10;
    int gateCapacity = 10;
    int checkInContents[10] = {0};
    int gateContents[10] = {0};
    int conveyorBeltPointer = 0;
    int checkInPointer = 0;
    int gatePointer = 0;
    int passengersCheckedIn = 0;
    int passengersAtGate = 0;

    printf("Welcome to the post-apocalyptic airport baggage handling simulation.\n");
    printf("The world has gone to hell, but we're still flying.\n\n");

    while(1) {
        printf("What do you want to do?\n");
        printf("1. Add a bag to the conveyor belt\n");
        printf("2. Move a bag from the conveyor belt to check-in\n");
        printf("3. Move a bag from check-in to the gate\n");
        printf("4. Print current status\n");
        printf("5. Quit\n");

        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            // Add a bag to the conveyor belt
            if(baggageCount == conveyorBeltCapacity) {
                printf("Conveyor belt is full. Wait for it to move.\n");
                sleep(2);
                continue;
            }

            printf("Enter the weight of the bag in kg: ");
            int weight;
            scanf("%d", &weight);

            conveyorBeltContents[conveyorBeltPointer] = weight;
            conveyorBeltPointer = (conveyorBeltPointer + 1) % conveyorBeltCapacity;
            baggageCount++;
        } else if(choice == 2) {
            // Move a bag from the conveyor belt to check-in
            if(baggageCount == 0) {
                printf("There is no baggage on the conveyor belt.\n");
                sleep(2);
                continue;
            }

            int weight = conveyorBeltContents[conveyorBeltPointer];
            conveyorBeltContents[conveyorBeltPointer] = 0;
            conveyorBeltPointer = (conveyorBeltPointer + 1) % conveyorBeltCapacity;
            baggageCount--;

            if(passengersCheckedIn == checkInCapacity) {
                printf("Check-in is full. Wait for a passenger to board.\n");
                sleep(2);
                continue;
            }

            checkInContents[checkInPointer] = weight;
            checkInPointer = (checkInPointer + 1) % checkInCapacity;
            passengersCheckedIn++;
        } else if(choice == 3) {
            // Move a bag from check-in to the gate
            if(passengersCheckedIn == 0) {
                printf("There are no checked-in passengers.\n");
                sleep(2);
                continue;
            }

            int weight = checkInContents[checkInPointer];
            checkInContents[checkInPointer] = 0;
            checkInPointer = (checkInPointer + 1) % checkInCapacity;
            passengersCheckedIn--;

            if(passengersAtGate == gateCapacity) {
                printf("Gate is full. Wait for a passenger to board.\n");
                sleep(2);
                continue;
            }

            gateContents[gatePointer] = weight;
            gatePointer = (gatePointer + 1) % gateCapacity;
            passengersAtGate++;
        } else if(choice == 4) {
            // Print current status
            printf("Conveyor belt: ");
            for(int i = 0; i < conveyorBeltCapacity; i++) {
                printf("[%d] ", conveyorBeltContents[i]);
            }
            printf("\n");

            printf("Check-in: ");
            for(int i = 0; i < checkInCapacity; i++) {
                printf("[%d] ", checkInContents[i]);
            }
            printf("\n");

            printf("Gate: ");
            for(int i = 0; i < gateCapacity; i++) {
                printf("[%d] ", gateContents[i]);
            }
            printf("\n");

            printf("Passengers checked in: %d\n", passengersCheckedIn);
            printf("Passengers at gate: %d\n", passengersAtGate);
        } else if(choice == 5) {
            // Quit
            printf("Exiting the simulation...\n");
            break;
        } else {
            // Invalid choice
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}