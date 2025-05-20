//Code Llama-13B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100

typedef struct {
    int id;
    int weight;
    char* destination;
} Baggage;

Baggage* baggage[MAX_BAGGAGE];
int baggage_count = 0;

void generate_baggage() {
    int i;
    for (i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i] = (Baggage*)malloc(sizeof(Baggage));
        baggage[i]->id = i + 1;
        baggage[i]->weight = rand() % 100 + 1;
        baggage[i]->destination = (char*)malloc(10 * sizeof(char));
        sprintf(baggage[i]->destination, "%d", rand() % 10 + 1);
        baggage_count++;
    }
}

void sort_baggage() {
    int i, j;
    Baggage temp;
    for (i = 0; i < baggage_count; i++) {
        for (j = i + 1; j < baggage_count; j++) {
            if (baggage[i]->weight > baggage[j]->weight) {
                temp = *baggage[i];
                *baggage[i] = *baggage[j];
                *baggage[j] = temp;
            }
        }
    }
}

void print_baggage() {
    int i;
    printf("Baggage Information:\n");
    for (i = 0; i < baggage_count; i++) {
        printf("ID: %d, Weight: %d, Destination: %s\n", baggage[i]->id, baggage[i]->weight, baggage[i]->destination);
    }
}

int main() {
    srand(time(NULL));
    generate_baggage();
    sort_baggage();
    print_baggage();
    return 0;
}