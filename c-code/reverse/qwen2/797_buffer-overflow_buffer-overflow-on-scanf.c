#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int speed = 0;
    char direction;

    while (1) {
        printf("Enter speed (0-100) and direction (L/R): ");
        if (scanf("%d %c", &speed, &direction) != 2 || speed < 0 || speed > 100 || (direction != 'L' && direction != 'R')) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n'); // Clear input buffer
        } else {
            printf("Speed: %d, Direction: %c\n", speed, direction);
        }
    }

    return 0;
}
