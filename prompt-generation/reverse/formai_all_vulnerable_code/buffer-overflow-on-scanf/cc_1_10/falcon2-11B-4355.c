//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DEPTH 100

typedef struct {
    int x;
    int y;
} Coordinate;

Coordinate getRandomCoordinate() {
    Coordinate result;
    result.x = rand() % (MAX_DEPTH - 1) + 1;
    result.y = rand() % (MAX_DEPTH - 1) + 1;
    return result;
}

int main() {
    Coordinate currentCoordinate = getRandomCoordinate();
    int depth = 0;

    printf("You are in the vast emptiness of space.\n");

    while (depth < MAX_DEPTH) {
        printf("You have traveled %d blocks deep into the void.\n", depth);

        Coordinate nextCoordinate = getRandomCoordinate();
        Coordinate direction = {0, 0};

        if (nextCoordinate.x < currentCoordinate.x) {
            direction.x = -1;
        } else if (nextCoordinate.x > currentCoordinate.x) {
            direction.x = 1;
        }

        if (nextCoordinate.y < currentCoordinate.y) {
            direction.y = -1;
        } else if (nextCoordinate.y > currentCoordinate.y) {
            direction.y = 1;
        }

        currentCoordinate = nextCoordinate;
        depth++;

        if (depth % 5 == 0) {
            printf("You have encountered a strange alien artifact. What do you do?\n");
            int choice = 0;
            printf("1. Investigate the artifact\n2. Leave the artifact alone\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You approach the artifact and discover it's a portal to another dimension. Do you enter?\n");
                int choice2 = 0;
                printf("1. Yes\n2. No\n");
                scanf("%d", &choice2);

                if (choice2 == 1) {
                    printf("You enter the portal and find yourself in a strange, new world.\n");
                } else {
                    printf("You decide not to enter the portal and continue your journey.\n");
                }
            } else {
                printf("You ignore the artifact and continue your journey.\n");
            }
        } else {
            printf("You continue your journey deeper into the void.\n");
        }
    }

    printf("You have traveled %d blocks deep into the void. You have reached the center of the universe.\n", depth);

    return 0;
}