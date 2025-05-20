//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLightState;

void displayMenu() {
    printf("\nTraffic Light Controller Menu:\n");
    printf("1. Set Traffic Light to RED\n");
    printf("2. Set Traffic Light to GREEN\n");
    printf("3. Set Traffic Light to YELLOW\n");
    printf("4. Exit\n");
    printf("Please choose an option (1-4): ");
}

void delay(int seconds) {
    sleep(seconds);
}

void setTrafficLight(TrafficLightState state) {
    switch (state) {
        case RED:
            printf("Traffic Light is RED. Please stop!\n");
            delay(5);
            break;
        case GREEN:
            printf("Traffic Light is GREEN. You can go!\n");
            delay(5);
            break;
        case YELLOW:
            printf("Traffic Light is YELLOW. Get ready to stop!\n");
            delay(2);
            break;
        default:
            printf("Invalid state!\n");
    }
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        displayMenu();

        // Ensure that input is valid
        while (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 4: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        switch (choice) {
            case 1:
                setTrafficLight(RED);
                break;
            case 2:
                setTrafficLight(GREEN);
                break;
            case 3:
                setTrafficLight(YELLOW);
                break;
            case 4:
                printf("Exiting the Traffic Light Controller...\n");
                running = false;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}