//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {

    int control, signal, power, altitude;
    char direction;

    printf("Welcome to the Medieval Drone Control!\n\n");

    printf("Enter the remote control number: ");
    scanf("%d", &control);

    printf("Enter the signal strength (1-10): ");
    scanf("%d", &signal);

    if (signal < 1 || signal > 10) {
        printf("Invalid signal strength entered. Please restart.\n");
        exit(0);
    }

    printf("Enter the power level (1-5): ");
    scanf("%d", &power);

    if (power < 1 || power > 5) {
        printf("Invalid power level entered. Please restart.\n");
        exit(0);
    }

    printf("Enter the initial altitude (1-50): ");
    scanf("%d", &altitude);

    if (altitude < 1 || altitude > 50) {
        printf("Invalid altitude entered. Please restart.\n");
        exit(0);
    }

    printf("Starting remote control number %d...\n", control);

    while (1) {

        printf("Enter the direction to move the drone (N - North, S - South, E - East, W - West): ");
        scanf(" %c", &direction);

        if (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W') {
            printf("Invalid direction entered. Try again.\n");
            continue;
        }

        printf("Enter the distance to move the drone (1-10): ");
        int distance;
        scanf("%d", &distance);

        if (distance < 1 || distance > 10) {
            printf("Invalid distance entered. Try again.\n");
            continue;
        }

        switch (direction) {
            case 'N':
                altitude += distance * power;
                break;
            case 'S':
                altitude -= distance * power;
                break;
            case 'E':
                printf("The drone moves East %d feet.\n", distance * signal);
                break;
            case 'W':
                printf("The drone moves West %d feet.\n", distance * signal);
                break;
        }

        if (altitude <= 0) {
            printf("The drone crashed to the ground!\n");
            break;
        } else if (altitude >= 50) {
            printf("The drone reached the maximum altitude and flew away!\n");
            break;
        }
    }

    printf("\nThank you for using the Medieval Drone Control.\n");

    return 0;
}