//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3
#define PEDESTRIAN 4
#define NUM_LIGHTS 4

// Function prototypes
void initLights(int lights[]);
void displayLights(int lights[]);
void changeLight(int lights[], int lightNum, int newState);
void advanceLights(int lights[]);

int main() {
    int lights[NUM_LIGHTS] = {RED, RED, RED, PEDESTRIAN};
    int lightNum = 0;

    srand(time(NULL));

    initLights(lights);

    while (1) {
        printf("Enter light number to change (0-3): ");
        scanf("%d", &lightNum);

        if (lightNum >= 0 && lightNum <= 3) {
            printf("Enter new state (1-4): ");
            scanf("%d", &lights[lightNum]);

            changeLight(lights, lightNum, lights[lightNum]);
        } else {
            printf("Invalid light number.\n");
        }

        advanceLights(lights);
        displayLights(lights);

        sleep(1);
    }

    return 0;
}

void initLights(int lights[]) {
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i] = rand() % 4;
    }
}

void displayLights(int lights[]) {
    printf("Current light settings:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        switch (lights[i]) {
            case RED:
                printf("Light %d: Red\n", i + 1);
                break;
            case YELLOW:
                printf("Light %d: Yellow\n", i + 1);
                break;
            case GREEN:
                printf("Light %d: Green\n", i + 1);
                break;
            case PEDESTRIAN:
                printf("Light %d: Pedestrian Crossing\n", i + 1);
                break;
            default:
                printf("Light %d: Unknown State\n", i + 1);
        }
    }
}

void changeLight(int lights[], int lightNum, int newState) {
    lights[lightNum] = newState;
}

void advanceLights(int lights[]) {
    for (int i = 0; i < NUM_LIGHTS - 1; i++) {
        lights[i] = lights[i + 1];
    }

    lights[NUM_LIGHTS - 1] = rand() % 4;
}