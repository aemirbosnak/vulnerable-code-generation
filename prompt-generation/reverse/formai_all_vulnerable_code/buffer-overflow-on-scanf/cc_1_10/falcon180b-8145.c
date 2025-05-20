//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_KNIGHTS 100

// Structure to represent a knight
typedef struct {
    int strength;
    int honor;
} Knight;

// Function to compare the strength of two knights
int compare_strength(const void *a, const void *b) {
    const Knight *knight_a = (const Knight *)a;
    const Knight *knight_b = (const Knight *)b;

    if (knight_a->strength > knight_b->strength) {
        return -1;
    } else if (knight_a->strength < knight_b->strength) {
        return 1;
    } else {
        return 0;
    }
}

// Function to compare the honor of two knights
int compare_honor(const void *a, const void *b) {
    const Knight *knight_a = (const Knight *)a;
    const Knight *knight_b = (const Knight *)b;

    if (knight_a->honor > knight_b->honor) {
        return -1;
    } else if (knight_a->honor < knight_b->honor) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Initialize the number of knights
    int num_knights = 0;

    // Read in the number of knights
    printf("Enter the number of knights: ");
    scanf("%d", &num_knights);

    // Initialize the array of knights
    Knight knights[MAX_KNIGHTS];

    // Read in the strengths and honors of the knights
    for (int i = 0; i < num_knights; i++) {
        printf("Enter the strength and honor of knight %d:\n", i + 1);
        scanf("%d %d", &knights[i].strength, &knights[i].honor);
    }

    // Sort the knights by strength
    qsort(knights, num_knights, sizeof(Knight), compare_strength);

    // Print the sorted list of knights
    printf("Sorted by strength:\n");
    for (int i = 0; i < num_knights; i++) {
        printf("%d: %d %d\n", i + 1, knights[i].strength, knights[i].honor);
    }

    // Sort the knights by honor
    qsort(knights, num_knights, sizeof(Knight), compare_honor);

    // Print the sorted list of knights
    printf("\nSorted by honor:\n");
    for (int i = 0; i < num_knights; i++) {
        printf("%d: %d %d\n", i + 1, knights[i].strength, knights[i].honor);
    }

    return 0;
}