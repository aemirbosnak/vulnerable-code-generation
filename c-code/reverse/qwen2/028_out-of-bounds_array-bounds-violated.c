#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10

void movePlayer(int *x, int *y, char direction) {
    switch (direction) {
        case 'N': (*y)--; break;
        case 'S': (*y)++; break;
        case 'E': (*x)++; break;
        case 'W': (*x)--; break;
        default: printf("Invalid move.\n"); return;
    }
}

int main() {
    int x = 5, y = 5;
    char input;

    while (1) {
        printf("You are at (%d, %d).\n", x, y);
        printf("Enter your move (N/S/E/W): ");
        scanf(" %c", &input);

        if (input == 'Q') break;

        movePlayer(&x, &y, input);

        // Intentionally leaving out of bounds check for vulnerability
    }

    return 0;
}
