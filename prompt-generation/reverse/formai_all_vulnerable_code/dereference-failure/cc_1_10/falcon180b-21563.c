//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define PEDESTRIAN_LIGHT 3
#define RED_PEDESTRIAN_LIGHT 4
#define YELLOW_PEDESTRIAN_LIGHT 5
#define GREEN_PEDESTRIAN_LIGHT 6

void traffic_light_controller(int direction) {
    int current_light = RED_LIGHT;
    int current_pedestrian_light = RED_PEDESTRIAN_LIGHT;
    int duration = 10; // seconds
    int pedestrian_duration = 5; // seconds

    while (1) {
        switch (current_light) {
            case RED_LIGHT:
                printf("Traffic light is red\n");
                printf("Pedestrian light is red\n");
                usleep(duration * 1000000); // sleep for duration seconds
                current_light = GREEN_LIGHT;
                current_pedestrian_light = RED_PEDESTRIAN_LIGHT;
                break;
            case YELLOW_LIGHT:
                printf("Traffic light is yellow\n");
                printf("Pedestrian light is red\n");
                usleep(duration * 1000000); // sleep for duration seconds
                current_light = RED_LIGHT;
                current_pedestrian_light = GREEN_PEDESTRIAN_LIGHT;
                break;
            case GREEN_LIGHT:
                printf("Traffic light is green\n");
                printf("Pedestrian light is red\n");
                usleep(duration * 1000000); // sleep for duration seconds
                current_light = YELLOW_LIGHT;
                current_pedestrian_light = RED_PEDESTRIAN_LIGHT;
                break;
            case PEDESTRIAN_LIGHT:
                printf("Pedestrian light is green\n");
                printf("Traffic light is red\n");
                usleep(pedestrian_duration * 1000000); // sleep for pedestrian_duration seconds
                current_pedestrian_light = YELLOW_PEDESTRIAN_LIGHT;
                current_light = RED_LIGHT;
                break;
            case RED_PEDESTRIAN_LIGHT:
                printf("Pedestrian light is red\n");
                printf("Traffic light is green\n");
                usleep(pedestrian_duration * 1000000); // sleep for pedestrian_duration seconds
                current_pedestrian_light = GREEN_PEDESTRIAN_LIGHT;
                break;
            case YELLOW_PEDESTRIAN_LIGHT:
                printf("Pedestrian light is yellow\n");
                printf("Traffic light is green\n");
                usleep(pedestrian_duration * 1000000); // sleep for pedestrian_duration seconds
                current_pedestrian_light = RED_PEDESTRIAN_LIGHT;
                break;
            case GREEN_PEDESTRIAN_LIGHT:
                printf("Pedestrian light is green\n");
                printf("Traffic light is red\n");
                usleep(pedestrian_duration * 1000000); // sleep for pedestrian_duration seconds
                current_pedestrian_light = YELLOW_PEDESTRIAN_LIGHT;
                break;
            default:
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [direction]\n", argv[0]);
        return 1;
    }

    int direction = atoi(argv[1]);

    if (direction!= 1 && direction!= 2) {
        printf("Invalid direction\n");
        return 1;
    }

    traffic_light_controller(direction);

    return 0;
}