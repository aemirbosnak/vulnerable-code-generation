//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGGAGE 50
#define MAX_TIME 60

typedef struct {
    int id;
    int weight;
} Baggage;

int main(void) {
    int num_bags, max_weight, min_weight;
    srand(time(NULL));

    printf("Welcome to the Airport Baggage Handling Simulator!\n\n");
    printf("Please enter the number of bags you would like to simulate (up to %d): ", MAX_BAGGAGE);
    scanf("%d", &num_bags);

    if (num_bags > MAX_BAGGAGE) {
        printf("Sorry, that's too many bags. Please try again.\n");
        return 1;
    }

    printf("Please enter the maximum weight of a bag: ");
    scanf("%d", &max_weight);

    printf("Please enter the minimum weight of a bag: ");
    scanf("%d", &min_weight);

    if (max_weight < min_weight) {
        printf("Sorry, the maximum weight must be greater than or equal to the minimum weight.\n");
        return 1;
    }

    printf("\nThank you, the simulation will begin shortly...\n\n");

    Baggage bags[num_bags];

    for (int i = 0; i < num_bags; i++) {
        bags[i].id = i + 1;
        bags[i].weight = rand() % (max_weight - min_weight + 1) + min_weight;

        printf("Bag %d with weight %d is added to the system.\n", bags[i].id, bags[i].weight);
    }

    printf("\nThe bags are now being transported to the airplane...\n\n");

    for (int i = 1; i <= MAX_TIME; i++) {
        printf("Time: %d seconds\n", i);

        for (int j = 0; j < num_bags; j++) {
            if (bags[j].weight <= 30) {
                printf("Bag %d has been loaded onto the airplane.\n", bags[j].id);
                bags[j].weight = 0;
            } else {
                printf("Bag %d is too heavy to load onto the airplane. It will be removed from the system.\n", bags[j].id);
                num_bags--;
            }
        }

        if (num_bags == 0) {
            printf("\nAll bags have been loaded onto the airplane!\n");
            break;
        }

        printf("\n");
    }

    return 0;
}