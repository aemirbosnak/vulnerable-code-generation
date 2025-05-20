//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void welcome();
void chooseRoom();
void encounterGhost();
void displayMenu();

int main() {
    welcome();
    chooseRoom();
    return 0;
}

// Function to print the welcome message
void welcome() {
    printf("***************************************\n");
    printf("*                                     *\n");
    printf("*  WELCOME TO THE HAUNTED HOUSE!     *\n");
    printf("*                                     *\n");
    printf("***************************************\n");
    printf("Prepare yourself for a spine-chilling adventure!\n");
    printf("Press ENTER to continue...\n");
    getchar();
}

// Function to let the user choose a room in the haunted house
void chooseRoom() {
    int choice;

    while (1) {
        printf("\nChoose a room to enter:\n");
        printf("1. The Spooky Living Room\n");
        printf("2. The Creepy Basement\n");
        printf("3. The Eerie Attic\n");
        printf("4. Exit the Haunted House\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                encounterGhost("Living Room");
                break;
            case 2:
                encounterGhost("Basement");
                break;
            case 3:
                encounterGhost("Attic");
                break;
            case 4:
                printf("You have safely exited the haunted house. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid room (1-4).\n");
                break;
        }
    }
}

// Function to simulate encountering a ghost in the chosen room
void encounterGhost(char* room) {
    printf("\nYou enter the %s...\n", room);
    srand(time(NULL));
    int ghost = rand() % 3;

    switch (ghost) {
        case 0:
            printf("A friendly ghost appears! It waves at you and disappears.\n");
            break;
        case 1:
            printf("A spooky spirit suddenly floats in front of you!\n");
            printf("It shivers and vanishes into thin air...\n");
            break;
        case 2:
            printf("A terrifying ghost lurks in the shadows!\n");
            printf("What will you do? Run away, scream, or try to communicate?\n");
            displayMenu();
            break;
    }
}

// Function to display actions when encountering a terrifying ghost
void displayMenu() {
    int action;

    printf("1. Run Away\n");
    printf("2. Scream\n");
    printf("3. Communicate\n");
    printf("Choose your action (1-3): ");
    scanf("%d", &action);

    switch (action) {
        case 1:
            printf("You run away screaming as the ghost chases you out!\n");
            break;
        case 2:
            printf("Your scream echoes through the haunted house. The ghost looks confused and leaves you alone!\n");
            break;
        case 3:
            printf("You attempt to communicate with the ghost...\n");
            printf("It reveals that it just wants to play some games!\n");
            printf("You spent a delightful moment playing hide and seek!\n");
            break;
        default:
            printf("Invalid choice! The ghost laughs at your indecisiveness and vanishes.\n");
            break;
    }
}