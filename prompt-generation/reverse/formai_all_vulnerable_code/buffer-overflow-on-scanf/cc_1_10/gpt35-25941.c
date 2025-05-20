//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR -1
#define SUCCESS 0

typedef struct coordinate {
    float x;
    float y;
} Coordinate;

float distance_between(Coordinate p1, Coordinate p2) {
    float x_diff = p2.x - p1.x;
    float y_diff = p2.y - p1.y;
    return sqrt((x_diff * x_diff) + (y_diff * y_diff));
}

int main() {
    Coordinate current_location = {0.0, 0.0};
    Coordinate des_location = {10.0, 10.0};

    while (1) {  // infinite loop
        printf("Current location: (%.2f,%.2f)\n", current_location.x, current_location.y);

        float distance = distance_between(current_location, des_location);
        printf("Distance to destination: %.2f\n", distance);

        if (distance < 0.1) {  // check if destination is reached
            printf("You have reached your destination!\n");
            break;
        }

        printf("Enter the direction you want to go. (N/S/E/W): ");

        char direction;
        scanf(" %c", &direction);  // space before %c to consume newline

        float delta_x = 0.0, delta_y = 0.0;
        switch (direction) {
            case 'N':
                delta_y = 1.0;
                break;
            case 'S':
                delta_y = -1.0;
                break;
            case 'E':
                delta_x = 1.0;
                break;
            case 'W':
                delta_x = -1.0;
                break;
            default:
                printf("Invalid direction. Try again.\n");
                continue;  // go to the beginning of the while loop
        }

        Coordinate new_location = {current_location.x + delta_x, current_location.y + delta_y};
        float new_distance = distance_between(new_location, des_location);

        if (new_distance < distance) {  // move to new location only if it is closer to destination
            current_location = new_location;
        } else {
            printf("Cannot move in that direction. Try another direction.\n");
        }
    }

    return SUCCESS;
}