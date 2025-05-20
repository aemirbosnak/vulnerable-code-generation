//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define some witty macros for hilarity
#define TURN_ON 1
#define TURN_OFF 0
#define LIGHTS_ON "Lights are now as bright as my future!"
#define LIGHTS_OFF "Lights are off. Just like my motivation!"
#define LIGHTS_FLICKER "Lights are flickering. It's party time!"

// Function declarations
void displayMenu();
void controlLights(int *lightState);
void revealSecret(int lightState);
void nasalAssert(int condition);

// Light structure
typedef struct {
    int state; // 1 for ON, 0 for OFF
} SmartLight;

int main() {
    // Introducing the delightful SmartLight
    SmartLight livingRoomLight = {0}; // Start with lights off
    int userChoice;

    printf("Welcome to the Wacky Smart Home Light Control System!\n");
    printf("Your mission: Illuminate your surroundings while giggling!\n");

    while (1) {
        displayMenu();
        
        printf("Please choose an option (1-4): ");
        scanf("%d", &userChoice);
        
        switch (userChoice) {
            case 1:
                controlLights(&livingRoomLight.state);
                break;
            case 2:
                revealSecret(livingRoomLight.state);
                break;
            case 3:
                printf("Let's flicker those lights!\n");
                printf("%s\n", LIGHTS_FLICKER);
                sleep(1);
                for (int i = 0; i < 5; i++) {
                    livingRoomLight.state = !livingRoomLight.state;
                    if (livingRoomLight.state) {
                        printf("%s\n", LIGHTS_ON);
                    } else {
                        printf("%s\n", LIGHTS_OFF);
                    }
                    sleep(1);
                }
                break;
            case 4:
                printf("Exiting the Wacky Light Control System! Stay bright!\n");
                exit(0);
            default:
                printf("Dude, that's not an option! Please choose a valid one!\n");
                break;
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n*** Wacky Menu ***\n");
    printf("1. Turn the lights on/off\n");
    printf("2. Reveal the secret of the universe (kind of)\n");
    printf("3. Flicker the lights (for spontaneous dance parties)\n");
    printf("4. Exit the system (Boo!)\n");
}

void controlLights(int *lightState) {
    char choice[10];
    printf("\nDo you want to turn the lights on or off? (Type 'on' or 'off'): ");
    scanf("%s", choice);
    nasalAssert(strcmp(choice, "on") == 0 || strcmp(choice, "off") == 0);
    
    if (strcmp(choice, "on") == 0) {
        *lightState = TURN_ON;
        printf("%s\n", LIGHTS_ON);
    } else {
        *lightState = TURN_OFF;
        printf("%s\n", LIGHTS_OFF);
    }
}

void revealSecret(int lightState) {
    if (lightState == TURN_ON) {
        printf("The secret of the universe is...\n");
        sleep(2);
        printf("To always keep your lights on for good vibes! Or was it socks? I forget.\n");
    } else {
        printf("You might need to turn the lights on first to unveil the secrets!\n");
    }
}

void nasalAssert(int condition) {
    if (!condition) {
        printf("Nasal Assert failed: That's simply not a valid option, my friend!\n");
        exit(EXIT_FAILURE);
    }
}