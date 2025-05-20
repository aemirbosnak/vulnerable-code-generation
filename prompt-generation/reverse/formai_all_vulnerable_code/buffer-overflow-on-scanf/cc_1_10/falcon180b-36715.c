//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_BAGS 1000
#define MAX_PLANES 10
#define MAX_BAG_TYPES 5
#define MAX_BAG_SIZES 5

typedef struct {
    int id;
    int dest;
    int status;
    int size;
} Bag;

typedef struct {
    int num_bags;
    int capacity;
    int dest;
    int status;
} Plane;

int main() {
    int num_planes, i, j;
    int num_bags, bag_size, bag_type;
    int bag_count[MAX_BAG_TYPES][MAX_BAG_SIZES] = {0};
    Bag bags[MAX_BAGS];
    Plane planes[MAX_PLANES];

    // Initialize random seed
    srand(time(NULL));

    // Read input
    printf("Enter number of planes: ");
    scanf("%d", &num_planes);

    for (i = 0; i < num_planes; i++) {
        printf("Enter destination for plane %d: ", i+1);
        scanf("%d", &planes[i].dest);
        planes[i].num_bags = 0;
        planes[i].capacity = rand() % 100 + 50;
        planes[i].status = 0;
    }

    printf("Enter number of bags: ");
    scanf("%d", &num_bags);

    for (i = 0; i < num_bags; i++) {
        printf("Enter destination for bag %d: ", i+1);
        scanf("%d", &bags[i].dest);
        bags[i].size = rand() % 5 + 1;
        bags[i].status = 0;
    }

    // Simulate baggage handling
    for (i = 0; i < num_planes; i++) {
        for (j = 0; j < num_bags; j++) {
            if (bags[j].dest == planes[i].dest && planes[i].num_bags < planes[i].capacity) {
                bags[j].status = 1;
                planes[i].num_bags++;
            }
        }
    }

    // Print results
    printf("Baggage handling complete.\n");
    for (i = 0; i < num_planes; i++) {
        printf("Plane %d is carrying %d bags to %d.\n", i+1, planes[i].num_bags, planes[i].dest);
    }

    return 0;
}