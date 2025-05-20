//FormAI DATASET v1.0 Category: Smart home light control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printMenu(){
    printf("\nWelcome to Smart Home Light Control System!\n");
    printf("1. Get Light Status\n");
    printf("2. Turn Light On\n");
    printf("3. Turn Light Off\n");
    printf("4. Change Light Color\n");
    printf("5. Exit\n");
}

int main(){
    bool isLightOn = false;
    int lightColor = 0;
    bool isRunning = true;

    while(isRunning){
        printMenu();
        int option;
        printf("Please enter your choice (1-5): ");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                printf("Light status: %s\n", isLightOn ? "On" : "Off");
                break;
            case 2:
                printf("Turning light on...\n");
                isLightOn = true;
                lightColor = 1;
                break;
            case 3:
                printf("Turning light off...\n");
                isLightOn = false;
                lightColor = 0;
                break;
            case 4:
                printf("Select light color (1-5): ");
                int colorOption;
                scanf("%d", &colorOption);
                if(colorOption >= 1 && colorOption <= 5){
                    printf("Changing light color to %d\n", colorOption);
                    lightColor = colorOption;
                }
                else {
                    printf("Invalid color option!\n");
                }
                break;
            case 5:
                printf("Exiting program...\n");
                isRunning = false;
                break;
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}