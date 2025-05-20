//GPT-4o-mini DATASET v1.0 Category: Smart home automation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Kingdom's magical commands and devices
#define TORCH 'T'
#define DOOR 'D'
#define ALTER 'A'
#define LANTERN 'L'
#define WINDOW 'W'

// Function Prototypes
void lightTorch();
void openDoor();
void alterWeather();
void lightLantern();
void openWindow();
void castleGreeting();
void castleMenu();
char castleCommand();

int main() {
    srand(time(NULL)); // Seed the random number generator
    castleGreeting();

    // Main command loop for the automation
    while(1) {
        castleMenu();
        char command = castleCommand();

        switch(command) {
            case TORCH:
                lightTorch();
                break;
            case DOOR:
                openDoor();
                break;
            case ALTER:
                alterWeather();
                break;
            case LANTERN:
                lightLantern();
                break;
            case WINDOW:
                openWindow();
                break;
            case 'Q':
                printf("Thou hast chosen to leave the automation command. Farewell!\n");
                exit(0);
            default:
                printf("Alas! That is not a command that is known to the kingdom.\n");
                break;
        }
    }

    return 0;
}

// Castle Greeting Function
void castleGreeting() {
    printf("Welcome, noble traveler, to the castle of Automation!\n");
    printf("Here, thou shalt command the enchanted devices of this abode.\n");
}

// Display the available commands
void castleMenu() {
    printf("\nEnter thy command with one of the following enchanted symbols:\n");
    printf(" %c : Light the Torch\n", TORCH);
    printf(" %c : Open the Door\n", DOOR);
    printf(" %c : Alter the Weather\n", ALTER);
    printf(" %c : Light the Lantern\n", LANTERN);
    printf(" %c : Open the Window\n", WINDOW);
    printf(" Q : Quit the enchantments\n");
}

// Capture user command
char castleCommand() {
    char command;
    printf("Thy Command: ");
    scanf(" %c", &command);
    return command;
}

// Light the Torch
void lightTorch() {
    printf("The Torch hath been lit, casting a warm glow in thy chamber.\n");
}

// Open the Door with randomness
void openDoor() {
    int chance = rand() % 2;
    if (chance) {
        printf("The grand Door swings open, allowing fresh air to enter the castle.\n");
    } else {
        printf("Alas! The Door resists and remains shut tight, as if guarded by a dragon.\n");
    }
}

// Alter the Weather in the kingdom
void alterWeather() {
    int weather = rand() % 3;
    switch(weather) {
        case 0:
            printf("The skies darken as a storm brews over the castle. Thunder rumbles!\n");
            break;
        case 1:
            printf("Oh! The sun shines brightly, bringing warmth to the fields!\n");
            break;
        case 2:
            printf("A gentle breeze blows through, carrying the aroma of blooming flowers.\n");
            break;
    }
}

// Light the Lantern
void lightLantern() {
    printf("The Lantern hath been lit, illuminating the secrets of the night.\n");
}

// Open the Window
void openWindow() {
    printf("The Window opens wide, allowing the sweet melodies of birds to fill the castle.\n");
}