//Gemma-7B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Knight {
    char name[20];
    int strength;
    int agility;
    int position;
} Knight;

int compareKnights(Knight *a, Knight *b) {
    return a->strength - b->strength;
}

int main() {
    Knight knights[MAX_SIZE];
    int i, n, sorting = 0;

    printf("Enter the number of knights: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        knights[i].name[0] = '\0';
        printf("Enter the name of knight %d: ", i + 1);
        scanf("%s", knights[i].name);

        printf("Enter the strength of knight %d: ", i + 1);
        scanf("%d", &knights[i].strength);

        printf("Enter the agility of knight %d: ", i + 1);
        scanf("%d", &knights[i].agility);

        knights[i].position = i + 1;
    }

    qsort(knights, n, sizeof(Knight), compareKnights);

    sorting = 1;
    printf("The knights are now sorted by strength:\n");
    for (i = 0; i < n; i++) {
        printf("Knight %d: %s, Strength: %d, Agility: %d, Position: %d\n", knights[i].position, knights[i].name, knights[i].strength, knights[i].agility, knights[i].position);
    }

    if (!sorting) {
        printf("No knights were sorted.\n");
    }

    return 0;
}