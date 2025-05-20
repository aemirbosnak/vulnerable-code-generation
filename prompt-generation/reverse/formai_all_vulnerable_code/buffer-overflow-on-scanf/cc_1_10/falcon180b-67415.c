//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

void traffic_light_controller(int duration) {
    int current_light = RED_LIGHT;
    int previous_light = 0;
    time_t start_time, end_time;

    start_time = time(NULL);
    end_time = start_time + duration;

    while (difftime(time(NULL), start_time) < duration) {
        printf("Current light: ");
        switch (current_light) {
            case RED_LIGHT:
                printf("Red\n");
                break;
            case YELLOW_LIGHT:
                printf("Yellow\n");
                break;
            case GREEN_LIGHT:
                printf("Green\n");
                break;
        }
        previous_light = current_light;

        if (current_light == GREEN_LIGHT) {
            current_light = YELLOW_LIGHT;
        } else if (current_light == YELLOW_LIGHT) {
            current_light = RED_LIGHT;
        } else {
            current_light = GREEN_LIGHT;
        }

        printf("Previous light: ");
        switch (previous_light) {
            case RED_LIGHT:
                printf("Red\n");
                break;
            case YELLOW_LIGHT:
                printf("Yellow\n");
                break;
            case GREEN_LIGHT:
                printf("Green\n");
                break;
        }

        sleep(1);
    }

    printf("Traffic light cycle completed.\n");
}

int main(int argc, char *argv[]) {
    int duration;

    printf("Enter the duration of the traffic light cycle (in seconds): ");
    scanf("%d", &duration);

    traffic_light_controller(duration);

    return 0;
}