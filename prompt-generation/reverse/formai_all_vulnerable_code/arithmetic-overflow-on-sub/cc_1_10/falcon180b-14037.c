//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

int main() {
    int current_light = RED_LIGHT;
    int light_duration[3] = {30, 5, 30}; // seconds
    int light_index = 0;
    time_t start_time;
    time_t end_time;

    printf("Starting Traffic Light Controller\n");

    // Initialize random seed
    srand(time(NULL));

    // Start with red light
    start_time = time(NULL);
    light_index = RED_LIGHT;

    while (1) {
        // Check if time has elapsed
        end_time = time(NULL);
        if (end_time - start_time >= light_duration[light_index]) {
            printf("Light changed from %d to %d\n", current_light, light_index);
            current_light = light_index;
            start_time = end_time;
        }

        // Randomly change light
        if (rand() % 50 == 0) {
            light_index = rand() % 3;
            start_time = time(NULL);
        }

        // Print current light
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
            default:
                printf("Unknown\n");
        }

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}