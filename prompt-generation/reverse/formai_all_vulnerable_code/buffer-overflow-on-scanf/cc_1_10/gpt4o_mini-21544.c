//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define NATIVE_SPECIES_INITIAL 50
#define INVASIVE_SPECIES_GROWTH_RATE 2
#define NATIVE_SPECIES_DEATH_RATE 1

typedef struct {
    int nativeSpecies;
    int invasiveSpecies;
} Ecosystem;

void initializeEcosystem(Ecosystem ecosystem[GRID_SIZE][GRID_SIZE]) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            ecosystem[i][j].nativeSpecies = NATIVE_SPECIES_INITIAL;
            ecosystem[i][j].invasiveSpecies = 0;
        }
    }
}

void simulateGrowth(Ecosystem ecosystem[GRID_SIZE][GRID_SIZE]) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            ecosystem[i][j].invasiveSpecies += INVASIVE_SPECIES_GROWTH_RATE;
            if (ecosystem[i][j].nativeSpecies > 0) {
                ecosystem[i][j].nativeSpecies -= NATIVE_SPECIES_DEATH_RATE;
            }
        }
    }
}

void printEcosystem(Ecosystem ecosystem[GRID_SIZE][GRID_SIZE]) {
    printf("Ecosystem Population\n");
    printf("----------------------\n");
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            printf("| N:%d I:%d ", ecosystem[i][j].nativeSpecies, ecosystem[i][j].invasiveSpecies);
        }
        printf("|\n");
        printf("----------------------\n");
    }
}

int main() {
    Ecosystem ecosystem[GRID_SIZE][GRID_SIZE];
    int iterations;

    srand(time(NULL));

    printf("Enter the number of iterations for the simulation: ");
    scanf("%d", &iterations);

    initializeEcosystem(ecosystem);

    for(int iter = 0; iter < iterations; iter++) {
        printf("\nIteration %d:\n", iter + 1);
        simulateGrowth(ecosystem);
        printEcosystem(ecosystem);
    }

    return 0;
}