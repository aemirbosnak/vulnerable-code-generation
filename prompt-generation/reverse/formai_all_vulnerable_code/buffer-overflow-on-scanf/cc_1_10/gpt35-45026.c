//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_FLIGHTS 5

typedef struct {
    int flight_number;
    int num_bags;
} Flight;

typedef struct {
    int bag_id;
    int flight_number;
} Bag;

int main() {
    int num_flights;
    Flight flights[MAX_FLIGHTS];
    Bag bags[MAX_BAGS];
    int total_bags = 0;
    int num_bags_loaded = 0;

    printf("Welcome to the Happy Airport Baggage Handling Simulation!\n\n");

    // Input number of flights and number of bags for each flight
    printf("Please enter the number of flights: ");
    scanf("%d", &num_flights);

    for (int i = 0; i < num_flights; i++) {
        printf("Please enter the flight number for flight %d: ", i+1);
        scanf("%d", &flights[i].flight_number);

        printf("Please enter the number of bags for flight %d: ", i+1);
        scanf("%d", &flights[i].num_bags);
        total_bags += flights[i].num_bags;
    }

    // Generate unique bag IDs for each bag
    for (int i = 0; i < total_bags; i++) {
        bags[i].bag_id = i + 1;
    }

    // Shuffle the bags randomly
    srand(time(NULL));
    for (int i = total_bags-1; i > 0; i--) {
        int j = rand() % (i+1);

        Bag temp = bags[i];
        bags[i] = bags[j];
        bags[j] = temp;
    }

    // Load bags onto flights
    for (int i = 0; i < num_flights; i++) {
        printf("\n-- Loading bags for flight %d --\n\n", flights[i].flight_number);

        for (int j = 0; j < flights[i].num_bags; j++) {
            printf("Loading bag with ID %d onto flight %d...\n", bags[num_bags_loaded].bag_id, flights[i].flight_number);
            bags[num_bags_loaded].flight_number = flights[i].flight_number;
            num_bags_loaded++;
        }

        printf("\n");
    }

    // Output bag IDs and flight numbers
    printf("\n-- Summary of loaded bags --\n\n");
    for (int i = 0; i < num_bags_loaded; i++) {
        printf("Bag %d is loaded onto flight %d\n", bags[i].bag_id, bags[i].flight_number);
    }

    return 0;
}