//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10 // Max number of connected lights

void printMenu() {
    printf("--- Smart Home Light Control ---\n");
    printf("1- Turn on all lights\n");
    printf("2- Turn off all lights\n");
    printf("3- Turn on specific light\n");
    printf("4- Turn off specific light\n");
    printf("5- Exit\n");
}

int main() {
    bool lights[MAX_LIGHTS] = {false}; // Array to store the state of each light
    int choice, lightIndex;

    while(true) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1:
                // Turn on all lights
                for(int i = 0; i < MAX_LIGHTS; i++) {
                    lights[i] = true;
                }
                printf("All lights turned on.\n\n");
                break;

            case 2:
                // Turn off all lights
                for(int i = 0; i < MAX_LIGHTS; i++) {
                    lights[i] = false;
                }
                printf("All lights turned off.\n\n");
                break;

            case 3:
                // Turn on specific light
                printf("Enter light index (1 to %d): ", MAX_LIGHTS);
                scanf("%d", &lightIndex);
                if(lightIndex > 0 && lightIndex <= MAX_LIGHTS) {
                    lights[lightIndex-1] = true;
                    printf("Light %d turned on.\n\n", lightIndex);
                } else {
                    printf("Invalid light index.\n\n");
                }
                break;

            case 4:
                // Turn off specific light
                printf("Enter light index (1 to %d): ", MAX_LIGHTS);
                scanf("%d", &lightIndex);
                if(lightIndex > 0 && lightIndex <= MAX_LIGHTS) {
                    lights[lightIndex-1] = false;
                    printf("Light %d turned off.\n\n", lightIndex);
                } else {
                    printf("Invalid light index.\n\n");
                }
                break;

            case 5:
                // Exit
                printf("Exiting program...");
                exit(0);

            default:
                printf("Invalid choice.\n\n");
                break;
        }
    }
    return 0;
}