//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep() function

typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

void displayLight(TrafficLightState state) {
    switch(state) {
        case RED:
            printf("   [ RED ]   \n");
            break;
        case YELLOW:
            printf("  [ YELLOW ]  \n");
            break;
        case GREEN:
            printf("  [ GREEN ]  \n");
            break;
    }
}

void waitForInput(char* message) {
    printf("%s", message);
    getchar();  // Wait for user input
}

int main() {
    TrafficLightState currentState = RED;
    int redTime = 5;
    int yellowTime = 2;
    int greenTime = 5;
    char option;

    printf("Welcome to the Traffic Light Controller!\n");
    
    while (1) {
        system("clear");  // Clear the console (Linux specific)

        displayLight(currentState);

        switch(currentState) {
            case RED:
                waitForInput("RED light is ON. Press Enter to change to GREEN!\n");
                sleep(redTime);
                currentState = GREEN;
                break;

            case GREEN:
                waitForInput("GREEN light is ON. Press Enter to change to YELLOW!\n");
                sleep(greenTime);
                currentState = YELLOW;
                break;

            case YELLOW:
                waitForInput("YELLOW light is ON. Press Enter to change to RED!\n");
                sleep(yellowTime);
                currentState = RED;
                break;
        }

        printf("Do you want to change the timings? (Y/N): ");
        scanf(" %c", &option);
        if (option == 'Y' || option == 'y') {
            printf("Enter time for RED light (current = %d seconds): ", redTime);
            scanf("%d", &redTime);
            printf("Enter time for YELLOW light (current = %d seconds): ", yellowTime);
            scanf("%d", &yellowTime);
            printf("Enter time for GREEN light (current = %d seconds): ", greenTime);
            scanf("%d", &greenTime);
        }

        printf("Press Enter to continue or any other key to exit...\n");
        getchar();  // Consume newline from previous input
        option = getchar();
        if (option != '\n') {
            break;  // Exit loop on any key press
        }
    }

    printf("Thank you for using the Traffic Light Controller!\n");
    return 0;
}