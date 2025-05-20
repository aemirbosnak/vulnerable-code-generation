//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 10 // number of bags to be simulated
#define MAX_WEIGHT 50 // maximum weight of a bag in kgs
#define MAX_FLIGHTS 5 // maximum number of flights
#define MAX_BAGS_PER_FLIGHT 100 // maximum number of bags per flight
#define MAX_DESTINATIONS 3 // maximum number of destinations

// function to generate random integers
int random_int(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// struct to represent a bag
typedef struct {
    int id; // bag id
    int weight; // bag weight in kgs
    int flight_num; // flight number
    char destination[3]; // destination airport code
} Bag;

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // array of bags to be transported
    Bag bags[NUM_BAGS];
    
    // variable to keep track of number of bags handled
    int num_bags_handled = 0;
    
    // array of flights and their bags
    int num_flights = random_int(1, MAX_FLIGHTS); // number of flights
    int num_bags_per_flight[num_flights]; // number of bags per flight
    Bag flights[num_flights][MAX_BAGS_PER_FLIGHT]; // array to store the bags for each flight
    
    // generate the bags
    for (int i = 0; i < NUM_BAGS; i++) {
        Bag bag;
        bag.id = i + 1;
        bag.weight = random_int(1, MAX_WEIGHT);
        bag.flight_num = random_int(1, num_flights);
        sprintf(bag.destination, "D%d", random_int(1, MAX_DESTINATIONS));
        bags[i] = bag;
    }
    
    // sort the bags by flight number
    for (int i = 0; i < NUM_BAGS; i++) {
        for (int j = i + 1; j < NUM_BAGS; j++) {
            if (bags[j].flight_num < bags[i].flight_num) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
    
    // assign the bags to flights
    int current_flight = 1; // current flight number being processed
    int current_bag_index = 0; // index of the next available slot in the flights array
    for (int i = 0; i < NUM_BAGS; i++) {
        if (bags[i].flight_num != current_flight) {
            num_bags_per_flight[current_flight - 1] = current_bag_index; // store the number of bags for the current flight
            current_flight = bags[i].flight_num; // update the current flight number
            current_bag_index = 0; // reset the bag index
        }
        flights[current_flight - 1][current_bag_index] = bags[i]; // assign the bag to the current flight
        current_bag_index++; // increment the bag index
        num_bags_handled++; // increment the number of bags handled
    }
    num_bags_per_flight[current_flight - 1] = current_bag_index; // store the number of bags for the last flight
    
    // display the number of bags handled and the bags assigned to each flight
    printf("Number of bags handled: %d\n\n", num_bags_handled);
    for (int i = 0; i < num_flights; i++) {
        printf("Flight %d (%d bags) to %s\n", i + 1, num_bags_per_flight[i], flights[i][0].destination);
        for (int j = 0; j < num_bags_per_flight[i]; j++) {
            printf("\tBag %d (weight: %d kgs)\n", flights[i][j].id, flights[i][j].weight);
        }
        printf("\n");
    }
    
    return 0;
}