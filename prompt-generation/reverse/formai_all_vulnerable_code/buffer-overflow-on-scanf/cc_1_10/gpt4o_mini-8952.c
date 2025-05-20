//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void enterRoom(int roomNumber);
void hauntedKitchen();
void spookyLibrary();
void eerieHallway();
void ghostEncounter();
void witchEncounter();
void exitHouse();

int main() {
    int choice = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You stand before a creepy old house. Do you dare to enter?\n");
    printf("1. Enter the house\n");
    printf("2. Leave\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int currentRoom = 1;
        while (currentRoom != 0) {
            enterRoom(currentRoom);
            printf("Do you want to explore more rooms or exit the house? (1 for more, 0 to exit): ");
            scanf("%d", &currentRoom);
        }
    } else {
        printf("Thank you for your visit. Stay safe!\n");
    }

    return 0;
}

void enterRoom(int roomNumber) {
    switch (roomNumber) {
        case 1:
            hauntedKitchen();
            break;
        case 2:
            spookyLibrary();
            break;
        case 3:
            eerieHallway();
            break;
        default:
            printf("You have exited the house. Goodbye!\n");
            break;
    }
}

void hauntedKitchen() {
    printf("\nYou have entered the haunted kitchen!\n");
    printf("You see a cauldron bubbling and hear whispers in the air.\n");
    printf("Choose:\n");
    printf("1. Investigate the cauldron\n");
    printf("2. Leave the kitchen\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        int result = rand() % 2;
        if (result == 0) {
            printf("You found a potion! You feel a surge of power!\n");
        } else {
            printf("A witch appears! You are trapped in a spell!\n");
            witchEncounter();
        }
    } else {
        printf("You leave the kitchen and head back.\n");
    }
}

void spookyLibrary() {
    printf("\nYou have entered the spooky library!\n");
    printf("The books are old and dusty. A ghostly figure floats by.\n");
    printf("Choose:\n");
    printf("1. Read a mysterious book\n");
    printf("2. Leave the library\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        ghostEncounter();
    } else {
        printf("You leave the library and head back.\n");
    }
}

void eerieHallway() {
    printf("\nYou are in the eerie hallway!\n");
    printf("You hear footsteps echoing.\n");
    printf("Choose:\n");
    printf("1. Investigate the noise\n");
    printf("2. Retreat to safety\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You bravely walk towards the noise... it's just a creaky board!\n");
    } else {
        printf("You retreat safely to another room.\n");
    }
}

void ghostEncounter() {
    printf("\nA ghost appears and scares you!\n");
    printf("1. Run away\n");
    printf("2. Face your fear\n");
    
    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You ran away and escaped the library!\n");
    } else {
        printf("You stand your ground, and the ghost begins to laugh!\n");
        printf("It's just a friendly ghost! You made a new friend!\n");
    }
}

void witchEncounter() {
    printf("\nYou find yourself trapped by the witch!\n");
    printf("You can:\n");
    printf("1. Try to break the enchantment\n");
    printf("2. Surrender\n");

    int choice;
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("You manage to break free! The witch is furious!\n");
        printf("You escape the kitchen quickly!\n");
    } else {
        printf("The witch potions you, and you fall asleep!\n");
    }
}