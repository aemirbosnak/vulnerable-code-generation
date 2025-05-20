//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MAX_DISTANCE 100
#define MAX_ANGLE 90
#define FORWARD 1
#define BACKWARD -1

int main(int argc, char **argv) {
    int distance = 0;
    int angle = 0;
    int direction = FORWARD;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <distance>\n", argv[0]);
        return 1;
    }

    int distance_int = atoi(argv[1]);
    if (distance_int > MAX_DISTANCE || distance_int < 0) {
        fprintf(stderr, "Invalid distance: %d\n", distance_int);
        return 1;
    }

    distance = distance_int;

    if (fork() == 0) {
        while (1) {
            sleep(1);

            if (direction == FORWARD) {
                printf("Moving forward...\n");
                direction = BACKWARD;
            } else {
                printf("Moving backward...\n");
                direction = FORWARD;
            }

            if (distance == 0) {
                printf("Arrived at destination!\n");
                exit(0);
            }

            distance--;
            angle = (distance_int - 1) * 2;
            if (angle < 0)
                angle += 360;

            printf("Moving at %d degrees for %d seconds...\n", angle, 2);
            sleep(2);
        }
    } else {
        while (1) {
            sleep(1);

            if (fork() == 0) {
                signal(SIGTERM, SIG_IGN);
                if (distance == 0)
                    exit(0);

                distance--;
                printf("Moving at %d degrees for %d seconds...\n", (distance_int - 1) * 2, 2);
                sleep(2);
            } else {
                exit(0);
            }
        }
    }

    return 0;
}