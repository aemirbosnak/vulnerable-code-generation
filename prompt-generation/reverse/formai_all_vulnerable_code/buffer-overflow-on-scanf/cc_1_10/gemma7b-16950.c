//Gemma-7B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Knight {
    char name[20];
    int strength;
    int courage;
} Knight;

int compareKnights(Knight a, Knight b) {
    return a.strength - b.strength;
}

int main() {
    Knight knights[MAX_SIZE];
    int i, n;

    // Create knights
    for (i = 0; i < MAX_SIZE; i++) {
        knights[i].name[0] = '\0';
        knights[i].strength = 0;
        knights[i].courage = 0;
    }

    // Get number of knights
    printf("Enter the number of knights: ");
    scanf("%d", &n);

    // Fill knights' information
    for (i = 0; i < n; i++) {
        printf("Enter the name of knight #%d: ", i + 1);
        scanf("%s", knights[i].name);

        printf("Enter the strength of knight #%d: ", i + 1);
        scanf("%d", &knights[i].strength);

        printf("Enter the courage of knight #%d: ", i + 1);
        scanf("%d", &knights[i].courage);
    }

    // Sort knights by strength
    qsort(knights, n, sizeof(Knight), compareKnights);

    // Print sorted knights
    printf("The sorted knights are:\n");
    for (i = 0; i < n; i++) {
        printf("%s has a strength of %d and a courage of %d.\n", knights[i].name, knights[i].strength, knights[i].courage);
    }

    return 0;
}