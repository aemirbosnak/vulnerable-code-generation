//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3
#define PEDESTRIAN_LIGHT 4

#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_HOUR (SECONDS_PER_MINUTE * 60)
#define SECONDS_PER_DAY (SECONDS_PER_HOUR * 24)

void init_lights() {
    printf("Initializing lights...\n");
    system("clear");
    printf("------------------------\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("|                    |\n");
    printf("------------------------\n");
}

void set_light(int light_number, char* light_color) {
    printf("Setting light %d to %s...\n", light_number, light_color);
    switch (light_number) {
        case RED_LIGHT:
            printf("|%s|\n", light_color);
            break;
        case YELLOW_LIGHT:
            printf("|%s|\n", light_color);
            break;
        case GREEN_LIGHT:
            printf("|%s|\n", light_color);
            break;
        case PEDESTRIAN_LIGHT:
            printf("|%s|\n", light_color);
            break;
        default:
            printf("Invalid light number.\n");
            break;
    }
}

void simulate_traffic_light(int duration) {
    int current_light = RED_LIGHT;
    time_t start_time, end_time;

    printf("Starting traffic light simulation for %d seconds...\n", duration);
    time(&start_time);

    while (difftime(time(NULL), start_time) < duration) {
        set_light(current_light, "RED");
        sleep(1);

        set_light(current_light, "YELLOW");
        sleep(1);

        set_light(current_light, "GREEN");
        sleep(1);

        set_light(current_light, "PEDESTRIAN");
        sleep(1);

        current_light++;
        if (current_light > PEDESTRIAN_LIGHT) {
            current_light = RED_LIGHT;
        }
    }

    printf("Traffic light simulation complete.\n");
}

int main() {
    init_lights();
    int duration;

    printf("Enter the duration of the traffic light simulation in seconds: ");
    scanf("%d", &duration);

    simulate_traffic_light(duration);

    return 0;
}