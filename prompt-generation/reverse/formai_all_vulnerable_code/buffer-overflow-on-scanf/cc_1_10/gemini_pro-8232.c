//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LATITUDE_MIN -90.0
#define LATITUDE_MAX 90.0
#define LONGITUDE_MIN -180.0
#define LONGITUDE_MAX 180.0

typedef struct {
    double latitude;
    double longitude;
} coordinate_t;

int main() {
    // Initialize the GPS simulator.
    coordinate_t current_position = {0.0, 0.0};
    double speed = 0.0;
    double bearing = 0.0;

    // Read the input from the user.
    char input[100];
    while (1) {
        printf("Enter a command (move, turn, stop, exit): ");
        scanf("%s", input);

        // Process the command.
        if (strcmp(input, "move") == 0) {
            // Get the distance and duration.
            double distance;
            double duration;
            scanf("%lf %lf", &distance, &duration);

            // Calculate the new position.
            current_position.latitude += distance * sin(bearing * M_PI / 180.0);
            current_position.longitude += distance * cos(bearing * M_PI / 180.0);

            // Update the speed.
            speed = distance / duration;
        } else if (strcmp(input, "turn") == 0) {
            // Get the angle.
            double angle;
            scanf("%lf", &angle);

            // Update the bearing.
            bearing += angle;

            // Normalize the bearing.
            bearing = fmod(bearing, 360.0);
        } else if (strcmp(input, "stop") == 0) {
            // Set the speed to zero.
            speed = 0.0;
        } else if (strcmp(input, "exit") == 0) {
            // Exit the program.
            break;
        } else {
            // Print an error message.
            printf("Invalid command.\n");
        }
    }

    // Print the final position.
    printf("Final position: (%lf, %lf)\n", current_position.latitude, current_position.longitude);

    return 0;
}