//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_BAG_SIZE 100

struct Bag {
    int id;
    int size;
    int destination;
    int status;
};

int main() {
    srand(time(NULL));
    struct Bag bags[MAX_BAGS];
    int num_bags = 0;
    int num_lost_bags = 0;
    int num_misrouted_bags = 0;
    int num_delayed_bags = 0;

    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    printf("Enter the number of bags you want to simulate (up to %d): ", MAX_BAGS);
    scanf("%d", &num_bags);

    for (int i = 0; i < num_bags; i++) {
        bags[i].id = i + 1;
        bags[i].size = rand() % MAX_BAG_SIZE + 1;
        bags[i].destination = rand() % 10 + 1;
        bags[i].status = 0;
    }

    printf("Simulating baggage handling...\n");
    for (int i = 0; i < num_bags; i++) {
        int baggage_carousel = rand() % 3 + 1;
        int baggage_claim_area = rand() % 2 + 1;

        if (baggage_carousel == baggage_claim_area) {
            printf("Bag %d was successfully delivered to its destination.\n", bags[i].id);
        } else {
            printf("Bag %d was misrouted to baggage carousel %d instead of %d.\n", bags[i].id, baggage_carousel, baggage_claim_area);
            num_misrouted_bags++;
        }

        if (bags[i].size > 50) {
            printf("Bag %d is too large and will be delayed.\n", bags[i].id);
            num_delayed_bags++;
        } else if (bags[i].destination > 5) {
            printf("Bag %d is lost and cannot be found.\n", bags[i].id);
            num_lost_bags++;
        }
    }

    printf("Simulation complete.\n");
    printf("Number of lost bags: %d\n", num_lost_bags);
    printf("Number of misrouted bags: %d\n", num_misrouted_bags);
    printf("Number of delayed bags: %d\n", num_delayed_bags);

    return 0;
}