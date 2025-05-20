//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

// Enumeration for traffic light states
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

void displayLight(TrafficLightState state) {
    switch (state) {
        case RED:
            printf("🚦 Red Light - Stop!\n");
            break;
        case GREEN:
            printf("🚦 Green Light - Go!\n");
            break;
        case YELLOW:
            printf("🚦 Yellow Light - Caution!\n");
            break;
        default:
            printf("Unknown light state!\n");
            break;
    }
}

TrafficLightState nextState(TrafficLightState current) {
    switch (current) {
        case RED:
            return GREEN;
        case GREEN:
            return YELLOW;
        case YELLOW:
            return RED;
        default:
            return RED; // Fallback to RED
    }
}

void trafficLightCycle() {
    TrafficLightState currentState = RED;
    
    while (1) {
        displayLight(currentState);
        
        // Timing intervals for each light state
        switch (currentState) {
            case RED:
                sleep(7); // Red for 7 seconds
                break;
            case GREEN:
                sleep(5); // Green for 5 seconds
                break;
            case YELLOW:
                sleep(3); // Yellow for 3 seconds
                break;
        }
        
        // Transition to the next state
        currentState = nextState(currentState);
    }
}

void showMenu() {
    printf("\nTraffic Light Controller Menu\n");
    printf("1. Start traffic light cycle\n");
    printf("2. Exit\n");
    printf("Choose an option (1 or 2): ");
}

int main() {
    int choice;
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Starting the traffic light cycle...\n");
                trafficLightCycle();
                break;
            case 2:
                printf("Exiting the traffic light controller.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select 1 or 2.\n");
                break;
        }
    }
    
    return 0;
}