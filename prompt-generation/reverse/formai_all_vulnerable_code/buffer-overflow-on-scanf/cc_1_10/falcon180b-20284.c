//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define DURATION_RED_LIGHT 5
#define DURATION_YELLOW_LIGHT 3
#define DURATION_GREEN_LIGHT 7

typedef struct {
    int current_light;
    int duration;
    int time_left;
} Light;

void initialize_light(Light *light, int current_light, int duration) {
    light->current_light = current_light;
    light->duration = duration;
    light->time_left = duration;
}

void change_light(Light *light) {
    if (light->current_light == RED_LIGHT) {
        light->current_light = YELLOW_LIGHT;
    } else if (light->current_light == YELLOW_LIGHT) {
        light->current_light = GREEN_LIGHT;
    } else {
        light->current_light = RED_LIGHT;
    }

    light->time_left = light->duration;
}

void decrement_time(Light *light) {
    if (light->time_left > 0) {
        light->time_left--;
    } else {
        change_light(light);
    }
}

int main() {
    Light light;
    initialize_light(&light, RED_LIGHT, DURATION_RED_LIGHT);

    while (1) {
        printf("Current light: %d\n", light.current_light);
        printf("Time left: %d\n", light.time_left);
        printf("\n");

        fflush(stdout);
        fflush(stdin);

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            change_light(&light);
        } else if (choice == 2) {
            initialize_light(&light, RED_LIGHT, DURATION_RED_LIGHT);
        } else if (choice == 3) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid choice.\n");
        }

        if (light.current_light == GREEN_LIGHT) {
            if (light.time_left == DURATION_GREEN_LIGHT) {
                printf("Light turned red.\n");
                change_light(&light);
            } else {
                printf("Light turned yellow.\n");
                change_light(&light);
            }
        }
    }

    return 0;
}