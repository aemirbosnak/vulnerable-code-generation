//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

typedef struct {
    TrafficLightState state;
    unsigned int redDuration;
    unsigned int greenDuration;
    unsigned int yellowDuration;
} TrafficLight;

void initializeTrafficLight(TrafficLight* light, unsigned int red, unsigned int green, unsigned int yellow) {
    light->state = RED;
    light->redDuration = red;
    light->greenDuration = green;
    light->yellowDuration = yellow;
}

void changeLight(TrafficLight* light) {
    switch (light->state) {
        case RED:
            printf("The traffic light is RED. Please stop.\n");
            sleep(light->redDuration);
            light->state = GREEN;
            break;
        case GREEN:
            printf("The traffic light is GREEN. You may go.\n");
            sleep(light->greenDuration);
            light->state = YELLOW;
            break;
        case YELLOW:
            printf("The traffic light is YELLOW. Prepare to stop.\n");
            sleep(light->yellowDuration);
            light->state = RED;
            break;
    }
}

void runTrafficLight(TrafficLight* light) {
    while (1) {
        changeLight(light);
    }
}

void customTrafficLightBehavior(TrafficLight* light) {
    unsigned int cycles;
    printf("Enter the number of cycles for the traffic light: ");
    scanf("%u", &cycles);
    
    for (unsigned int i = 0; i < cycles; i++) {
        changeLight(light);
    }
}

int main() {
    TrafficLight light;
    
    // Define duration of each state in seconds
    unsigned int redDuration = 10;
    unsigned int greenDuration = 5;
    unsigned int yellowDuration = 3;
    
    // Initialize the traffic light with specified durations
    initializeTrafficLight(&light, redDuration, greenDuration, yellowDuration);
    
    // Ask user for custom behavior or to run forever
    int choice;
    printf("Choose an option:\n1. Run traffic light indefinitely\n2. Custom number of cycles\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Running traffic light indefinitely...\n");
        runTrafficLight(&light);
    } else if (choice == 2) {
        customTrafficLightBehavior(&light);
    } else {
        printf("Invalid choice! Exiting program.\n");
    }

    return 0;
}