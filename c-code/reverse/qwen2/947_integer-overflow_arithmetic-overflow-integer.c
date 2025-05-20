#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100

typedef struct {
    int speed;
    char direction;
} Vehicle;

void updateVehicle(Vehicle *v, int newSpeed, char newDirection) {
    v->speed = newSpeed;
    v->direction = newDirection;
}

int main() {
    Vehicle myVehicle = {0, 'N'};
    int timeElapsed = 0;
    int distanceTraveled = 0;

    printf("Welcome to the Remote-Controlled Vehicle Simulator!\n");

    while (1) {
        printf("\nCurrent Speed: %d km/h\n", myVehicle.speed);
        printf("Current Direction: %c\n", myVehicle.direction);

        printf("Enter new speed (0-%d): ", MAX_SPEED);
        scanf("%d", &myVehicle.speed);

        if (myVehicle.speed > MAX_SPEED || myVehicle.speed < 0) {
            printf("Invalid speed. Please enter a value between 0 and %d.\n", MAX_SPEED);
            continue;
        }

        printf("Enter new direction (N/S/E/W): ");
        getchar(); // Consume newline character left by previous scanf
        scanf("%c", &myVehicle.direction);

        if (myVehicle.direction != 'N' && myVehicle.direction != 'S' && myVehicle.direction != 'E' && myVehicle.direction != 'W') {
            printf("Invalid direction. Please enter N, S, E, or W.\n");
            continue;
        }

        time_t start_time = time(NULL);
        sleep(1); // Simulate time passing
        time_t end_time = time(NULL);

        timeElapsed += (end_time - start_time);
        distanceTraveled += myVehicle.speed; // Simplified calculation for demonstration

        printf("Time elapsed: %d seconds\n", timeElapsed);
        printf("Distance traveled: %d meters\n", distanceTraveled);
    }

    return 0;
}
