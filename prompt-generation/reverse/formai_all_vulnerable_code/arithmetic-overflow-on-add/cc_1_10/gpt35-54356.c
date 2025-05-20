//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    int num_passengers;
    int num_bags;
    int weight_limit;
    int bag_num = 1;
    int total_weight = 0;
    int i, j, k;
    srand(time(NULL));
    
    // Getting input from user
    printf("Enter the number of passengers: ");
    scanf("%d", &num_passengers);
    printf("Enter the number of bags per passenger: ");
    scanf("%d", &num_bags);
    printf("Enter the weight limit per bag (in kg): ");
    scanf("%d", &weight_limit);
    
    // Creating and populating 2D array to represent all bags
    int bags[num_passengers][num_bags];
    for (i = 0; i < num_passengers; i++) {
        for (j = 0; j < num_bags; j++) {
            bags[i][j] = (rand() % weight_limit) + 1;
            total_weight += bags[i][j];
        }
    }
    
    // Outputting information to user
    printf("There are %d passengers, each with %d bags weighing up to %d kg.\n", num_passengers, num_bags, weight_limit);
    printf("There are a total of %d bags with a combined weight of %d kg.\n\n", num_passengers * num_bags, total_weight);
    
    // Simulating baggage handling process
    for (i = 0; i < num_passengers; i++) {
        printf("Passenger %d has the following bags: ", i+1);
        for (j = 0; j < num_bags; j++) {
            printf("%dkg ", bags[i][j]);
            if (bags[i][j] > weight_limit) {
                printf("(Bag is over the weight limit!)\n");
            } else {
                printf("\n");
            }
            bag_num++;
        }
    }
    printf("\n");
    
    // Checking for bags over weight limit
    int over_limit_counter = 0;
    for (i = 0; i < num_passengers; i++) {
        for (j = 0; j < num_bags; j++) {
            if (bags[i][j] > weight_limit) {
                over_limit_counter++;
            }
        }
    }
    
    // Outputting results of simulation
    if (over_limit_counter > 0) {
        printf("There are %d bags over the weight limit and must be sent back to be repacked.\n", over_limit_counter);
    } else {
        printf("All bags are within the weight limit and can proceed to the next stage of handling.\n");
    }
    
    return 0;
}