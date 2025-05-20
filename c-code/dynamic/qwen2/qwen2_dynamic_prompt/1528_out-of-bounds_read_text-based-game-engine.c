#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAX_LEVELS 10

void loadLevel(int level) {
    int levels[MAX_LEVELS][2] = {
        {10, 20},
        {30, 40},
        {50, 60},
        {70, 80},
        {90, 100},
        {110, 120},
        {130, 140},
        {150, 160},
        {170, 180},
        {190, 200}
    };

    if (level >= 0 && level < MAX_LEVELS) {
        printf("Loading level %d: %d to %d\n", level, levels[level][0], levels[level][1]);
    } else {
        printf("Error: Invalid level number.\n");
    }
}

int main() {
    int currentLevel = -1;

    while (1) {
        printf("Enter the level number to load (-1 to exit): ");
        scanf("%d", &currentLevel);

        if (currentLevel == -1) {
            break;
        }

        loadLevel(currentLevel);
    }

    return 0;
}
