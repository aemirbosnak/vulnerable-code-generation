//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    int latitude;
    int longitude;
} coord_t;

coord_t get_coordinate(char* location) {
    char* tokens[3];
    char* token;
    int i;

    if (location == NULL || strcmp(location, "") == 0) {
        return (coord_t){0, 0};
    }

    strcpy(tokens[0], location);
    token = strtok(tokens[0], ",");
    tokens[1] = token;
    token = strtok(NULL, ",");
    tokens[2] = token;

    for (i = 1; i < 3; i++) {
        if (tokens[i] == NULL) {
            return (coord_t){0, 0};
        }
    }

    coord_t coord;
    coord.latitude = atof(tokens[0]);
    coord.longitude = atof(tokens[1]);

    return coord;
}

int main() {
    point_t start;
    point_t destination;
    int steps;
    char* location;
    int i;

    printf("Enter start coordinates: ");
    location = scanf("%d,%d", &start.x, &start.y);
    if (location == NULL) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter destination coordinates: ");
    location = scanf("%d,%d", &destination.x, &destination.y);
    if (location == NULL) {
        printf("Invalid input!\n");
        return 1;
    }

    steps = 100;
    coord_t start_coord = get_coordinate(location);
    coord_t destination_coord = get_coordinate(location);

    printf("Start coordinate: (%d, %d)\n", start_coord.latitude, start_coord.longitude);
    printf("Destination coordinate: (%d, %d)\n", destination_coord.latitude, destination_coord.longitude);

    srand(time(NULL));
    int angle = rand() % 360;
    double distance = sqrt((double)(destination.x - start.x) * (destination.x - start.x) + (double)(destination.y - start.y) * (destination.y - start.y));

    for (i = 0; i < steps; i++) {
        point_t step;
        step.x = start.x + (rand() % 100) / 100.0 * distance * cos(angle);
        step.y = start.y + (rand() % 100) / 100.0 * distance * sin(angle);

        printf("Step %d: (%d, %d)\n", i + 1, step.x, step.y);

        angle += (rand() % 2) * 360;
    }

    printf("Reached destination!\n");

    return 0;
}