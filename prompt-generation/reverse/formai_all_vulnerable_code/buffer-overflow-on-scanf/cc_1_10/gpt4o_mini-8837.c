//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function

// Enum to represent the state of the traffic light
typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

// Function to get the string representation of the traffic light state
const char* getTrafficLightStr(TrafficLightState state) {
    switch (state) {
        case RED: return "RED";
        case GREEN: return "GREEN";
        case YELLOW: return "YELLOW";
        default: return "UNKNOWN";
    }
}

// Function to display the current state of the traffic light
void displayTrafficLight(TrafficLightState state) {
    printf("Current Traffic Light: %s\n", getTrafficLightStr(state));
}

// Function to simulate the traffic light controller
void trafficLightController() {
    TrafficLightState currentState = RED;

    while (1) {
        switch (currentState) {
            case RED:
                displayTrafficLight(RED);
                sleep(5); // RED light for 5 seconds
                currentState = GREEN;
                break;

            case GREEN:
                displayTrafficLight(GREEN);
                sleep(5); // GREEN light for 5 seconds
                currentState = YELLOW;
                break;

            case YELLOW:
                displayTrafficLight(YELLOW);
                sleep(2); // YELLOW light for 2 seconds
                currentState = RED;
                break;
        }
    }
}

// Function to print the menu
void printMenu() {
    printf("\nTraffic Light Controller Menu:\n");
    printf("1. Start Traffic Light\n");
    printf("2. Stop Traffic Light\n");
    printf("3. View Current Light State\n");
    printf("4. Exit\n");
}

// Main function to interact with the user
int main() {
    int choice;
    int running = 1;

    while (running) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Starting the Traffic Light Controller...\n");
                trafficLightController(); // This will run indefinitely
                break;
            case 2:
                printf("Stopping the Traffic Light Controller...\n");
                running = 0; // Change running status to exit the loop
                break;
            case 3:
                printf("Current light state is not available while running.\n");
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                running = 0; // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}