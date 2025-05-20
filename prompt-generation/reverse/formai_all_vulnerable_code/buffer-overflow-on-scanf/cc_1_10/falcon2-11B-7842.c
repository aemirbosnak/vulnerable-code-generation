//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: surprised
#include <stdio.h>
#include <string.h>

void turn_on_lights(void);
void turn_off_lights(void);
void dim_lights(void);

int main(void) {
    int choice;

    printf("Welcome to the Smart Home Automation System!\n");
    printf("Please select an action:\n");
    printf("1. Turn on lights\n");
    printf("2. Turn off lights\n");
    printf("3. Dim lights\n");

    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            turn_on_lights();
            break;
        case 2:
            turn_off_lights();
            break;
        case 3:
            dim_lights();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return 0;
    }

    printf("Action completed successfully.\n");

    return 0;
}

void turn_on_lights(void) {
    printf("Turning on lights...\n");
    // Code to turn on lights goes here
}

void turn_off_lights(void) {
    printf("Turning off lights...\n");
    // Code to turn off lights goes here
}

void dim_lights(void) {
    printf("Dimming lights...\n");
    // Code to dim lights goes here
}