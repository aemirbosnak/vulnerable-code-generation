#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

int main() {
    int speed = 0;
    char direction = 'f';
    int distance = 0;
    clock_t start_time = clock();

    while (1) {
        printf("Speed: %d\n", speed);
        printf("Direction: %s\n", direction == 'f' ? "Forward" : "Reverse");
        printf("Distance Traveled: %d meters\n", distance);

        printf("Enter command (i/d/s/q): ");
        char command;
        scanf(" %c", &command);

        switch (command) {
            case 'i':
                if (speed < MAX_SPEED) speed++;
                break;
            case 'd':
                if (speed > 0) speed--;
                break;
            case 's':
                direction = direction == 'f' ? 'r' : 'f';
                break;
            case 'q':
                goto end;
            default:
                printf("Invalid command.\n");
        }

        if (direction == 'f') {
            distance += speed * (clock() - start_time) / CLOCKS_PER_SEC;
        } else {
            distance -= speed * (clock() - start_time) / CLOCKS_PER_SEC;
        }
        start_time = clock();
    }

end:
    return 0;
}
