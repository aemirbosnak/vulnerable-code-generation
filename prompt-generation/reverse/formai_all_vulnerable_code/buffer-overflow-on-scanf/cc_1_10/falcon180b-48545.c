//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2

#define RED_LIGHT_DELAY 10
#define YELLOW_LIGHT_DELAY 5
#define GREEN_LIGHT_DELAY 15

void traffic_light_controller(int* current_light) {
    int light_state = *current_light;
    int new_light_state = RED_LIGHT;
    int delay;

    if (light_state == RED_LIGHT) {
        delay = RED_LIGHT_DELAY;
    } else if (light_state == YELLOW_LIGHT) {
        delay = YELLOW_LIGHT_DELAY;
    } else if (light_state == GREEN_LIGHT) {
        delay = GREEN_LIGHT_DELAY;
    }

    printf("Current light state: %d\n", light_state);
    printf("New light state: %d\n", new_light_state);
    printf("Delay: %d seconds\n\n", delay);

    switch (new_light_state) {
        case RED_LIGHT:
            printf("Traffic light is now red.\n");
            break;
        case YELLOW_LIGHT:
            printf("Traffic light is now yellow.\n");
            break;
        case GREEN_LIGHT:
            printf("Traffic light is now green.\n");
            break;
    }

    *current_light = new_light_state;
}

int main() {
    int current_light = RED_LIGHT;
    int choice;
    int delay;

    while (1) {
        printf("Current light state: %d\n", current_light);
        printf("1. Change to red\n2. Change to yellow\n3. Change to green\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traffic_light_controller(&current_light);
                break;
            case 2:
                traffic_light_controller(&current_light);
                break;
            case 3:
                traffic_light_controller(&current_light);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        delay = rand() % 5 + 1;
        printf("Delay for %d seconds...\n", delay);
        for (int i = 0; i < delay; i++) {
            printf("%d...\n", delay - i);
            sleep(1);
        }
    }

    return 0;
}