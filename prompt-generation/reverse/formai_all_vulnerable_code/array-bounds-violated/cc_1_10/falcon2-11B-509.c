//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_AIRPORT_SIZE 10
#define MAX_BAG_SIZE 5
#define MAX_AIRPORT_BAG_SIZE 1000

typedef struct {
    char name[50];
    int size;
    int weight;
} Bag;

typedef struct {
    char name[50];
    int bags[MAX_BAG_SIZE];
} Airport;

int main() {
    srand(time(NULL));

    Airport airports[MAX_AIRPORT_SIZE];
    for (int i = 0; i < MAX_AIRPORT_SIZE; i++) {
        airports[i].name[0] = 'A';
        airports[i].name[1] = 'i';
        airports[i].name[2] = 'r';
        airports[i].name[3] = 'p';
        airports[i].name[4] = '\0';
        airports[i].bags[0] = 1;
        airports[i].bags[1] = 2;
        airports[i].bags[2] = 3;
        airports[i].bags[3] = 4;
        airports[i].bags[4] = 5;
        airports[i].bags[5] = 6;
        airports[i].bags[6] = 7;
        airports[i].bags[7] = 8;
        airports[i].bags[8] = 9;
        airports[i].bags[9] = 10;
    }

    Bag bags[MAX_AIRPORT_BAG_SIZE];
    for (int i = 0; i < MAX_AIRPORT_BAG_SIZE; i++) {
        strcpy(bags[i].name, "Bag");
        bags[i].size = rand() % 100;
        bags[i].weight = rand() % 500;
    }

    for (int i = 0; i < MAX_AIRPORT_SIZE; i++) {
        for (int j = 0; j < MAX_AIRPORT_BAG_SIZE; j++) {
            printf("%s - %s: %d kg\n", airports[i].name, bags[j].name, bags[j].weight);
        }
    }

    return 0;
}