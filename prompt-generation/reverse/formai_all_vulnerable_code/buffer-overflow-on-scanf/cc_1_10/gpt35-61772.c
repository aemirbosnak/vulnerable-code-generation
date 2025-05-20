//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGS 1000 // maximum number of bags that can be processed
#define MAX_WEIGHT 50 // maximum weight of any bag
#define MAX_TIME 500 // maximum time for a bag to be processed

// structure to hold the information of each bag
struct Bag {
    int id;
    int weight;
    int processing_time;
};

// function to generate random values for weight and processing time of a bag
void generate_bag_values(struct Bag* bag) {
    bag->weight = rand() % MAX_WEIGHT + 1;
    bag->processing_time = rand() % MAX_TIME + 1;
}

int main() {
    struct Bag bags[MAX_BAGS]; // array to hold all the bags
    int num_bags, i, j;
    
    srand(time(NULL)); // seed for random number generator
    
    // get the number of bags to be processed
    printf("Enter the number of bags to be processed: ");
    scanf("%d", &num_bags);
    
    // generate random values for all the bags
    for(i = 0; i < num_bags; i++) {
        bags[i].id = i + 1;
        generate_bag_values(&bags[i]);
    }
    
    // simulate the baggage handling process
    for(i = 0; i < num_bags; i++) {
        printf("Bag %d with weight %d and processing time %d is being processed.\n", bags[i].id, bags[i].weight, bags[i].processing_time);
        for(j = 1; j <= bags[i].processing_time; j++) {
            printf("Time elapsed: %d\n", j);
            if(j == bags[i].processing_time) {
                printf("Bag %d has been processed successfully.\n", bags[i].id);
                break;
            }
        }
    }
    
    return 0;
}