//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3

#define RED_LIGHT_TIME 10
#define YELLOW_LIGHT_TIME 5
#define GREEN_LIGHT_TIME 15

int main() {
    int current_light = RED_LIGHT;
    int next_light = GREEN_LIGHT;
    int time_left;
    int choice;

    while (1) {
        printf("Current light: %s\n", current_light == RED_LIGHT? "RED" : current_light == YELLOW_LIGHT? "YELLOW" : "GREEN");
        printf("Press 1 to switch to RED light\n");
        printf("Press 2 to switch to YELLOW light\n");
        printf("Press 3 to switch to GREEN light\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                next_light = RED_LIGHT;
                break;
            case 2:
                next_light = YELLOW_LIGHT;
                break;
            case 3:
                next_light = GREEN_LIGHT;
                break;
            default:
                printf("Invalid choice\n");
                continue;
        }

        time_left = next_light == RED_LIGHT? RED_LIGHT_TIME : next_light == YELLOW_LIGHT? YELLOW_LIGHT_TIME : GREEN_LIGHT_TIME;

        printf("Switching to %s light in %d seconds...\n", next_light == RED_LIGHT? "RED" : next_light == YELLOW_LIGHT? "YELLOW" : "GREEN", time_left);

        for (int i = time_left; i > 0; i--) {
            printf("%d...\n", i);
            sleep(1);
        }

        current_light = next_light;
    }

    return 0;
}