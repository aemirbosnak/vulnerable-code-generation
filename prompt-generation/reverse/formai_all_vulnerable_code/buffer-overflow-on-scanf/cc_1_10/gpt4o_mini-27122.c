//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    RED, 
    GREEN, 
    YELLOW
} TrafficLightState;

typedef struct {
    TrafficLightState currentState;
    int redDuration;
    int greenDuration;
    int yellowDuration;
} TrafficLight;

void initTrafficLight(TrafficLight *light, int red, int green, int yellow) {
    light->currentState = RED;
    light->redDuration = red;
    light->greenDuration = green;
    light->yellowDuration = yellow;
}

void displayLightState(TrafficLightState state) {
    switch (state) {
        case RED:
            printf("Current Light: RED\n");
            break;
        case GREEN:
            printf("Current Light: GREEN\n");
            break;
        case YELLOW:
            printf("Current Light: YELLOW\n");
            break;
        default:
            printf("Unknown State\n");
            break;
    }
}

void changeLightState(TrafficLight *light) {
    switch (light->currentState) {
        case RED:
            light->currentState = GREEN;
            break;
        case GREEN:
            light->currentState = YELLOW;
            break;
        case YELLOW:
            light->currentState = RED;
            break;
        default:
            printf("Error: Unknown traffic light state!\n");
            exit(EXIT_FAILURE);
    }
}

void runTrafficLight(TrafficLight *light) {
    while (1) {
        displayLightState(light->currentState);
        
        switch (light->currentState) {
            case RED:
                sleep(light->redDuration);
                break;
            case GREEN:
                sleep(light->greenDuration);
                break;
            case YELLOW:
                sleep(light->yellowDuration);
                break;
            default:
                printf("Error: Unknown state during run!\n");
                exit(EXIT_FAILURE);
        }
        
        changeLightState(light);
    }
}

int main() {
    TrafficLight light;
    int redDuration, greenDuration, yellowDuration;

    printf("Traffic Light Controller Simulation\n");
    
    // Input durations for each light phase
    printf("Enter duration for RED light (in seconds): ");
    scanf("%d", &redDuration);

    printf("Enter duration for GREEN light (in seconds): ");
    scanf("%d", &greenDuration);

    printf("Enter duration for YELLOW light (in seconds): ");
    scanf("%d", &yellowDuration);
    
    // Initialize the traffic light with the user-defined durations
    initTrafficLight(&light, redDuration, greenDuration, yellowDuration);
    
    // Start running the traffic light simulation
    runTrafficLight(&light);
    
    return 0;
}