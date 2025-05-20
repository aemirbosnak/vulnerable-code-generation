//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_OF_BAGGAGE_CONVEYORS 3
#define MAX_BAGGAGE_SIZE 30
#define MAX_TRAVEL_TIME 5
#define MAX_CAPACITY 100

struct BaggageConveyor
{
    int conveyorID;
    int currentSize;
    int travelTime;
    bool isFull;
};

struct Baggage
{
    int size;
    int originConveyorID;
};

struct BaggageConveyor conveyor1, conveyor2, conveyor3;
struct Baggage baggageArray[MAX_CAPACITY];
int numOfBags = 0;

void initializeConveyors();
void simulateConveyors(int numOfBagsToAdd, int numOfBagsToRemove);

int main()
{
    int numOfBagsToAdd, numOfBagsToRemove;

    srand(time(NULL));

    initializeConveyors();

    printf("Enter the number of bags to add and remove from the conveyor system: ");
    scanf("%d %d", &numOfBagsToAdd, &numOfBagsToRemove);

    simulateConveyors(numOfBagsToAdd, numOfBagsToRemove);

    return 0;
}

void initializeConveyors()
{
    conveyor1.conveyorID = 1;
    conveyor1.currentSize = 0;
    conveyor1.isFull = false;
    conveyor1.travelTime = (rand() % MAX_TRAVEL_TIME) + 1;

    conveyor2.conveyorID = 2;
    conveyor2.currentSize = 0;
    conveyor2.isFull = false;
    conveyor2.travelTime = (rand() % MAX_TRAVEL_TIME) + 1;

    conveyor3.conveyorID = 3;
    conveyor3.currentSize = 0;
    conveyor3.isFull = false;
    conveyor3.travelTime = (rand() % MAX_TRAVEL_TIME) + 1;
}

void addBaggageToConveyor(struct Baggage newBaggage)
{
    if (conveyor1.isFull && conveyor2.isFull && conveyor3.isFull) {
        printf("All baggage conveyors are currently full! Cannot add baggage.\n");
        return;
    }

    if (conveyor1.currentSize <= conveyor2.currentSize && conveyor1.currentSize <= conveyor3.currentSize) {
        conveyor1.currentSize += newBaggage.size;
        conveyor1.isFull = conveyor1.currentSize >= MAX_BAGGAGE_SIZE;
        newBaggage.originConveyorID = conveyor1.conveyorID;
    } else if (conveyor2.currentSize <= conveyor1.currentSize && conveyor2.currentSize <= conveyor3.currentSize) {
        conveyor2.currentSize += newBaggage.size;
        conveyor2.isFull = conveyor2.currentSize >= MAX_BAGGAGE_SIZE;
        newBaggage.originConveyorID = conveyor2.conveyorID;
    } else {
        conveyor3.currentSize += newBaggage.size;
        conveyor3.isFull = conveyor3.currentSize >= MAX_BAGGAGE_SIZE;
        newBaggage.originConveyorID = conveyor3.conveyorID;
    }

    baggageArray[numOfBags++] = newBaggage;
    printf("Added baggage of size %d to conveyor %d.\n", newBaggage.size, newBaggage.originConveyorID);
}

void removeBaggageFromConveyor()
{
    if (numOfBags == 0) {
        printf("No baggage is currently on the conveyor system! Cannot remove baggage.\n");
        return;
    }

    int randomBagIndex = rand() % numOfBags;
    struct Baggage removedBaggage = baggageArray[randomBagIndex];
    int conveyorID = removedBaggage.originConveyorID;

    if (conveyorID == 1) {
        conveyor1.currentSize -= removedBaggage.size;
        conveyor1.isFull = false;
    } else if (conveyorID == 2) {
        conveyor2.currentSize -= removedBaggage.size;
        conveyor2.isFull = false;
    } else {
        conveyor3.currentSize -= removedBaggage.size;
        conveyor3.isFull = false;
    }

    for (int i = randomBagIndex; i < numOfBags - 1; i++) {
        baggageArray[i] = baggageArray[i + 1];
    }

    numOfBags--;

    printf("Removed baggage of size %d from conveyor %d.\n", removedBaggage.size, conveyorID);
}

void simulateConveyors(int numOfBagsToAdd, int numOfBagsToRemove)
{
    for (int i = 0; i < numOfBagsToAdd; i++) {
        int randomBagSize = (rand() % MAX_BAGGAGE_SIZE) + 1;
        struct Baggage newBaggage = {randomBagSize, 0};
        addBaggageToConveyor(newBaggage);
    }

    for (int i = 0; i < numOfBagsToRemove; i++) {
        removeBaggageFromConveyor();
    }
}