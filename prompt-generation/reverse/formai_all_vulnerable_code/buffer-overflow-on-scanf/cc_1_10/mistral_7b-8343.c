//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 20
#define MAX_FLIGHT_LENGTH 5

typedef struct {
    char id[MAX_NAME_LENGTH];
    int weight;
    int flight_number;
} Bag;

Bag bags[MAX_BAGS];
int num_bags = 0;

void add_bag(char* id, int weight, int flight_number) {
    if (num_bags >= MAX_BAGS) {
        printf("Cannot add bag, max capacity reached\n");
        return;
    }
    strcpy(bags[num_bags].id, id);
    bags[num_bags].weight = weight;
    bags[num_bags].flight_number = flight_number;
    num_bags++;
}

void process_bags() {
    for (int i = 0; i < num_bags; i++) {
        printf("Processing bag %s (weight: %d, flight number: %d)\n", bags[i].id, bags[i].weight, bags[i].flight_number);
        // code to send bag to its respective flight goes here
        // ...
    }
    num_bags = 0;
}

int main() {
    char id[MAX_NAME_LENGTH];
    int weight, flight_number;

    while (1) {
        printf("Enter bag ID, weight, and flight number (or 'q' to quit):\n");
        scanf("%s %d %d", id, &weight, &flight_number);
        if (strcmp(id, "q") == 0) {
            break;
        }
        add_bag(id, weight, flight_number);
    }

    printf("Processing bags...\n");
    process_bags();
    printf("Baggage handling complete\n");

    return 0;
}