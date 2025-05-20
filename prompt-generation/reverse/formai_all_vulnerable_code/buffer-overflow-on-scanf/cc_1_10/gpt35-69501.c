//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CAPACITY 20           // maximum capacity of the conveyor belt
#define MAX_FLIGHTS 5             // maximum number of flights
#define MAX_CHECKIN_BELT 30       // maximum capacity of the check-in conveyor belt

// Function to generate random flights
int generateRandomFlight() {
    return rand() % MAX_FLIGHTS + 1;  // return a random number between 1 to MAX_FLIGHTS
}

int main() {
    int conveyorBelt[MAX_CAPACITY];             // conveyor belt to store the baggage
    int checkInBelt[MAX_CHECKIN_BELT];           // check-in conveyor belt to store the baggage
    int flightBaggageCount[MAX_FLIGHTS] = {0};   // to count the number of baggage for each flight
    int conveyorHead = 0, conveyorTail = 0;      // pointers to point to the head and tail of conveyor belt
    int checkInHead = 0, checkInTail = 0;        // pointers to point to the head and tail of check-in conveyor belt
    int numOfFlights = 0, currentFlight = 0;     // to store current number of flights and current flight being processed
    
    srand(time(NULL));  // seeding random number generator with current time    
    
    // accepting input for the number of flights and validity check
    do {
        printf("Enter number of flights (max %d): ", MAX_FLIGHTS);
        scanf("%d",&numOfFlights);
    } while(numOfFlights < 1 || numOfFlights > MAX_FLIGHTS);
    
    printf("\nSimulating baggage handling for %d flights...\n\n", numOfFlights);
    
    // processing baggage for each flight
    for(currentFlight=1; currentFlight<=numOfFlights; currentFlight++) {
        printf("Processing baggage for Flight No: %d\n", currentFlight);
        
        // Generating random number of baggage for current flight
        int numOfBaggage = rand() % 11 + 10;   // generating a random number between 10 and 20 luggage items
        printf("Total baggage for Flight No %d: %d\n", currentFlight, numOfBaggage);
        flightBaggageCount[currentFlight-1] = numOfBaggage;    // storing the baggage count for current flight
        
        // Checking if check-in conveyor belt has space
        if((checkInTail - checkInHead) < MAX_CHECKIN_BELT) {
            printf("Adding baggage of Flight No %d to the Check-in conveyor belt.\n", currentFlight);
            for(int i=0; i<numOfBaggage; i++) {
                // filling up the check-in conveyor belt
                checkInBelt[checkInTail++] = currentFlight; 
            }
        }
        else {
            printf("No space available in Check-in conveyor belt. Please wait for some time.\n");
        }
        
        // Check-in conveyor belt simulation
        printf("\nChecking-in baggage for Flight No %d...\n", currentFlight);
        int baggageCount = 0; // to keep count of number of baggage checked in
        while(baggageCount < numOfBaggage) {
            // Checking if baggage is present on the conveyor belt
            if(conveyorHead != conveyorTail) {
                int currentBaggage = conveyorBelt[conveyorHead++];  // removing baggage from conveyor belt
                printf("Baggage %d of Flight No %d checked-in.\n",baggageCount+1, currentBaggage);
                baggageCount++;
            }
            else {
                printf("No more baggage for Flight No %d found on conveyor belt. Please wait for some time.\n", currentFlight);
            }
        }
        printf("\nBaggage check-in completed for Flight No %d.\n\n", currentFlight);
        
        // Unloading the baggage from check-in conveyor belt to the conveyor belt
        printf("Unloading baggage from Check-in conveyor belt to Conveyor belt...\n");
        while(checkInHead != checkInTail && conveyorTail < MAX_CAPACITY) {
            // emptying the check-in belt and filling up the conveyor belt
            conveyorBelt[conveyorTail++] = checkInBelt[checkInHead++];
        }
        printf("Unloading completed.\n\n");
        
    }
    
    // Printing final statistics
    printf("\nBaggage handling statistics:\n\n");
    for(int i=0; i<MAX_FLIGHTS; i++) {
        printf("Flight No %d: %d baggage\n", i+1, flightBaggageCount[i]);
    }
    printf("\n");
    printf("Total baggage handled: %d\n", conveyorTail);
    printf("Total baggage not handled: %d\n", (flightBaggageCount[0] + flightBaggageCount[1] + 
                                               flightBaggageCount[2] + flightBaggageCount[3] + flightBaggageCount[4]) -
                                               conveyorTail);
    return 0;
}