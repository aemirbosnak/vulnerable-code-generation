//Gemma-7B DATASET v1.0 Category: Sorting ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Warrior {
    char name[20];
    int strength;
    int agility;
    int wisdom;
} Warrior;

int compare(Warrior *a, Warrior *b) {
    return a->strength - b->strength;
}

void sortWarriors(Warrior **arr, int n) {
    qsort(arr, n, sizeof(Warrior), compare);
}

int main() {
    Warrior **warriors = NULL;
    int n = 0;

    printf("Enter the number of warriors: ");
    scanf("%d", &n);

    warriors = (Warrior **)malloc(n * sizeof(Warrior));

    for (int i = 0; i < n; i++) {
        warriors[i] = (Warrior *)malloc(sizeof(Warrior));
        printf("Enter the name of warrior %d: ", i + 1);
        scanf("%s", warriors[i]->name);
        printf("Enter the strength of warrior %d: ", i + 1);
        scanf("%d", &warriors[i]->strength);
        printf("Enter the agility of warrior %d: ", i + 1);
        scanf("%d", &warriors[i]->agility);
        printf("Enter the wisdom of warrior %d: ", i + 1);
        scanf("%d", &warriors[i]->wisdom);
    }

    sortWarriors(warriors, n);

    printf("The warriors are sorted by strength:\n");

    for (int i = 0; i < n; i++) {
        printf("%s has a strength of %d\n", warriors[i]->name, warriors[i]->strength);
    }

    free(warriors);

    return 0;
}