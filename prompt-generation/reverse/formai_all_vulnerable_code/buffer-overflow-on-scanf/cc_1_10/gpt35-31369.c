//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declare constants */
#define MAX_BAGS 100
#define MAX_WEIGHT 50
#define MIN_WEIGHT 5
#define MAX_FLIGHTS 10
#define MAX_GATES 5
#define MAX_BELTS 3

/* Define a structure for a baggage */
typedef struct {
    int id;
    int weight;
    int flight_number;
    int gate_number;
} Baggage;

/* Define a function to generate a random weight between 5 and 50 */
int generate_weight() {
    return (rand() % (MAX_WEIGHT - MIN_WEIGHT + 1)) + MIN_WEIGHT;
}

/* Define a function to generate a random flight number between 1 and 10 */
int generate_flight_number() {
    return rand() % MAX_FLIGHTS + 1;
}

/* Define a function to generate a random gate number between 1 and 5 */
int generate_gate_number() {
    return rand() % MAX_GATES + 1;
}

/* Define a function to simulate the baggage handling process */
void simulate_baggage_handling() {
    /* Declare variables */
    int num_bags, i, j;
    int gate_count[MAX_GATES] = {0};
    int belt_count[MAX_BELTS] = {0};
    Baggage bags[MAX_BAGS];

    /* Seed the random number generator */
    srand(time(NULL));

    /* Prompt the user for the number of bags */
    printf("Enter the number of bags: ");
    scanf("%d", &num_bags);

    /* Generate the bags */
    for (i = 0; i < num_bags; i++) {
        bags[i].id = i + 1;
        bags[i].weight = generate_weight();
        bags[i].flight_number = generate_flight_number();
        bags[i].gate_number = generate_gate_number();
    }

    /* Display the list of bags */
    printf("\nList of bags:\n");
    printf("------------------------------------------------------------\n");
    printf("| ID \t| Weight \t| Flight # \t| Gate # \t|\n");
    printf("------------------------------------------------------------\n");
    for (i = 0; i < num_bags; i++) {
        printf("| %d \t| %d lbs \t| Flight %d \t| Gate %d \t|\n", bags[i].id, bags[i].weight, bags[i].flight_number, bags[i].gate_number);
    }
    printf("------------------------------------------------------------\n");

    /* Simulate the baggage handling process */
    for (i = 0; i < num_bags; i++) {
        /* Put the bag on the gate belt */
        belt_count[bags[i].gate_number - 1]++;
        printf("\nBag %d put on Gate Belt %d", bags[i].id, bags[i].gate_number);
        printf("\nGate Belt %d count: %d", bags[i].gate_number, belt_count[bags[i].gate_number - 1]);

        /* Move the bag from the gate belt to the baggage claim belt */
        for (j = 0; j < MAX_BELTS; j++) {
            if (belt_count[j] < MAX_BAGS) {
                belt_count[bags[i].gate_number - 1]--;
                belt_count[j]++;
                printf("\nBag %d moved from Gate Belt %d to Baggage Claim Belt %d", bags[i].id, bags[i].gate_number, j + 1);
                printf("\nGate Belt %d count: %d, Baggage Claim Belt %d count: %d", bags[i].gate_number, belt_count[bags[i].gate_number - 1], j + 1, belt_count[j]);
                break;
            }
        }
    }

    /* Display the final counts */
    printf("\n\nFinal counts:");
    for (i = 0; i < MAX_GATES; i++) {
        printf("\nGate %d count: %d", i + 1, gate_count[i]);
    }
    for (i = 0; i < MAX_BELTS; i++) {
        printf("\nBaggage Claim Belt %d count: %d", i + 1, belt_count[i]);
    }
}

/* Define the main function */
int main() {
    /* Call the simulate_baggage_handling function */
    simulate_baggage_handling();

    /* Return 0 to indicate success */
    return 0;
}