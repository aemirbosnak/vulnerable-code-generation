//FormAI DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {
    // Initialize all lights to off
    int kitchenLight = FALSE;
    int livingRoomLight = FALSE;
    int bedroomLight = FALSE;

    // Print initial status
    printf("Kitchen light is now %s\n", kitchenLight ? "on" : "off");
    printf("Living room light is now %s\n", livingRoomLight ? "on" : "off");
    printf("Bedroom light is now %s\n\n", bedroomLight ? "on" : "off");

    // Light control loop
    while (TRUE) {
        // Prompt for user input
        printf("Enter a command (kitchen, living room, bedroom, or quit):\n");

        // Read user input
        char command[10];
        scanf("%s", command);

        // Process command
        if (strcmp(command, "kitchen") == 0) {
            // Toggle kitchen light
            kitchenLight = !kitchenLight;
            printf("Kitchen light is now %s\n", kitchenLight ? "on" : "off");
        } else if (strcmp(command, "living room") == 0) {
            // Toggle living room light
            livingRoomLight = !livingRoomLight;
            printf("Living room light is now %s\n", livingRoomLight ? "on" : "off");
        } else if (strcmp(command, "bedroom") == 0) {
            // Toggle bedroom light
            bedroomLight = !bedroomLight;
            printf("Bedroom light is now %s\n", bedroomLight ? "on" : "off");
        } else if (strcmp(command, "quit") == 0) {
            // Exit light control loop
            printf("Goodbye!\n");
            break;
        } else {
            // Invalid command
            printf("Invalid command: %s\n", command);
        }

        // Add some spacing for readability
        printf("\n");
    }

    return 0;
}