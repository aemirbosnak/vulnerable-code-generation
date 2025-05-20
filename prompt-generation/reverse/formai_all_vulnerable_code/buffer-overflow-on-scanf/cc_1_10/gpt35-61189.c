//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
Airport baggage handling simulation
Each passenger has a maximum of 2 bags (excluding carry-on)
We will assume each passenger has only one destination and each flight has only one destination airport

*/

#define MAX_PASSENGERS 100 // maximum capacity of the plane
#define MAX_DESTINATIONS 3 // maximum destinations a passenger can choose from
#define MAX_BAGS 2 // maximum number of bags per passenger

struct Baggage {
    char id[10]; // unique identifier for bag
    char destination[20]; // destination of the bag
};

struct Passenger {
    char name[20]; // name of the passenger
    char destination[20]; // destination of the passenger
    struct Baggage bags[MAX_BAGS]; // bags belonging to the passenger
    int num_of_bags; // number of bags belonging to the passenger
};

struct Flight {
    char destination[20]; // destination of the flight
    struct Passenger passengers[MAX_PASSENGERS]; // passengers on the flight
    int num_of_passengers; // number of passengers on the flight
};

int main() {
    // initialize variables
    struct Flight flight;
    int choice, i, j;
    
    // get destination of the flight
    printf("Enter the destination of the flight: ");
    scanf("%s", flight.destination);
    
    // ask for the number of passengers
    printf("Enter the number of passengers: ");
    scanf("%d", &flight.num_of_passengers);
    
    // loop through passengers
    for (i = 0; i < flight.num_of_passengers; i++) {
        printf("\n=====Passenger %d=====\n", i+1);
        printf("Enter the name of the passenger: ");
        scanf("%s", flight.passengers[i].name);
        
        // ask for destination of the passenger
        printf("Select the destination of the passenger (1: Destination 1, 2: Destination 2, 3: Destination 3): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                strcpy(flight.passengers[i].destination, "Destination 1");
                break;
            case 2:
                strcpy(flight.passengers[i].destination, "Destination 2");
                break;
            case 3:
                strcpy(flight.passengers[i].destination, "Destination 3");
                break;
            default:
                printf("Invalid choice\n");
                i--;
                continue;
        }
        
        // ask for number of bags
        printf("Enter the number of bags (maximum of 2 bags per passenger): ");
        scanf("%d", &flight.passengers[i].num_of_bags);
        if (flight.passengers[i].num_of_bags > 2) {
            printf("Maximum of 2 bags only\n");
            flight.passengers[i].num_of_bags = 2;
        }
        
        // loop through bags
        for (j = 0; j < flight.passengers[i].num_of_bags; j++) {
            printf("Enter the bag ID: ");
            scanf("%s", flight.passengers[i].bags[j].id);
            strcpy(flight.passengers[i].bags[j].destination, flight.passengers[i].destination); // set the destination of the bag to the destination of the passenger
        }
    }
    
    // display flight details
    printf("\n====Flight Details====\n");
    printf("Flight to %s with %d passengers\n\n", flight.destination, flight.num_of_passengers);
    for (i = 0; i < flight.num_of_passengers; i++) {
        printf("=====Passenger %d=====\n", i+1);
        printf("Name: %s\n", flight.passengers[i].name);
        printf("Destination: %s\n", flight.passengers[i].destination);
        printf("Number of bags: %d\n", flight.passengers[i].num_of_bags);
        for (j = 0; j < flight.passengers[i].num_of_bags; j++) {
            printf("Bag %d: ID: %s, Destination: %s\n", j+1, flight.passengers[i].bags[j].id, flight.passengers[i].bags[j].destination);
        }
        printf("\n");
    }
    
    return 0;
}