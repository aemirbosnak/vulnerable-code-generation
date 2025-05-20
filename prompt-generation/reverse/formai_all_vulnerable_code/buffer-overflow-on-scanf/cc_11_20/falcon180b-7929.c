//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 30
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 25

int main() {
    int redLightDuration = RED_LIGHT_DURATION;
    int yellowLightDuration = YELLOW_LIGHT_DURATION;
    int greenLightDuration = GREEN_LIGHT_DURATION;
    int currentLight = 1; // 1 = red light, 2 = yellow light, 3 = green light
    int pedestrianPress = 0;
    int pedestrianCrossing = 0;
    int emergencyVehicle = 0;

    while (1) {
        if (currentLight == 1) { // red light
            printf("Red light is on.\n");
            if (pedestrianPress) {
                if (!pedestrianCrossing) {
                    printf("Pedestrians are waiting to cross.\n");
                } else {
                    printf("Pedestrians are crossing.\n");
                }
            }
            if (emergencyVehicle) {
                printf("Emergency vehicle detected. Switching to green light.\n");
                currentLight = 3;
            } else {
                sleep(redLightDuration);
                currentLight = 2;
            }
        } else if (currentLight == 2) { // yellow light
            printf("Yellow light is on.\n");
            if (pedestrianPress) {
                if (!pedestrianCrossing) {
                    printf("Pedestrians are waiting to cross.\n");
                } else {
                    printf("Pedestrians are crossing.\n");
                }
            }
            sleep(yellowLightDuration);
            currentLight = 3;
        } else if (currentLight == 3) { // green light
            printf("Green light is on.\n");
            if (pedestrianPress) {
                if (!pedestrianCrossing) {
                    printf("Pedestrians are waiting to cross.\n");
                } else {
                    printf("Pedestrians are crossing.\n");
                }
            }
            if (emergencyVehicle) {
                printf("Emergency vehicle detected. Switching to red light.\n");
                currentLight = 1;
            } else {
                sleep(greenLightDuration);
                currentLight = 2;
            }
        }

        if (pedestrianPress) {
            if (!pedestrianCrossing) {
                printf("Pedestrians are waiting to cross.\n");
            } else {
                printf("Pedestrians are crossing.\n");
            }
        }

        if (emergencyVehicle) {
            printf("Emergency vehicle detected. Switching to green light.\n");
            currentLight = 3;
        }

        if (scanf("%d", &pedestrianPress) == 1) {
            pedestrianPress = 1;
        }

        if (scanf("%d", &pedestrianCrossing) == 1) {
            pedestrianCrossing = 1;
        }

        if (scanf("%d", &emergencyVehicle) == 1) {
            emergencyVehicle = 1;
        }
    }

    return 0;
}