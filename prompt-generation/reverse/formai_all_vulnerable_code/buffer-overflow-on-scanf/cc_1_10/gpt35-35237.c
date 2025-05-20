//FormAI DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned int)time(NULL)); // Seed the random number generator
    
    printf("Welcome to the dice roller! How many dice do you want to roll? ");
    int numDice;
    scanf("%d", &numDice);
    printf("How many sides does each die have? ");
    int numSides;
    scanf("%d", &numSides);
    
    // Allocate memory for the arrays
    int* rolls = malloc(numDice * sizeof(int));
    if (rolls == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int* counts = calloc(numSides, sizeof(int));
    if (counts == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        free(rolls);
        exit(EXIT_FAILURE);
    }
    
    // Roll the dice and count the results
    for (int i = 0; i < numDice; i++) {
        int roll = rand() % numSides + 1;
        rolls[i] = roll;
        counts[roll-1]++;
    }
    
    // Print the results
    printf("Rolls: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", rolls[i]);
    }
    printf("\n");
    for (int i = 0; i < numSides; i++) {
        printf("%d: %d\n", i+1, counts[i]);
    }
    
    // Free the memory
    free(rolls);
    free(counts);
    
    return 0;
}