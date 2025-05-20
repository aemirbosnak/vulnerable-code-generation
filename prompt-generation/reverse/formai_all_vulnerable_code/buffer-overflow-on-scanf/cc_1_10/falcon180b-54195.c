//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ALIENS 1000
#define MAX_TRIES 1000
#define MIN_DISTANCE 0.1
#define MAX_DISTANCE 10.0

struct Alien {
    double distance;
    int found;
};

int main() {
    srand(time(0));

    struct Alien aliens[MAX_ALIENS];
    int num_aliens = 0;

    printf("Enter the number of aliens to simulate: ");
    scanf("%d", &num_aliens);

    for (int i = 0; i < num_aliens; i++) {
        aliens[i].distance = (double)rand() / RAND_MAX * (MAX_DISTANCE - MIN_DISTANCE) + MIN_DISTANCE;
        aliens[i].found = 0;
    }

    int num_tries = 0;
    while (num_tries < MAX_TRIES) {
        double x = (double)rand() / RAND_MAX * (MAX_DISTANCE - MIN_DISTANCE) + MIN_DISTANCE;
        double y = (double)rand() / RAND_MAX * (MAX_DISTANCE - MIN_DISTANCE) + MIN_DISTANCE;

        int found = 0;
        for (int i = 0; i < num_aliens; i++) {
            double dx = x - aliens[i].distance;
            double dy = y - aliens[i].distance;
            double distance = sqrt(dx * dx + dy * dy);

            if (distance <= MIN_DISTANCE) {
                found = 1;
                break;
            }
        }

        if (found) {
            printf("Invasion detected at (%lf, %lf)\n", x, y);
        } else {
            printf("No invasion detected.\n");
        }

        num_tries++;
    }

    return 0;
}