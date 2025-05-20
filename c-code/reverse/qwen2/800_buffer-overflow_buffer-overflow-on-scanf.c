#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define GRID_SIZE 5

int main() {
    char grid[GRID_SIZE][GRID_SIZE] = {
        {'1', '2', '3', '4', '5'},
        {'6', '7', '8', '9', 'A'},
        {'B', 'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J', 'K'},
        {'L', 'M', 'N', 'O', 'P'}
    };
    int x = 0, y = 0;

    while (1) {
        printf("\nCurrent position: (%d, %d)\n", x, y);
        printf("Grid:\n");
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (i == x && j == y) {
                    printf("* ");
                } else {
                    printf("%c ", grid[i][j]);
                }
            }
            printf("\n");
        }

        printf("Enter direction (w/a/s/d): ");
        char dir;
        scanf(" %c", &dir);

        switch (dir) {
            case 'w':
                if (x > 0) x--;
                break;
            case 'a':
                if (y > 0) y--;
                break;
            case 's':
                if (x < GRID_SIZE - 1) x++;
                break;
            case 'd':
                if (y < GRID_SIZE - 1) y++;
                break;
            default:
                printf("Invalid direction!\n");
                continue;
        }

        // Vulnerable to buffer overflow
        char buffer[2];
        printf("Enter something: ");
        scanf("%s", buffer);
    }

    return 0;
}
