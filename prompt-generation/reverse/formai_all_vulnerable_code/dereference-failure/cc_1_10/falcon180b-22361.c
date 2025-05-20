//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_PLANES 10
#define NUM_PASSENGERS 50

typedef struct {
    int plane_num;
    int num_bags;
    int *bag_ids;
} Plane;

int main() {
    srand(time(NULL));

    // Create planes
    Plane *planes = malloc(NUM_PLANES * sizeof(Plane));
    for (int i = 0; i < NUM_PLANES; i++) {
        planes[i].plane_num = i + 1;
        planes[i].num_bags = rand() % (NUM_BAGS / NUM_PLANES) + 1;
        planes[i].bag_ids = malloc(planes[i].num_bags * sizeof(int));
        for (int j = 0; j < planes[i].num_bags; j++) {
            planes[i].bag_ids[j] = rand() % NUM_BAGS + 1;
        }
    }

    // Create passengers
    int *passenger_bags = malloc(NUM_PASSENGERS * sizeof(int));
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        passenger_bags[i] = rand() % NUM_BAGS + 1;
    }

    // Simulate baggage handling
    for (int i = 0; i < NUM_PLANES; i++) {
        printf("Plane %d has %d bags:\n", planes[i].plane_num, planes[i].num_bags);
        for (int j = 0; j < planes[i].num_bags; j++) {
            printf("%d ", planes[i].bag_ids[j]);
        }
        printf("\n");
    }

    printf("\nPassenger bags:\n");
    for (int i = 0; i < NUM_PASSENGERS; i++) {
        printf("%d ", passenger_bags[i]);
    }

    return 0;
}