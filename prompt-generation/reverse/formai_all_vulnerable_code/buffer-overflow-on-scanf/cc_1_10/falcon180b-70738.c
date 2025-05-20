//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char destination;
    int status;
} Baggage;

void generateRandomId(Baggage *baggage) {
    srand(time(NULL));
    baggage->id = rand() % 100000;
}

void printBaggage(Baggage baggage) {
    printf("Baggage ID: %d\n", baggage.id);
    printf("Destination: %c\n", baggage.destination);
    printf("Status: %d\n", baggage.status);
}

void main() {
    int numBaggage;
    printf("Enter the number of baggage: ");
    scanf("%d", &numBaggage);

    Baggage baggage[numBaggage];

    for(int i=0; i<numBaggage; i++) {
        printf("Enter the destination for baggage %d: ", i+1);
        scanf(" %c", &baggage[i].destination);
        generateRandomId(&baggage[i]);
        baggage[i].status = 0;
    }

    int numConveyors = 3;
    int conveyorCapacity = numBaggage / numConveyors;

    for(int i=0; i<numBaggage; i++) {
        int conveyorId = i / conveyorCapacity;
        int conveyorIndex = (conveyorId * conveyorCapacity) - 1;

        if(baggage[i].status == 0) {
            if(conveyorIndex >= numConveyors-1) {
                printf("Baggage %d is placed on conveyor %d.\n", i+1, conveyorId+1);
                baggage[i].status = 1;
            } else {
                printf("Baggage %d is waiting to be placed on conveyor %d.\n", i+1, conveyorId+1);
            }
        } else if(baggage[i].status == 1) {
            if(conveyorIndex >= numConveyors-1) {
                printf("Baggage %d has reached the end of conveyor %d.\n", i+1, conveyorId+1);
                baggage[i].status = 2;
            } else {
                printf("Baggage %d is moving on conveyor %d.\n", i+1, conveyorId+1);
            }
        } else if(baggage[i].status == 2) {
            printf("Baggage %d is ready for pickup at conveyor %d.\n", i+1, conveyorId+1);
        }
    }
}