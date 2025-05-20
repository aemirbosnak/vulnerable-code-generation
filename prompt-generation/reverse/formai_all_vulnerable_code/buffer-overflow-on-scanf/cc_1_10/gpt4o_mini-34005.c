//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void welcomeMessage() {
    printf("Welcome to the Galactic Explorer!\n");
    printf("You are about to embark on an adventure in a futuristic universe.\n");
    printf("Make wise choices to navigate this vast galaxy. Good luck!\n\n");
}

void showLocation(char *location) {
    printf("You are currently at: %s\n", location);
}

void exploreSpaceStation() {
    printf("You find yourself in a busy space station filled with aliens and intergalactic travelers.\n");
    printf("You can explore the following areas:\n");
    printf("1. Cargo Bay\n");
    printf("2. Quantum Lounge\n");
    printf("3. Hyperdrive Control Room\n");
}

void cargoBay() {
    printf("You enter the Cargo Bay.\n");
    printf("Here you can find various goods and trade items with traders.\n");
    printf("You can:\n");
    printf("1. Trade goods\n");
    printf("2. Talk to a trader\n");
    printf("3. Return to Space Station\n");
}

void quantumLounge() {
    printf("You enter the Quantum Lounge.\n");
    printf("You see several beings enjoying drinks and sharing stories.\n");
    printf("You can:\n");
    printf("1. Order a drink\n");
    printf("2. Listen to stories\n");
    printf("3. Return to Space Station\n");
}

void hyperdriveControlRoom() {
    printf("You enter the Hyperdrive Control Room.\n");
    printf("Here you can learn about spaceship navigation.\n");
    printf("You can:\n");
    printf("1. Talk to the navigator\n");
    printf("2. Examine the control panel\n");
    printf("3. Return to Space Station\n");
}

void processChoice(int choice, char *location) {
    switch(choice) {
        case 1: // Cargo Bay
            cargoBay();
            break;
        case 2: // Quantum Lounge
            quantumLounge();
            break;
        case 3: // Hyperdrive Control Room
            hyperdriveControlRoom();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void navigate() {
    int choice;
    char location[MAX_LENGTH] = "Galactic Space Station";

    welcomeMessage();
    showLocation(location);

    while(1) {
        printf("Choose an area to explore:\n");
        printf("1. Cargo Bay\n");
        printf("2. Quantum Lounge\n");
        printf("3. Hyperdrive Control Room\n");
        printf("4. Exit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Thank you for playing Galactic Explorer! Until next time.\n");
            break;
        }

        processChoice(choice, location);
    }
}

int main() {
    navigate();
    return 0;
}