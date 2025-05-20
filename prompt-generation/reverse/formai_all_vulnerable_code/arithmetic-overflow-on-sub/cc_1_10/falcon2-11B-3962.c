//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int red = 1, yellow = 1, green = 1;
int waitTime = 10;
int delayTime = 5;
int totalWaitTime = 0;

// Function to set the traffic light
void setTrafficLight(int light) {
    switch (light) {
        case 0:
            printf("Traffic light is RED\n");
            break;
        case 1:
            printf("Traffic light is YELLOW\n");
            break;
        case 2:
            printf("Traffic light is GREEN\n");
            break;
        default:
            printf("Invalid light setting\n");
    }
}

// Function to change the traffic light
void changeTrafficLight(int newLight) {
    switch (newLight) {
        case 0:
            printf("Changing traffic light to RED\n");
            break;
        case 1:
            printf("Changing traffic light to YELLOW\n");
            break;
        case 2:
            printf("Changing traffic light to GREEN\n");
            break;
        default:
            printf("Invalid light setting\n");
    }
    red = newLight;
}

// Function to check if it's time to change the traffic light
void checkTrafficLight() {
    int currentTime = time(NULL);
    if ((currentTime - totalWaitTime) >= waitTime) {
        setTrafficLight(red == 1? 2 : 1);
        totalWaitTime = currentTime;
    }
}

int main() {
    printf("Traffic light controller started\n");
    while (1) {
        checkTrafficLight();
        changeTrafficLight(red);
        setTrafficLight(green);
        checkTrafficLight();
        changeTrafficLight(yellow);
        setTrafficLight(red);
        checkTrafficLight();
        changeTrafficLight(green);
        setTrafficLight(yellow);
        checkTrafficLight();
        changeTrafficLight(red);
        setTrafficLight(green);
        checkTrafficLight();
    }
    return 0;
}