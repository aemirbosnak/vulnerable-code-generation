//FormAI DATASET v1.0 Category: Smart home automation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Function declarations
void lightOn();
void lightOff();
void fanOn();
void fanOff();
void acOn();
void acOff();

int main() {
    int time, option;
    
    // Main menu
    printf("Welcome to Smart Home Automation System\n\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Turn on fan\n");
    printf("4. Turn off fan\n");
    printf("5. Turn on AC\n");
    printf("6. Turn off AC\n");
    printf("7. Exit\n");
    
    do {
        // Get user input for time and option
        printf("\nEnter the time (24 hour format): ");
        scanf("%d", &time);

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Turning on the lights at %d:00\n", time);
                lightOn();
                break;

            case 2:
                printf("Turning off the lights at %d:00\n", time);
                lightOff();
                break;

            case 3:
                printf("Turning on the fan at %d:00\n", time);
                fanOn();
                break;

            case 4:
                printf("Turning off the fan at %d:00\n", time);
                fanOff();
                break;

            case 5:
                printf("Turning on the AC at %d:00\n", time);
                acOn();
                break;

            case 6:
                printf("Turning off the AC at %d:00\n", time);
                acOff();
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid option\n");
                break;
        }
    } while (1);

    return 0;
}

// Function definitions
void lightOn() {
    printf("Lights turned on\n");
}

void lightOff() {
    printf("Lights turned off\n");
}

void fanOn() {
    printf("Fan turned on\n");
}

void fanOff() {
    printf("Fan turned off\n");
}

void acOn() {
    printf("AC turned on\n");
}

void acOff() {
    printf("AC turned off\n");
}