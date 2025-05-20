//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ADVENTURERS 10

struct adventurer {
    char name[50];
    int height;
};

int main() {
    struct adventurer adventurers[MAX_ADVENTURERS];
    int i, j, count = 0;

    // Brave adventurers, assemble!
    printf("Gather 'round, brave adventurers! The quest for the average height awaits.\n");

    // Recruit some adventurers
    for (i = 0; i < MAX_ADVENTURERS; i++) {
        printf("Recruiting adventurer #%d...\n", i + 1);
        if (scanf("%49s %d", adventurers[i].name, &adventurers[i].height) != 2) {
            printf("Error: failed to recruit adventurer %d\n", i + 1);
            continue;
        }
        count++;
    }

    // Calculate the average height
    int total_height = 0;
    for (i = 0; i < count; i++) {
        total_height += adventurers[i].height;
    }
    float average_height = (float)total_height / count;

    // Announce the average height
    printf("Hear ye, hear ye! The average height of our brave adventurers is: %f feet\n", average_height);

    // Give a shout-out to the tallest adventurer
    struct adventurer *tallest = NULL;
    int tallest_height = -1;
    for (i = 0; i < count; i++) {
        if (adventurers[i].height > tallest_height) {
            tallest_height = adventurers[i].height;
            tallest = &adventurers[i];
        }
    }
    printf("And the tallest adventurer of all is: %s, with a height of %d feet\n", tallest->name, tallest->height);

    // Let the adventurers depart
    for (i = 0; i < count; i++) {
        printf("Fare thee well, brave adventurer %d! May your journey be long and your battles be glorious.\n", i + 1);
    }

    return 0;
}