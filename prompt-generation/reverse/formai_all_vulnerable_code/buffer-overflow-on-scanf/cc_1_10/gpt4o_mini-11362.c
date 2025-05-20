//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LIGHT_ON "The lights are now brighter than your future!"
#define LIGHT_OFF "The lights have been turned off, just like your motivation."
#define DOOR_LOCKED "The door is now locked. Sorry, no pizza for you."
#define DOOR_UNLOCKED "The door is unlocked... But please don't let the squirrels in!"
#define COFFEE_MADE "Enjoy your coffee! Enjoy your third cup this hour!"
#define COFFEE_NOT_MADE "No coffee for you, you have already reached caffeine limit!"

enum DeviceState {
    LIGHT,
    DOOR,
    COFFEE
};

typedef struct {
    enum DeviceState state;
    int isLightOn;
    int isDoorLocked;
    int coffeeCount;
} SmartHome;

// Function Prototypes
void controlLights(SmartHome *home);
void controlDoor(SmartHome *home);
void makeCoffee(SmartHome *home);
void displayMenu();
void resetSmartHome(SmartHome *home);

int main() {
    SmartHome myHome = {LIGHT, 0, 1, 0};
    int choice;

    printf("Welcome to your Smart Home! Buckle up and let's automate your life!\n");

    while(1) {
        displayMenu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                controlLights(&myHome); 
                break;
            case 2: 
                controlDoor(&myHome); 
                break;
            case 3: 
                makeCoffee(&myHome); 
                break;
            case 4: 
                resetSmartHome(&myHome); 
                printf("Smart Home has been reset. Good luck cleaning up!\n");
                break;
            case 5: 
                printf("Exiting... Now you can start living like a caveman.\n");
                return 0;
            default: 
                printf("That's not a choice! Did you eat glue as a kid?\n");
        }
    }
}

void displayMenu() {
    printf("\n=== Smart Home Control Menu ===\n");
    printf("1. Control Lights\n");
    printf("2. Control Door\n");
    printf("3. Make Coffee\n");
    printf("4. Reset Smart Home\n");
    printf("5. Exit\n");
}

void controlLights(SmartHome *home) {
    if (home->isLightOn) {
        home->isLightOn = 0;
        printf("%s\n", LIGHT_OFF);
    } else {
        home->isLightOn = 1;
        printf("%s\n", LIGHT_ON);
    }
}

void controlDoor(SmartHome *home) {
    if (home->isDoorLocked) {
        home->isDoorLocked = 0;
        printf("%s\n", DOOR_UNLOCKED);
    } else {
        home->isDoorLocked = 1;
        printf("%s\n", DOOR_LOCKED);
    }
}

void makeCoffee(SmartHome *home) {
    if (home->coffeeCount < 5) { // Speed limit on caffeine
        home->coffeeCount++;
        printf("%s\n", COFFEE_MADE);
    } else {
        printf("%s\n", COFFEE_NOT_MADE);
    }
}

void resetSmartHome(SmartHome *home) {
    home->isLightOn = 0;
    home->isDoorLocked = 1;
    home->coffeeCount = 0;
    printf("Your smart home has been reset to initial settings. Good luck with that!\n");
}