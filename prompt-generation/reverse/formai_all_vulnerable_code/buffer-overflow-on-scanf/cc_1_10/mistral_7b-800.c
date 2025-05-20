//MISTRAL-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int weight;
} Bag;

void print_error_and_exit(char *message) {
    printf("\n!!! SHOCKED ERROR !!!\n");
    printf("%s\n", message);
    exit(1);
}

void read_bags(Bag bags[]) {
    int i;

    printf("\n!!! READING BAGS !!!\n");

    for (i = 0; i < MAX_BAGS; i++) {
        printf("Enter name of bag %d: ", i + 1);
        scanf("%s", bags[i].name);

        if (strlen(bags[i].name) > MAX_NAME_LENGTH) {
            print_error_and_exit("Name too long!");
        }

        printf("Enter weight of bag %d: ", i + 1);
        scanf("%d", &bags[i].weight);

        if (bags[i].weight < 0) {
            print_error_and_exit("Negative weight!");
        }
    }
}

void handle_bags(Bag bags[]) {
    int i;
    int total_weight = 0;

    printf("\n!!! HANDLING BAGS !!!\n");

    for (i = 0; i < MAX_BAGS; i++) {
        total_weight += bags[i].weight;

        printf("Handling bag %s with weight %d\n", bags[i].name, bags[i].weight);
    }

    printf("Total weight of bags: %d\n", total_weight);
}

int main() {
    srand(time(NULL));
    Bag bags[MAX_BAGS];

    printf("\n!!! C AIRPORT BAGGAGE HANDLING SIMULATION !!!\n");

    read_bags(bags);

    handle_bags(bags);

    return 0;
}