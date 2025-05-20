//FormAI DATASET v1.0 Category: Smart home light control ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to turn on the lights
void turnOnLights() {
    printf("Turning on the lights! \n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("Turning off the lights! \n");
}

// Function to dim the lights
void dimLights(int level) {
    printf("Dimming the lights to level %d! \n", level);
}

int main() {
    int choice, level;
    
    printf("Welcome to the Smart Home Light Control \n");
    
    while(1) {
        printf("\nEnter your choice: \n");
        printf("1.Turn On Lights \n");
        printf("2.Turn Off Lights \n");
        printf("3.Dim Lights \n");
        printf("4.Exit \n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                turnOnLights();
                break;
            case 2:
                turnOffLights();
                break;
            case 3:
                printf("Enter the dimming level: ");
                scanf("%d", &level);
                dimLights(level);
                break;
            case 4:
                printf("Exiting the program! \n");
                exit(0);
            default:
                printf("Invalid choice! \n");
                break;
        }
    }
    return 0;
}