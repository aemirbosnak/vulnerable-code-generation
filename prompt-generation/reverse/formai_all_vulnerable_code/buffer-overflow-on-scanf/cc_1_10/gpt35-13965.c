//FormAI DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char userChoice[10];
    int colorOption, brightnessLevel;
    
    printf("Welcome to the Smart Home Light Control Program!\n");
    printf("How can I help you?\n");
    printf("Enter 'on' to turn on the light or 'off' to turn it off: ");
    
    scanf("%s", userChoice);
    
    if(strcmp(userChoice, "on") == 0) {
        printf("\nLight is on. Choose the desired color option:\n");
        printf("1. Red\n2. Yellow\n3. Green\n4. Blue\n5. White\n");
        printf("Enter your choice: ");
        
        scanf("%d", &colorOption);
        
        switch(colorOption) {
            case 1:
                printf("\nRed color is selected.\n");
                break;
            case 2:
                printf("\nYellow color is selected.\n");
                break;
            case 3:
                printf("\nGreen color is selected.\n");
                break;
            case 4:
                printf("\nBlue color is selected.\n");
                break;
            case 5:
                printf("\nWhite color is selected.\n");
                break;
            default:
                printf("\nInvalid input. Try again.\n");
                break;
        }
        
        printf("\nEnter the brightness level (between 1-10): ");
        scanf("%d", &brightnessLevel);
        
        if(brightnessLevel >= 1 && brightnessLevel <= 10) {
            printf("\nBrightness level is set to %d.\n", brightnessLevel);
        } else {
            printf("\nInvalid input. Brightness level should be between 1-10.\n");
        }
        
    } else if(strcmp(userChoice, "off") == 0) {
        printf("\nLight is off.\n");
    } else {
        printf("\nInvalid input. Program terminated.\n");
    }
    
    printf("\nThank you for using the Smart Home Light Control Program.\n");
    
    return 0;
}