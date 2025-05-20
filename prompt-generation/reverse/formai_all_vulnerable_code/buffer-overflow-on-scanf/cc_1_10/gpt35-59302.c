//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LUGGAGE_SIZE 10 // maximum size of luggage handled by the system
#define MAX_LUGGAGE 100 // maximum amount of luggage the system can handle
#define MAX_FLIGHTS 10 // maximum number of flights to handle

// defining a luggage structure
struct luggage {
    int size;
    char destination[50];
};

// function to generate a random destination for luggage
char * generateDestination() {
    char * destinations[] = {"London", "New York", "Paris", "Dubai", "Tokyo", "Hong Kong", "Singapore", "Sydney", "Cairo", "Amsterdam"};
    return destinations[rand() % 10];
}

// function to generate a random size for luggage
int generateSize() {
    return rand() % MAX_LUGGAGE_SIZE + 1;
}

// function to display an array of luggage
void displayLuggage(struct luggage luggageArray[], int size) {
    for(int i=0; i<size; i++) {
        printf("Luggage %d: Destination - %s, Size - %d\n", i+1, luggageArray[i].destination, luggageArray[i].size);
    }
}

int main() {
    srand(time(0)); // initializing random number generator
    
    // initializing variables
    int numFlights, numLuggage;
    printf("Enter the number of flights: ");
    scanf("%d", &numFlights);
    printf("Enter the number of luggage for each flight: ");
    scanf("%d", &numLuggage);
    
    // creating an array of structures for each flight
    struct luggage flightLuggage[MAX_FLIGHTS][MAX_LUGGAGE];
    
    // filling the array with randomly generated luggage
    for(int i=0; i<numFlights; i++) {
        for(int j=0; j<numLuggage; j++) {
            struct luggage newLuggage;
            newLuggage.size = generateSize();
            strcpy(newLuggage.destination, generateDestination());
            flightLuggage[i][j] = newLuggage;
        }
    }
    
    // displaying the luggage for each flight
    for(int i=0; i<numFlights; i++) {
        printf("\nFlight %d:\n", i+1);
        displayLuggage(flightLuggage[i], numLuggage);
    }
    
    return 0; // program executed successfully
}