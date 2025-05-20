//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 100
#define NUM_DESTINATIONS 10
#define MAX_NUM_PASSENGERS 50

typedef struct {
    int destination;
    int passenger_id;
} Bag;

Bag bags[NUM_BAGS];
int num_bags = 0;
int num_passengers = 0;

void generate_bags() {
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        bags[i].destination = rand() % NUM_DESTINATIONS;
        bags[i].passenger_id = rand() % MAX_NUM_PASSENGERS;
    }
}

void simulate() {
    int i, j;
    srand(time(NULL));
    generate_bags();

    printf("Baggage handling simulation started...\n");

    while (num_bags > 0) {
        for (i = 0; i < num_passengers; i++) {
            j = rand() % num_bags;
            if (bags[j].destination == i) {
                printf("Bag %d claimed by passenger %d\n", j, i);
                num_bags--;
            }
        }
        for (i = 0; i < num_bags; i++) {
            if (bags[i].destination == -1) {
                printf("Bag %d lost\n", i);
                num_bags--;
            }
        }
        num_passengers++;
    }

    printf("Baggage handling simulation ended.\n");
}

int main() {
    int choice;

    do {
        printf("1. Start simulation\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            simulate();
            break;
        case 2:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}