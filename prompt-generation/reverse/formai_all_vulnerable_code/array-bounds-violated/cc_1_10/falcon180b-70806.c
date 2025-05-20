//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_CAROUSELS 10
#define BAG_SIZE 50

typedef struct {
    int id;
    int destination;
    int carousel;
} Bag;

Bag bags[NUM_BAGS];
int carousels[NUM_CAROUSELS];
int num_bags_per_carousel[NUM_CAROUSELS] = {0};

void distribute_bags(int num_carousels, int num_bags) {
    int i, j, k;
    for (i = 0; i < num_carousels; i++) {
        num_bags_per_carousel[i] = (num_bags / num_carousels) + (i < (num_bags % num_carousels));
    }

    for (i = 0; i < num_bags; i++) {
        bags[i].destination = i % num_carousels;
        carousels[bags[i].destination] += 1;
    }
}

void print_bags(int num_bags, int num_carousels) {
    int i, j;
    for (i = 0; i < num_carousels; i++) {
        printf("Carousel %d has %d bags:\n", i + 1, num_bags_per_carousel[i]);
        for (j = 0; j < num_bags_per_carousel[i]; j++) {
            printf("Bag %d going to carousel %d\n", j + 1, bags[i * BAG_SIZE + j].destination + 1);
        }
    }
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].destination = rand() % NUM_CAROUSELS;
    }

    distribute_bags(NUM_CAROUSELS, NUM_BAGS);
    print_bags(NUM_BAGS, NUM_CAROUSELS);

    return 0;
}