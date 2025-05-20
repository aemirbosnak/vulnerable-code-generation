#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define MAP_SIZE 10

int main() {
    int x = 5, y = 5;
    char command;

    while (1) {
        printf("You are at (%d, %d)\n", x, y);
        printf("Enter your move (N/S/E/W): ");
        scanf(" %c", &command);

        switch (command) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            default:
                printf("Invalid command!\n");
                continue;
        }

        // Intentional buffer overflow vulnerability
        if (x >= MAP_SIZE || x < 0 || y >= MAP_SIZE || y < 0) {
            printf("Buffer overflow detected!\n");
            return 1;
        }
    }

    return 0;
}
