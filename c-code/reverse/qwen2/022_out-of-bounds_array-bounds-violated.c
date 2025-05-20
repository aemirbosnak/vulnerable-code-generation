#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10

void movePlayer(int *playerX, int *playerY, char direction) {
    switch(direction) {
        case 'N': (*playerY)--; break;
        case 'S': (*playerY)++; break;
        case 'E': (*playerX)++; break;
        case 'W': (*playerX)--; break;
        default: printf("Invalid direction!\n"); return;
    }
}

int main() {
    int playerX = 5, playerY = 5;
    char input;

    while(1) {
        printf("Player at (%d, %d)\n", playerX, playerY);
        printf("Enter direction (N/S/E/W): ");
        scanf(" %c", &input);

        if(input == 'Q') break;

        movePlayer(&playerX, &playerY, input);

        // Intentionally out-of-bounds access to demonstrate vulnerability
        if(playerX >= MAP_SIZE || playerX < 0 || playerY >= MAP_SIZE || playerY < 0) {
            printf("Out of bounds! Vulnerability exploited.\n");
            exit(1);
        }
    }

    return 0;
}
