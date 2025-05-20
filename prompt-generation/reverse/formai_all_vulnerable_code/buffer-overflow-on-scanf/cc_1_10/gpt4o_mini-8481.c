//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightColor;

void displayTrafficLight(TrafficLightColor color) {
    switch (color) {
        case RED:
            printf("\n\t\t\t   [RED]\n");
            printf("\t\t\t   •\n");
            printf("\t\t\t   •\n");
            printf("\t\t\t   •\n");
            break;
        case GREEN:
            printf("\n\t\t\t   [GREEN]\n");
            printf("\t\t\t   •\n");
            printf("\t\t\t   •\n");
            printf("\t\t\t   •\n");
            break;
        case YELLOW:
            printf("\n\t\t\t   [YELLOW]\n");
            printf("\t\t\t   •\n");
            printf("\t\t\t   •\n");
            printf("\t\t\t   •\n");
            break;
        default:
            printf("Invalid Traffic Light Color!\n");
    }
}

void waitForMilliseconds(int milliseconds) {
    usleep(milliseconds * 1000);
}

void startTrafficLightSimulation(int redDelay, int greenDelay, int yellowDelay) {
    while (1) {
        displayTrafficLight(RED);
        waitForMilliseconds(redDelay);

        displayTrafficLight(YELLOW);
        waitForMilliseconds(yellowDelay);

        displayTrafficLight(GREEN);
        waitForMilliseconds(greenDelay);

        displayTrafficLight(YELLOW);
        waitForMilliseconds(yellowDelay);
    }
}

int main() {
    int redDelay, greenDelay, yellowDelay;

    printf("Welcome to the Traffic Light Controller!\n");
    printf("Please set the delays for each color in milliseconds:\n");

    printf("Red Delay: ");
    scanf("%d", &redDelay);
    
    printf("Green Delay: ");
    scanf("%d", &greenDelay);
    
    printf("Yellow Delay: ");
    scanf("%d", &yellowDelay);

    printf("\nStarting Traffic Light Simulation...\n");
    
    startTrafficLightSimulation(redDelay, greenDelay, yellowDelay);

    return 0;
}