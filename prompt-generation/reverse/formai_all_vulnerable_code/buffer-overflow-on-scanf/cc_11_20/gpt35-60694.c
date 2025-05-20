//FormAI DATASET v1.0 Category: Robot movement control ; Style: light-weight
#include <stdio.h>

int main() {
    int x_position = 0;
    int y_position = 0;
    int facing_direction = 1;
    char move;

    printf("Enter your movements (F=forward, L=turn left, R=turn right): ");

    while (1) {
        scanf("%c", &move);

        if (move == 'F') {
            if (facing_direction == 1) {
                x_position++;
            }
            else if (facing_direction == 2) {
                y_position++;
            }
            else if (facing_direction == 3) {
                x_position--;
            }
            else if (facing_direction == 4) {
                y_position--;
            }
        }
        else if (move == 'L') {
            facing_direction--;

            if (facing_direction == 0) {
                facing_direction = 4;
            }
        }
        else if (move == 'R') {
            facing_direction++;

            if (facing_direction == 5) {
                facing_direction = 1;
            }
        }
        else {
            break;
        }
    }

    printf("Robot's final position: (%d, %d) facing ", x_position, y_position);

    if (facing_direction == 1) {
        printf("East");
    }
    else if (facing_direction == 2) {
        printf("North");
    }
    else if (facing_direction == 3) {
        printf("West");
    }
    else if (facing_direction == 4) {
        printf("South");
    }

    return 0;
}