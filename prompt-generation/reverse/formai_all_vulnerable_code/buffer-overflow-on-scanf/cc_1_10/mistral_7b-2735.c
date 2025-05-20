//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SEEDS 100

typedef struct Seed {
    char name[30];
    int ripening_time;
} Seed;

void swap(Seed* a, Seed* b) {
    Seed temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(Seed seeds[MAX_SEEDS]) {
    int i, j, min_index;

    for (i = 0; i < MAX_SEEDS - 1; i++) {
        min_index = i;

        for (j = i + 1; j < MAX_SEEDS; j++) {
            if (seeds[j].ripening_time < seeds[min_index].ripening_time) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&seeds[i], &seeds[min_index]);
        }
    }
}

int main() {
    Seed community_garden[MAX_SEEDS];
    int num_seeds;

    printf("\n***** Welcome to the Last Survivors Community Garden *****\n");
    printf("Enter the number of seeds you have collected:\n");
    scanf("%d", &num_seeds);

    if (num_seeds > MAX_SEEDS) {
        printf("Sorry, we can only sort up to %d seeds.\n", MAX_SEEDS);
        return 1;
    }

    printf("Enter the name and ripening time for each seed:\n");

    for (int i = 0; i < num_seeds; i++) {
        printf("Seed %d:\n", i + 1);
        scanf("%s", community_garden[i].name);
        scanf("%d", &community_garden[i].ripening_time);
    }

    printf("\nSorting seeds based on their ripening time...\n");
    selection_sort(community_garden);

    printf("\nSorted seeds:\n");

    for (int i = 0; i < num_seeds; i++) {
        printf("Seed %s - Ripening time: %d\n", community_garden[i].name, community_garden[i].ripening_time);
    }

    return 0;
}