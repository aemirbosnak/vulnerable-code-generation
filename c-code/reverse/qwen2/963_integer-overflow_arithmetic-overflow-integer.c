#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100

typedef struct {
    int weight;
} Bag;

int main() {
    srand(time(0));
    int numBags, i;
    printf("Enter the number of bags: ");
    if (scanf("%d", &numBags) != 1 || numBags <= 0 || numBags > MAX_BAGS) {
        printf("Invalid input. Please enter a positive integer less than or equal to %d.\n", MAX_BAGS);
        return 1;
    }

    Bag bags[MAX_BAGS];
    for (i = 0; i < numBags; i++) {
        bags[i].weight = rand() % 50 + 1; // Random weight between 1 and 50 kg
    }

    clock_t start = clock();
    int loadedBags = 0;
    for (i = 0; i < numBags; i++) {
        if (bags[i].weight <= 20) { // Assuming max allowed weight is 20 kg
            loadedBags++;
        }
    }
    clock_t end = clock();

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to load bags: %.2f seconds\n", timeTaken);
    printf("Number of bags loaded: %d\n", loadedBags);

    return 0;
}
