#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int speed = 0;
    int direction = 1; // 1 for forward, -1 for reverse
    int distance = 0;

    while (1) {
        printf("Current Speed: %d km/h, Direction: %s\n", speed * direction, direction == 1 ? "Forward" : "Reverse");
        printf("Enter command (s for speed up, n for speed down, r for reverse, q to quit): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 's':
                if (speed < 100) speed++;
                break;
            case 'n':
                if (speed > 0) speed--;
                break;
            case 'r':
                direction *= -1;
                break;
            case 'q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
        }

        distance += speed * direction;
    }

    return 0;
}
