//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_TERMINALS 10

typedef struct {
    int id;
    int terminal;
    int weight;
} Baggage;

typedef struct {
    int id;
    Baggage *bags;
    int num_bags;
} Flight;

typedef struct {
    int id;
    int num_flights;
    Flight *flights;
} Terminal;

int main() {
    //set seed for random number generation
    srand(time(NULL));

    //initialize terminals
    Terminal terminals[MAX_TERMINALS];
    for(int i = 0; i < MAX_TERMINALS; i++) {
        terminals[i].id = i+1;
        terminals[i].num_flights = rand() % 5 + 1;
        terminals[i].flights = (Flight *) malloc(terminals[i].num_flights * sizeof(Flight));
        
        //initialize flights for each terminal
        for(int j = 0; j < terminals[i].num_flights; j++) {
            terminals[i].flights[j].id = j+1;
            terminals[i].flights[j].num_bags = rand() % 21 + 30; //30 to 50 bags per flight
            terminals[i].flights[j].bags = (Baggage *) malloc(terminals[i].flights[j].num_bags * sizeof(Baggage));
            
            //initialize bags for each flight
            for(int k = 0; k < terminals[i].flights[j].num_bags; k++) {
                terminals[i].flights[j].bags[k].id = k+1;
                terminals[i].flights[j].bags[k].weight = rand() % 26 + 5; //5 to 30 kg per bag
                terminals[i].flights[j].bags[k].terminal = i+1; //assign the terminal id to the bag
            }
        }
    }

    //print the initial state of the system
    printf("INITIAL STATE:\n\n");
    for(int i = 0; i < MAX_TERMINALS; i++) {
        printf("Terminal %d:\n", terminals[i].id);
        for(int j = 0; j < terminals[i].num_flights; j++) {
            printf("\tFlight %d:\n", terminals[i].flights[j].id);
            for(int k = 0; k < terminals[i].flights[j].num_bags; k++) {
                printf("\t\tBaggage %d: terminal %d, weight %d kg\n", terminals[i].flights[j].bags[k].id, terminals[i].flights[j].bags[k].terminal, terminals[i].flights[j].bags[k].weight);
            }
        }
    }

    //simulate the baggage handling process
    printf("\nSTARTING SIMULATION:\n\n");
    for(int i = 0; i < MAX_TERMINALS; i++) {
        for(int j = 0; j < terminals[i].num_flights; j++) {
            printf("Handling baggage for Terminal %d Flight %d...\n", terminals[i].id, terminals[i].flights[j].id);
            for(int k = 0; k < terminals[i].flights[j].num_bags; k++) {
                //randomly assign a destination terminal to each bag
                int dest = rand() % MAX_TERMINALS;
                while(dest == i) {
                    dest = rand() % MAX_TERMINALS;
                }
                printf("\tBaggage %d: Moving from Terminal %d to Terminal %d\n", terminals[i].flights[j].bags[k].id, terminals[i].flights[j].bags[k].terminal, dest+1);
                terminals[dest].flights[j].bags = (Baggage *) realloc(terminals[dest].flights[j].bags, (terminals[dest].flights[j].num_bags + 1) * sizeof(Baggage));
                terminals[dest].flights[j].bags[terminals[dest].flights[j].num_bags].id = terminals[i].flights[j].bags[k].id;
                terminals[dest].flights[j].bags[terminals[dest].flights[j].num_bags].weight = terminals[i].flights[j].bags[k].weight;
                terminals[dest].flights[j].bags[terminals[dest].flights[j].num_bags].terminal = dest+1;
                terminals[dest].flights[j].num_bags++;
            }
        }
    }

    //print the final state of the system
    printf("\nFINAL STATE:\n\n");
    for(int i = 0; i < MAX_TERMINALS; i++) {
        printf("Terminal %d:\n", terminals[i].id);
        for(int j = 0; j < terminals[i].num_flights; j++) {
            printf("\tFlight %d:\n", terminals[i].flights[j].id);
            for(int k = 0; k < terminals[i].flights[j].num_bags; k++) {
                printf("\t\tBaggage %d: terminal %d, weight %d kg\n", terminals[i].flights[j].bags[k].id, terminals[i].flights[j].bags[k].terminal, terminals[i].flights[j].bags[k].weight);
            }
        }
    }

    //free memory allocated to baggage and flights
    for(int i = 0; i < MAX_TERMINALS; i++) {
        for(int j = 0; j < terminals[i].num_flights; j++) {
            free(terminals[i].flights[j].bags);
        }
        free(terminals[i].flights);
    }
    
    return 0;
}