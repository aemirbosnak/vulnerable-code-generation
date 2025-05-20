//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 0
#define YELLOW_LIGHT 1
#define GREEN_LIGHT 2
#define LIGHT_INTERVAL 3

int main() {
    int light_state = RED_LIGHT;
    int light_interval = LIGHT_INTERVAL;

    while (1) {
        printf("Current light state: ");
        switch (light_state) {
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
                printf("Invalid state\n");
                break;
        }
        printf("Current light interval: %d seconds\n", light_interval);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Change light state\n");
        printf("2. Change light interval\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new light state (0 for red, 1 for yellow, 2 for green): ");
                scanf("%d", &light_state);
                break;
            case 2:
                printf("Enter new light interval (in seconds): ");
                scanf("%d", &light_interval);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}