//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_SEC 30
#define GREEN_LIGHT_SEC 30
#define YELLOW_LIGHT_SEC 5

void traffic_light_controller(void) {
    int red_light_time = RED_LIGHT_SEC;
    int green_light_time = GREEN_LIGHT_SEC;
    int yellow_light_time = YELLOW_LIGHT_SEC;

    while (1) {
        printf("Traffic light controller:\n");
        printf("Red light is on for %d seconds\n", red_light_time);
        printf("Green light is on for %d seconds\n", green_light_time);
        printf("Yellow light is on for %d seconds\n", yellow_light_time);

        printf("\nPress 1 to increase red light time\n");
        printf("Press 2 to decrease red light time\n");
        printf("Press 3 to increase green light time\n");
        printf("Press 4 to decrease green light time\n");
        printf("Press 5 to increase yellow light time\n");
        printf("Press 6 to decrease yellow light time\n");
        printf("Press any other key to exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                red_light_time++;
                break;
            case 2:
                if (red_light_time > 1) {
                    red_light_time--;
                }
                break;
            case 3:
                green_light_time++;
                break;
            case 4:
                if (green_light_time > 1) {
                    green_light_time--;
                }
                break;
            case 5:
                yellow_light_time++;
                break;
            case 6:
                if (yellow_light_time > 1) {
                    yellow_light_time--;
                }
                break;
            default:
                exit(0);
        }

        printf("\nCurrent traffic light timings:\n");
        printf("Red light is on for %d seconds\n", red_light_time);
        printf("Green light is on for %d seconds\n", green_light_time);
        printf("Yellow light is on for %d seconds\n", yellow_light_time);

        sleep(1);
    }
}

int main() {
    srand(time(0));

    int num_lights = rand() % 10 + 1;

    printf("Number of traffic lights: %d\n", num_lights);

    for (int i = 1; i <= num_lights; i++) {
        traffic_light_controller();
    }

    return 0;
}