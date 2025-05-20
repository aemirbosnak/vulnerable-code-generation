#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int weight;
} Baggage;

int main() {
    int numBags;
    printf("Enter the number of bags: ");
    scanf("%d", &numBags);

    Baggage *bags = (Baggage *)malloc(numBags * sizeof(Baggage));
    if (bags == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < numBags; i++) {
        bags[i].weight = rand() % 50 + 1;
    }

    int loadedBags = 0;
    while (loadedBags < numBags) {
        if (loadedBags >= numBags) {
            break;
        }
        printf("Loading bag %d with weight %d\n", loadedBags + 1, bags[loadedBags].weight);
        loadedBags++;
        sleep(1); // Simulate time delay
    }

    free(bags);
    return 0;
}
