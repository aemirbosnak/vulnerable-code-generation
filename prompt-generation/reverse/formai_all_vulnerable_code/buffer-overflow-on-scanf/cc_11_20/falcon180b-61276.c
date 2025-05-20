//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define PEDESTRIAN_LIGHT 3

int main() {
    int current_state = RED_LIGHT;
    int next_state = 0;
    int timer = 0;
    int pedestrian_timer = 0;

    while (1) {
        // Check for pedestrian crossing
        if (current_state == RED_LIGHT || current_state == GREEN_LIGHT) {
            if (pedestrian_timer == 0) {
                printf("Pedestrian crossing\n");
                printf("Press Enter to continue...\n");
                if (scanf("%d", &pedestrian_timer)!= 1) {
                    printf("Invalid input\n");
                    exit(1);
                }
            } else {
                pedestrian_timer--;
            }
        }

        // Check for traffic light change
        if (current_state == RED_LIGHT) {
            next_state = GREEN_LIGHT;
        } else if (current_state == GREEN_LIGHT) {
            next_state = YELLOW_LIGHT;
        } else if (current_state == YELLOW_LIGHT) {
            next_state = RED_LIGHT;
        } else if (current_state == PEDESTRIAN_LIGHT) {
            next_state = RED_LIGHT;
        }

        if (current_state!= next_state) {
            printf("Traffic light changing from %d to %d\n", current_state, next_state);
        }

        // Change traffic light state
        current_state = next_state;

        // Wait for appropriate time
        switch (current_state) {
            case RED_LIGHT:
                timer = 30;
                break;
            case YELLOW_LIGHT:
                timer = 5;
                break;
            case GREEN_LIGHT:
                timer = 25;
                break;
            case PEDESTRIAN_LIGHT:
                timer = 15;
                break;
        }

        printf("Current traffic light state: %d\n", current_state);
        printf("Press Enter to continue...\n");
        if (scanf("%d", &timer)!= 1) {
            printf("Invalid input\n");
            exit(1);
        }

        if (timer == 0) {
            printf("Traffic light changing...\n");
        } else {
            printf("Wait for %d seconds...\n", timer);
        }
        sleep(1);
    }

    return 0;
}