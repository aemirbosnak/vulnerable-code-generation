//FormAI DATASET v1.0 Category: Smart home light control ; Style: energetic
// Welcome to the Smart Home Light Control example program!
// This program lets you control your home lights remotely from your smartphone.

#include <stdio.h>

int main() { 
    
    // Initialize variables for light and room status
    int kitchenLight = 0;
    int livingRoomLight = 0;
    int bedroomLight = 0;
    int kitchenDimmer = 0;
    int livingRoomDimmer = 0;
    int bedroomDimmer = 0;
    
    // Loop to continuously prompt user for input
    while(1) {
        
        // Display menu
        printf("\nSelect an option: \n");
        printf("1. Turn on kitchen light\n");
        printf("2. Turn off kitchen light\n");
        printf("3. Turn on living room light\n");
        printf("4. Turn off living room light\n");
        printf("5. Turn on bedroom light\n");
        printf("6. Turn off bedroom light\n");
        printf("7. Adjust kitchen dimmer\n");
        printf("8. Adjust living room dimmer\n");
        printf("9. Adjust bedroom dimmer\n");
        printf("10. Exit program\n");
        
        // Prompt for user input
        int option;
        scanf("%d", &option);
        
        // Evaluate user input and execute corresponding action
        if(option == 1) {
            kitchenLight = 1;
            printf("Kitchen light turned on.\n");
        } else if(option == 2) {
            kitchenLight = 0;
            printf("Kitchen light turned off.\n");
        } else if(option == 3) {
            livingRoomLight = 1;
            printf("Living room light turned on.\n");
        } else if(option == 4) {
            livingRoomLight = 0;
            printf("Living room light turned off.\n");
        } else if(option == 5) {
            bedroomLight = 1;
            printf("Bedroom light turned on.\n");
        } else if(option == 6) {
            bedroomLight = 0;
            printf("Bedroom light turned off.\n");
        } else if(option == 7) {
            printf("Enter new brightness level (0-10): ");
            scanf("%d", &kitchenDimmer);
            printf("Kitchen dimmer adjusted to %d.\n", kitchenDimmer);
        } else if(option == 8) {
            printf("Enter new brightness level (0-10): ");
            scanf("%d", &livingRoomDimmer);
            printf("Living room dimmer adjusted to %d.\n", livingRoomDimmer);
        } else if(option == 9) {
            printf("Enter new brightness level (0-10): ");
            scanf("%d", &bedroomDimmer);
            printf("Bedroom dimmer adjusted to %d.\n", bedroomDimmer);
        } else if(option == 10) {
            printf("Program terminated.\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
    
    return 0;
}