//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
int main() {
    // Initialize variables
    int num_bags = 10;
    int num_bags_checked = 0;
    int num_bags_delayed = 0;
    int num_bags_lost = 0;
    int num_bags_found = 0;
    char bag_type[50];
    
    // Generate random bag types
    srand(time(NULL));
    for (int i = 0; i < num_bags; i++) {
        int rand_num = rand() % 4;
        switch (rand_num) {
            case 0:
                sprintf(bag_type, "Heavy armor");
                break;
            case 1:
                sprintf(bag_type, "Light armor");
                break;
            case 2:
                sprintf(bag_type, "Weapon");
                break;
            case 3:
                sprintf(bag_type, "Food");
                break;
        }
        printf("Bag %d is a %s\n", i+1, bag_type);
    }
    
    // Check bags for delays
    for (int i = 0; i < num_bags; i++) {
        if (strcmp(bag_type[i], "Heavy armor") == 0) {
            printf("Bag %d is delayed due to weight\n", i+1);
            num_bags_delayed++;
        } else if (strcmp(bag_type[i], "Light armor") == 0) {
            printf("Bag %d is delayed due to weight\n", i+1);
            num_bags_delayed++;
        } else if (strcmp(bag_type[i], "Weapon") == 0) {
            printf("Bag %d is delayed due to sharp edges\n", i+1);
            num_bags_delayed++;
        } else if (strcmp(bag_type[i], "Food") == 0) {
            printf("Bag %d is delayed due to smell\n", i+1);
            num_bags_delayed++;
        }
    }
    
    // Print results
    printf("Total bags: %d\n", num_bags);
    printf("Bags checked: %d\n", num_bags_checked);
    printf("Bags delayed: %d\n", num_bags_delayed);
    printf("Bags lost: %d\n", num_bags_lost);
    printf("Bags found: %d\n", num_bags_found);
    return 0;
}