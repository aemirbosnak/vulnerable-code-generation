//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shape shifting
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DISTANCE 1000000000
#define MAX_SPEED 1000000
#define MAX_SIZE 1000000
#define MAX_TIME 1000000

typedef struct {
    double distance;
    double speed;
    double size;
    double time;
} Alien;

double calculate_probability(Alien alien) {
    double probability = 0.0;

    if (alien.distance > MAX_DISTANCE) {
        return probability;
    }

    if (alien.speed > MAX_SPEED) {
        return probability;
    }

    if (alien.size > MAX_SIZE) {
        return probability;
    }

    if (alien.time > MAX_TIME) {
        return probability;
    }

    probability = (alien.distance / MAX_DISTANCE) * (alien.speed / MAX_SPEED) * (alien.size / MAX_SIZE) * (alien.time / MAX_TIME);

    return probability;
}

int main() {
    Alien alien;

    printf("Enter the distance to Earth (in light years): ");
    scanf("%lf", &alien.distance);

    printf("Enter the speed of the alien spaceship (in light years per year): ");
    scanf("%lf", &alien.speed);

    printf("Enter the size of the alien spaceship (in kilometers): ");
    scanf("%lf", &alien.size);

    printf("Enter the time until the alien spaceship arrives (in years): ");
    scanf("%lf", &alien.time);

    double probability = calculate_probability(alien);

    printf("The probability of an alien invasion is: %lf%%\n", probability * 100);

    return 0;
}