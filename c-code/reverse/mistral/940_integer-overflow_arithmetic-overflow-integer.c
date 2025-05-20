#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_SPEED 255
#define STEP 10

int speed = 0;
int direction = 0;
int distance = 0;

void move() {
    while (1) {
        distance += speed * STEP;
        printf("Moving: Speed: %d, Distance: %d\n", speed, distance);
        sleep(1);
    }
}

int main() {
    char input;

    while (1) {
        printf("Enter command (S: Speed, D: Direction, Q: Quit): ");
        scanf("%c", &input);

        switch (input) {
            case 'S':
                printf("Enter new speed (0-255): ");
                scanf("%d", &speed);
                if (speed > MAX_SPEED)
                    speed = MAX_SPEED;
                break;
            case 'D':
                printf("Enter new direction (0-3): ");
                scanf("%d", &direction);
                if (direction > 3 || direction < 0)
                    direction = 0;
                break;
            case 'Q':
                return 0;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
