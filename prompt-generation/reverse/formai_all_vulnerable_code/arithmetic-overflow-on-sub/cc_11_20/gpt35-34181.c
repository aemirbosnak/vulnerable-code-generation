//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MAX_ANGLE 180

struct Control {
    int speed;
    int angle;
};

int main() {
    srand(time(NULL));

    struct Control remote = {0, 0};

    printf("Remote control vehicle simulator.\n");
    printf("Enter 'q' to quit.\n");

    char input;
    do {
        printf("\nCurrent speed: %d, Current angle: %d\n", remote.speed, remote.angle);
        printf("Enter a command (e.g. 'f30', 'b20', 'l90', 'r45'): ");
        scanf(" %c", &input);

        switch (input) {
            case 'f': {
                int speed;
                scanf("%d", &speed);
                if (speed > MAX_SPEED) {
                    printf("Error: speed exceeds maximum speed (%d)\n", MAX_SPEED);
                } else {
                    remote.speed += speed;
                }
                break;
            }
            case 'b': {
                int speed;
                scanf("%d", &speed);
                if (speed > remote.speed) {
                    printf("Error: cannot reverse faster than current speed (%d)\n", remote.speed);
                } else {
                    remote.speed -= speed;
                }
                break;
            }
            case 'l': {
                int angle;
                scanf("%d", &angle);
                if (angle > MAX_ANGLE) {
                    printf("Error: angle exceeds maximum angle (%d)\n", MAX_ANGLE);
                } else {
                    remote.angle -= angle;
                }
                break;
            }
            case 'r': {
                int angle;
                scanf("%d", &angle);
                if (angle > MAX_ANGLE) {
                    printf("Error: angle exceeds maximum angle (%d)\n", MAX_ANGLE);
                } else {
                    remote.angle += angle;
                }
                break;
            }
            case 'q': {
                printf("Goodbye!\n");
                break;
            }
            default: {
                printf("Error: unrecognized command\n");
                break;
            }
        }
    } while (input != 'q');

    return 0;
}