//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables for light control
    int bedroomLight = 0;
    int livingRoomLight = 0;
    int kitchenLight = 0;
    
    // Medieval-style introduction to the program
    printf("Greetings! I am the lord of this smart home castle. Welcome to my humble abode.\n");
    printf("In this castle, we use advanced technology to control the lighting of our rooms.\n");
    printf("Your wish is my command. Let's get started!\n\n");
    
    // Create an infinite loop for light control
    while (1) {
        // Ask the user which room they would like to control
        printf("Which room's lighting would you like to control?\n");
        printf("1. Bedroom\n");
        printf("2. Living room\n");
        printf("3. Kitchen\n");
        printf("Enter the corresponding number: ");
        
        // Read the user's input as an integer
        int choice;
        scanf("%d", &choice);
        printf("\n");
        
        // Use a switch statement to control the selected room's light
        switch (choice) {
            case 1:
                printf("Entering the bedroom...\n");
                printf("The current light level in the bedroom is %d. Would you like to increase or decrease it?\n", bedroomLight);
                printf("1. Increase\n");
                printf("2. Decrease\n");
                printf("Enter the corresponding number: ");
                int change;
                scanf("%d", &change);
                
                if (change == 1) {
                    printf("Increasing bedroom light level...\n");
                    bedroomLight++;
                } else if (change == 2) {
                    printf("Decreasing bedroom light level...\n");
                    bedroomLight--;
                } else {
                    printf("Invalid input. Please try again.\n");
                }
                
                break;
            case 2:
                printf("Entering the living room...\n");
                printf("The current light level in the living room is %d. Would you like to increase or decrease it?\n", livingRoomLight);
                printf("1. Increase\n");
                printf("2. Decrease\n");
                printf("Enter the corresponding number: ");
                scanf("%d", &change);
                
                if (change == 1) {
                    printf("Increasing living room light level...\n");
                    livingRoomLight++;
                } else if (change == 2) {
                    printf("Decreasing living room light level...\n");
                    livingRoomLight--;
                } else {
                    printf("Invalid input. Please try again.\n");
                }
                
                break;
            case 3:
                printf("Entering the kitchen...\n");
                printf("The current light level in the kitchen is %d. Would you like to increase or decrease it?\n", kitchenLight);
                printf("1. Increase\n");
                printf("2. Decrease\n");
                printf("Enter the corresponding number: ");
                scanf("%d", &change);
                
                if (change == 1) {
                    printf("Increasing kitchen light level...\n");
                    kitchenLight++;
                } else if (change == 2) {
                    printf("Decreasing kitchen light level...\n");
                    kitchenLight--;
                } else {
                    printf("Invalid input. Please try again.\n");
                }
                
                break;
            default:
                printf("Invalid input. Please try again.\n");
        }
        
        // Print the current light levels of each room
        printf("\nThe current light levels are:\n");
        printf("Bedroom: %d\n", bedroomLight);
        printf("Living room: %d\n", livingRoomLight);
        printf("Kitchen: %d\n\n", kitchenLight);
    }
    
    return 0;
}