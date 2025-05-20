//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef enum {
    RED,
    GREEN,
    YELLOW,
    OFF
} TrafficLightState;

typedef struct {
    TrafficLightState state;
    int duration; // Duration in seconds for each light
} TrafficLight;

void initializeTrafficLight(TrafficLight* light, int redDuration, int greenDuration, int yellowDuration) {
    light->state = RED; // Start with RED
    light->duration = redDuration;
}

void changeLightState(TrafficLight* light) {
    switch (light->state) {
        case RED:
            light->state = GREEN;
            light->duration = 5; // Set green to persist for 5 seconds
            break;
        case GREEN:
            light->state = YELLOW;
            light->duration = 2; // Set yellow to persist for 2 seconds
            break;
        case YELLOW:
            light->state = RED;
            light->duration = 10; // Set red to persist for 10 seconds
            break;
        default:
            light->state = OFF;
            light->duration = 0;
            break;
    }
}

const char* getLightColor(TrafficLight* light) {
    switch (light->state) {
        case RED: return "RED";
        case GREEN: return "GREEN";
        case YELLOW: return "YELLOW";
        case OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

void displayLightStatus(TrafficLight* light, int cycleCount) {
    printf("Cycle %d: Light is %s\n", cycleCount, getLightColor(light));
    printf("Duration: %d seconds\n", light->duration);
}

void runTrafficLightController(TrafficLight* light, int cycles) {
    for (int i = 0; i < cycles; i++) {
        displayLightStatus(light, i + 1);
        sleep(light->duration);
        changeLightState(light);
    }
}

int main() {
    int cycles;
    printf("Enter the number of cycles for the traffic light controller: ");
    scanf("%d", &cycles);

    TrafficLight trafficLight;
    initializeTrafficLight(&trafficLight, 10, 5, 2); // initial durations for red, green, and yellow.

    runTrafficLightController(&trafficLight, cycles);

    return 0;
}