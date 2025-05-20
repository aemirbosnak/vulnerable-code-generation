//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 10
#define GREEN_LIGHT_DURATION 20
#define YELLOW_LIGHT_DURATION 5

void traffic_light_controller(int num_intersections) {
    int i, j;
    int **lights;

    lights = (int **)malloc(num_intersections * sizeof(int *));
    for (i = 0; i < num_intersections; i++) {
        lights[i] = (int *)malloc(3 * sizeof(int));
        for (j = 0; j < 3; j++) {
            lights[i][j] = 0;
        }
    }

    while (1) {
        for (i = 0; i < num_intersections; i++) {
            lights[i][0] = 1; // red light for pedestrians
            lights[i][1] = 0; // red light for vehicles
            lights[i][2] = 0; // green light for pedestrians
        }
        sleep(RED_LIGHT_DURATION);

        for (i = 0; i < num_intersections; i++) {
            lights[i][1] = 1; // green light for vehicles
            lights[i][2] = 0; // red light for pedestrians
        }
        sleep(GREEN_LIGHT_DURATION);

        for (i = 0; i < num_intersections; i++) {
            lights[i][0] = 0; // green light for pedestrians
            lights[i][1] = 0; // yellow light for vehicles
            lights[i][2] = 1; // red light for pedestrians
        }
        sleep(YELLOW_LIGHT_DURATION);
    }
}

int main(int argc, char *argv[]) {
    int num_intersections;

    printf("Enter the number of intersections: ");
    scanf("%d", &num_intersections);

    traffic_light_controller(num_intersections);

    return 0;
}