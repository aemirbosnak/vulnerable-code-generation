//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_BAGS_PER_FLIGHT 50

typedef struct {
    int baggage_id;
    int flight_number;
    int weight;
} baggage;

typedef struct {
    int flight_number;
    int num_bags;
    baggage bags[MAX_BAGS_PER_FLIGHT];
} flight;

int main() {
    srand(time(NULL)); // Seed random number generator with current timestamp
    
    flight flights[MAX_FLIGHTS];
    int num_flights;
    printf("Enter the number of flights to handle: ");
    scanf("%d", &num_flights);
    
    // Generate flights and their baggage
    for (int i = 0; i < num_flights; i++) {
        flights[i].flight_number = i + 1;
        flights[i].num_bags = rand() % (MAX_BAGS_PER_FLIGHT + 1); // Generate random number of bags for flight
        
        printf("Information for Flight %d:\n", flights[i].flight_number);
        
        if (flights[i].num_bags > 0) {
            printf("%d bags:\n", flights[i].num_bags);
        } else {
            printf("No bags.\n");
        }
        
        for (int j = 0; j < flights[i].num_bags; j++) {
            flights[i].bags[j].baggage_id = j + 1;
            flights[i].bags[j].flight_number = i + 1;
            flights[i].bags[j].weight = rand() % 51 + 1; // Generate random weight between 1 and 50 for bag
            
            printf("Baggage ID: %d, Weight: %d\n", flights[i].bags[j].baggage_id, flights[i].bags[j].weight);
        }
        
        printf("\n");
    }
    
    // Simulate baggage handling
    printf("---Starting Simulation---\n");
    for (int i = 0; i < num_flights; i++) {
        printf("\nHandling baggage for Flight %d...\n", flights[i].flight_number);
        
        for (int j = 0; j < flights[i].num_bags; j++) {
            printf("Handling Baggage %d...\n", flights[i].bags[j].baggage_id);
            // Do baggage handling tasks here...
        }
        
        printf("All baggage handled for Flight %d.\n", flights[i].flight_number);
    }
    printf("---Simulation Complete---\n");
    
    return 0;
}