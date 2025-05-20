//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT 1
#define YELLOW_LIGHT 2
#define GREEN_LIGHT 3
#define PEDESTRIAN_LIGHT 4
#define NUM_LIGHTS 5

// Function prototypes
void initializeLights(int lights[]);
void displayLights(int lights[]);
void changeLight(int lights[], int lightNumber);

int main() {
    int lights[NUM_LIGHTS] = {RED_LIGHT, YELLOW_LIGHT, GREEN_LIGHT, PEDESTRIAN_LIGHT};
    int lightNumber;

    srand(time(NULL));

    initializeLights(lights);

    while(1) {
        printf("Enter light number to change (0-3): ");
        scanf("%d", &lightNumber);

        if(lightNumber >= 0 && lightNumber <= 3) {
            changeLight(lights, lightNumber);
        } else {
            printf("Invalid light number.\n");
        }

        displayLights(lights);

        sleep(1);
    }

    return 0;
}

void initializeLights(int lights[]) {
    for(int i=0; i<NUM_LIGHTS; i++) {
        lights[i] = rand() % NUM_LIGHTS;
    }
}

void displayLights(int lights[]) {
    printf("Current lights:\n");
    for(int i=0; i<NUM_LIGHTS; i++) {
        switch(lights[i]) {
            case RED_LIGHT:
                printf("Light %d is red.\n", i+1);
                break;
            case YELLOW_LIGHT:
                printf("Light %d is yellow.\n", i+1);
                break;
            case GREEN_LIGHT:
                printf("Light %d is green.\n", i+1);
                break;
            case PEDESTRIAN_LIGHT:
                printf("Light %d is for pedestrians.\n", i+1);
                break;
            default:
                printf("Light %d is off.\n", i+1);
        }
    }
}

void changeLight(int lights[], int lightNumber) {
    int newLight;

    do {
        newLight = rand() % NUM_LIGHTS;
    } while(newLight == lights[lightNumber]);

    lights[lightNumber] = newLight;
}