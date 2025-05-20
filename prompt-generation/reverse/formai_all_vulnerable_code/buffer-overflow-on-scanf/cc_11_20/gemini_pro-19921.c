//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

int main() {
    int duration = 12; // This is the duration of the light.
    int status = RED;  // This is the status of the light.

    int vehicles_waiting = 0;  // This is the number of vehicles waiting.

    // Read the number of vehicles waiting.
    printf("Enter the number of vehicles waiting: ");
    scanf("%d", &vehicles_waiting);

    int optimal = 0;

    // While there are vehicles waiting, run the traffic light.
    while (vehicles_waiting > 0) {
        // If the light is red and there are vehicles waiting, turn the light green.
        if (status == RED && vehicles_waiting > 0) {
            status = GREEN;
        }

        // If the light is green, let vehicles pass for the duration of the light.
        if (status == GREEN) {
            duration--;
        }

        // If the light is green and the duration has expired, turn the light yellow.
        if (status == GREEN && duration == 0) {
            status = YELLOW;
        }

        // If the light is yellow, let vehicles pass for the duration of the light.
        if (status == YELLOW) {
            duration--;
        }

        // If the light is yellow and the duration has expired, turn the light red.
        if (status == YELLOW && duration == 0) {
            status = RED;
        }

        // Print the status of the light.
        if (status == RED) {
            printf("The light is red.\n");
        } else if (status == GREEN) {
            printf("The light is green.\n");
        } else if (status == YELLOW) {
            printf("The light is yellow.\n");
        }

        // Decrement the number of vehicles waiting.
        vehicles_waiting--;

        // Sleep for one second.
        sleep(1);
    }

    // Print a message indicating that there are no more vehicles waiting.
    printf("There are no more vehicles waiting.\n");

    return 0;
}