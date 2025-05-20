#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10
#define WIN_LOCATION 45

int main() {
    int playerPosition = 0;
    char direction;

    while (playerPosition != WIN_LOCATION) {
        printf("You are at position %d. Enter N, S, E, W to move: ", playerPosition);
        scanf(" %c", &direction);

        switch (direction) {
            case 'N':
                if (playerPosition >= GRID_SIZE) playerPosition -= GRID_SIZE;
                break;
            case 'S':
                if (playerPosition < GRID_SIZE * (GRID_SIZE - 1)) playerPosition += GRID_SIZE;
                break;
            case 'E':
                if ((playerPosition + 1) % GRID_SIZE != 0) playerPosition++;
                break;
            case 'W':
                if (playerPosition % GRID_SIZE != 0) playerPosition--;
                break;
            default:
                printf("Invalid direction!\n");
                continue;
        }

        if (playerPosition == WIN_LOCATION) {
            printf("Congratulations! You've won!\n");
        }
    }

    return 0;
}
