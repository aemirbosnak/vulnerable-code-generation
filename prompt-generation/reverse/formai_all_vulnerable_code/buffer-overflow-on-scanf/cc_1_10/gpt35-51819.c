//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000

// struct for flights
struct Flight {
    int id; // unique identifier for flight
    int bags[MAX_BAGS]; // array of bag IDs for that flight
    int num_bags; // number of bags for that flight
    int arrived; // flag indicating whether or not flight has arrived
};

// struct for bags
struct Bag {
    int id; // unique identifier for bag
    int flight_id; // ID of flight bag is associated with
};

// function prototype for baggage handler
void baggage_handler(int num_flights, int num_bags_per_flight);

int main() {
    int num_flights, num_bags_per_flight;
    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    printf("Please enter the number of flights: ");
    scanf("%d", &num_flights);
    printf("Please enter the number of bags per flight: ");
    scanf("%d", &num_bags_per_flight);
    baggage_handler(num_flights, num_bags_per_flight);
    return 0;
}

void baggage_handler(int num_flights, int num_bags_per_flight) {
    // initialize flights
    struct Flight flights[num_flights];
    for (int i = 0; i < num_flights; i++) {
        flights[i].id = i+1; // set flight ID
        flights[i].num_bags = num_bags_per_flight; // set number of bags for each flight
        flights[i].arrived = 0; // set initial arrived flag to 0
        // generate bag IDs for each flight
        for (int j = 0; j < num_bags_per_flight; j++) {
            flights[i].bags[j] = (i*num_bags_per_flight)+j+1;
        }
    }

    // initialize bags
    struct Bag bags[num_flights*num_bags_per_flight];
    for (int i = 0; i < num_flights*num_bags_per_flight; i++) {
        bags[i].id = i+1; // set bag ID
        bags[i].flight_id = ((i/num_bags_per_flight)+1); // set flight ID for each bag
    }

    // randomly shuffle bags for each flight
    srand(time(NULL));
    for (int i = 0; i < num_flights; i++) {
        for (int j = num_bags_per_flight-1; j > 0; j--) {
            int k = rand() % (j+1);
            int temp = flights[i].bags[j];
            flights[i].bags[j] = flights[i].bags[k];
            flights[i].bags[k] = temp;
        }
    }

    // randomly shuffle flights
    for (int i = num_flights-1; i > 0; i--) {
        int j = rand() % (i+1);
        struct Flight temp = flights[i];
        flights[i] = flights[j];
        flights[j] = temp;
    }

    // simulate flights arriving and bags being loaded on conveyor belt
    printf("\nFlights are now arriving and bags are being loaded on the conveyor belt...\n");
    for (int i = 0; i < num_flights; i++) {
        flights[i].arrived = 1; // set arrived flag for flight to 1
        printf("Flight %d has arrived!\n", flights[i].id);
        printf("Bags for Flight %d: ", flights[i].id);
        for (int j = 0; j < num_bags_per_flight; j++) {
            int bag_index = ((flights[i].id-1)*num_bags_per_flight)+j;
            printf("%d ", bags[bag_index].id);
        }
        printf("\n");
    }

    // simulate bags being picked up from conveyor belt by passengers
    printf("\nPassengers are now picking up bags from the conveyor belt...\n");
    for (int i = 0; i < num_flights; i++) {
        printf("Bags for Flight %d: ", flights[i].id);
        for (int j = 0; j < num_bags_per_flight; j++) {
            int bag_index = ((flights[i].id-1)*num_bags_per_flight)+j;
            printf("%d ", bags[bag_index].id);
        }
        printf("\n");
    }

    // simulate bags being loaded onto planes by baggage handlers
    printf("\nBaggage handlers are now loading bags onto planes...\n");
    for (int i = 0; i < num_flights; i++) {
        printf("Bags for Flight %d being loaded onto plane...\n", flights[i].id);
    }

    printf("\nAll bags have been loaded onto the planes. Have a safe flight!\n");
}