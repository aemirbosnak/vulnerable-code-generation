//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct drone {
    int altitude;
    int direction;
    int speed;
};

void increaseAltitude(struct drone *d, int amount) {
    d->altitude += amount;
}

void decreaseAltitude(struct drone *d, int amount) {
    d->altitude -= amount;
}

void turnLeft(struct drone *d, int angle) {
    d->direction -= angle;
}

void turnRight(struct drone *d, int angle) {
    d->direction += angle;
}

void increaseSpeed(struct drone *d, int amount) {
    d->speed += amount;
}

void decreaseSpeed(struct drone *d, int amount) {
    d->speed -= amount;
}

int main() {
    struct drone d = { 0, 0, 0 };

    printf("Drone remote control initialized.\n");

    while (1) {
        printf("Current altitude: %d\n", d.altitude);
        printf("Current direction: %d\n", d.direction);
        printf("Current speed: %d\n", d.speed);

        printf("Enter command: ");
        char command = getchar();
        while (getchar() != '\n'); // discard rest of line

        switch (command) {
            case 'a':
                printf("Enter amount to increase altitude: ");
                int amount;
                scanf("%d", &amount);
                while (getchar() != '\n'); // discard rest of line
                increaseAltitude(&d, amount);
                break;
            case 'd':
                printf("Enter amount to decrease altitude: ");
                scanf("%d", &amount);
                while (getchar() != '\n'); // discard rest of line
                decreaseAltitude(&d, amount);
                break;
            case 'l':
                printf("Enter angle to turn left: ");
                scanf("%d", &amount);
                while (getchar() != '\n'); // discard rest of line
                turnLeft(&d, amount);
                break;
            case 'r':
                printf("Enter angle to turn right: ");
                scanf("%d", &amount);
                while (getchar() != '\n'); // discard rest of line
                turnRight(&d, amount);
                break;
            case 'i':
                printf("Enter amount to increase speed: ");
                scanf("%d", &amount);
                while (getchar() != '\n'); // discard rest of line
                increaseSpeed(&d, amount);
                break;
            case 'q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }

        if (d.altitude < 0) {
            printf("Drone crashed!\n");
            exit(0);
        }
    }

    return 0;
}