//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100
#define MAX_WEIGHT 50

int main() {
    printf("Welcome to the airport baggage handling simulation program.\n");
    printf("We take baggage security very seriously here, so please make sure your luggage meets our guidelines.\n");
    printf("Maximum luggage size is 100cm x 50cm x 50cm and the maximum weight is 50kg.\n");
    printf("Please enter the number of bags you will be checking in today: ");

    int num_bags;
    scanf("%d", &num_bags);

    int total_size = 0;
    int total_weight = 0;
    int i, size, weight;
    srand(time(NULL)); // seed random number generator

    // Check each piece of luggage to make sure it meets our guidelines
    for(i = 1; i <= num_bags; i++) {
        size = rand() % MAX_SIZE + 1; // generate random size between 1 and MAX_SIZE
        weight = rand() % MAX_WEIGHT + 1; // generate random weight between 1 and MAX_WEIGHT
        
        if(size > 100 || size * 2 > total_size) {
            printf("Error: Baggage size too large or exceeds total luggage size limit.\n");
            printf("Please check the dimensions of your luggage and try again.\n");
            printf("Your baggage has been confiscated.\n");
            return 0;
        }
        else if(weight > 50) {
            printf("Error: Baggage weight exceeds limit.\n");
            printf("Please remove some items from your luggage and try again.\n");
            printf("Your baggage has been confiscated.\n");
            return 0;
        }
        else {
            total_size += size * 2; // multiply by 2 to account for both x and y dimensions
            total_weight += weight;
            printf("Baggage %d cleared security.\n", i);
        }
    }

    printf("Congratulations, your baggage has been cleared for check-in.\n");
    printf("Total weight of luggage: %dkg\n", total_weight);
    printf("Total size of luggage: %dcm x %dcm\n", MAX_SIZE, total_size / 2);

    return 0;
}