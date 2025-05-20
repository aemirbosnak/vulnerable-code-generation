//FormAI DATASET v1.0 Category: Smart home light control ; Style: modular
#include <stdio.h>
#include <stdbool.h>

/* Function declarations */
void turnOnLight(int lightId);
void turnOffLight(int lightId);
void toggleLight(int lightId);

/* Main program */
int main() {
    bool isRunning = true;
    
    while (isRunning) {
        int choice;
        printf("Please enter your choice:\n");
        printf("1 - Turn on light\n");
        printf("2 - Turn off light\n");
        printf("3 - Toggle light\n");
        printf("4 - Exit program\n");
        scanf("%d", &choice);
        
        int lightId;
        switch(choice) {
            case 1:
                printf("Enter light id: ");
                scanf("%d", &lightId);
                turnOnLight(lightId);
                break;
            case 2:
                printf("Enter light id: ");
                scanf("%d", &lightId);
                turnOffLight(lightId);
                break;
            case 3:
                printf("Enter light id: ");
                scanf("%d", &lightId);
                toggleLight(lightId);
                break;
            case 4:
                isRunning = false;
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }   
    }
    
    return 0;
}

/* Function definitions */

void turnOnLight(int lightId) {
    printf("Turning on light %d\n", lightId);
    // Code to turn on the light goes here
}

void turnOffLight(int lightId) {
    printf("Turning off light %d\n", lightId);
    // Code to turn off the light goes here
}

void toggleLight(int lightId) {
    printf("Toggling light %d\n", lightId);
    // Code to toggle the light goes here
}