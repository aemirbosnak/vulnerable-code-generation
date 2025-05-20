//FormAI DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIGHT_ON 1
#define LIGHT_OFF 0

bool isPowerOn = false;
bool isLightOn = false;

void enterPasscode() {
    int passcode;
    printf("Enter the passcode to turn on the power: ");
    scanf("%d", &passcode);
    
    if (passcode == 1234) {
        printf("\nPower turned on!\n");
        isPowerOn = true;
    } else {
        printf("\nIncorrect passcode. Power remains off.\n");
    }
}

void turnOnLight() {
    if (isPowerOn) {
        isLightOn = true;
        printf("\nLight turned on.\n");
    } else {
        printf("\nCannot turn on light. Power is off.\n");
    }
}

void turnOffLight() {
    isLightOn = false;
    printf("\nLight turned off.\n");
}

void displayMenu() {
    printf("\n\n-----------------------------");
    printf("\n\tSMART HOME MENU");
    printf("\n-----------------------------");
    printf("\n1. Turn on power");
    printf("\n2. Turn on light");
    printf("\n3. Turn off light");
    printf("\n4. Exit");
    printf("\n\nEnter your choice: ");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: enterPasscode();
                    break;
            case 2: turnOnLight();
                    break;
            case 3: turnOffLight();
                    break;
            case 4: printf("Goodbye. Stay safe in this post-apocalyptic world.\n");
                    exit(0);
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while(true);
    
    return 0;
}