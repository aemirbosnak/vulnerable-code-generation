//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
// A unique C Airport Baggage Handling Simulation example program in a genius style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_BAGGAGE 500
#define MIN_BAGGAGE 100
#define BAGGAGE_TIME 10

// Define structs
typedef struct {
    int id;
    int weight;
    int time;
} Baggage;

typedef struct {
    int id;
    int capacity;
    int current_weight;
    Baggage* baggage[MAX_BAGGAGE];
} Terminal;

// Define functions
void print_terminal_status(Terminal* terminal) {
    printf("Terminal %d:\n", terminal->id);
    printf("Capacity: %d\n", terminal->capacity);
    printf("Current weight: %d\n", terminal->current_weight);
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        if (terminal->baggage[i] != NULL) {
            printf("Baggage %d:\n", terminal->baggage[i]->id);
            printf("Weight: %d\n", terminal->baggage[i]->weight);
            printf("Time: %d\n", terminal->baggage[i]->time);
        }
    }
}

void simulate_baggage_handling(Terminal* terminal) {
    int baggage_count = rand() % (MAX_BAGGAGE - MIN_BAGGAGE + 1) + MIN_BAGGAGE;
    for (int i = 0; i < baggage_count; i++) {
        Baggage* baggage = (Baggage*)malloc(sizeof(Baggage));
        baggage->id = i + 1;
        baggage->weight = rand() % 1000 + 1;
        baggage->time = BAGGAGE_TIME;
        terminal->baggage[i] = baggage;
    }
    printf("Simulating baggage handling for terminal %d...\n", terminal->id);
    while (1) {
        for (int i = 0; i < MAX_BAGGAGE; i++) {
            if (terminal->baggage[i] != NULL) {
                terminal->baggage[i]->time--;
                if (terminal->baggage[i]->time == 0) {
                    terminal->current_weight += terminal->baggage[i]->weight;
                    if (terminal->current_weight > terminal->capacity) {
                        printf("Terminal %d overloaded! Baggage %d dropped.\n", terminal->id, terminal->baggage[i]->id);
                        terminal->baggage[i] = NULL;
                    } else {
                        printf("Baggage %d handled.\n", terminal->baggage[i]->id);
                        terminal->baggage[i] = NULL;
                    }
                }
            }
        }
        if (terminal->current_weight == 0) {
            printf("Terminal %d empty.\n", terminal->id);
            break;
        }
        sleep(1);
    }
}

int main() {
    srand(time(NULL));

    Terminal terminal1;
    terminal1.id = 1;
    terminal1.capacity = 1000;
    terminal1.current_weight = 0;

    Terminal terminal2;
    terminal2.id = 2;
    terminal2.capacity = 1500;
    terminal2.current_weight = 0;

    simulate_baggage_handling(&terminal1);
    simulate_baggage_handling(&terminal2);

    print_terminal_status(&terminal1);
    print_terminal_status(&terminal2);

    return 0;
}