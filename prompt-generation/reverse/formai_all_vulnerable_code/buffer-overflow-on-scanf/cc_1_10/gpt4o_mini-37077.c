//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void welcomeMessage();
void enterRoom(int room);
void displayMenu();
int getChoice();
void exitHouse();

int main() {
    srand(time(NULL)); // Seed for random choices
    int room = 1; // Starting room
    welcomeMessage();

    while (1) {
        enterRoom(room);
        displayMenu();
        int choice = getChoice();

        switch (choice) {
            case 1:
                printf("You decide to move deeper into the haunted house.\n");
                room++;
                break;
            case 2:
                printf("You turn back and exit the house. You made it out alive!\n");
                exitHouse();
                return 0;
            case 3:
                printf("You sit down and cower in fear. \n");
                if (rand() % 2 == 0) {
                    printf("A ghost appears and scares you out of the house!\n");
                    return 0;
                } else {
                    printf("The ghost ignores you and moves on.\n");
                }
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }

        // If player reaches room 5, they encounter the final ghost
        if (room > 5) {
            printf("You've reached the final room. A massive ghost appears!\n");
            printf("What will you do?\n");
            printf("1. Attempt to fight the ghost\n");
            printf("2. Plead for your life\n");
            printf("3. Run away\n");
            choice = getChoice();

            if (choice == 1) {
                printf("You bravely fight the ghost and it vanishes! You win!\n");
                return 0;
            } else if (choice == 2) {
                printf("The ghost laughs at your plea but loses interest. You sneak out!\n");
                return 0;
            } else if (choice == 3) {
                printf("You run away screaming, never to return again!\n");
                return 0;
            } else {
                printf("Invalid choice! The ghost catches you and you freeze in fear!\n");
                return 0;
            }
        }
    }
}

void welcomeMessage() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Dare to enter? Navigate through eerie rooms and make choices.\n\n");
}

void enterRoom(int room) {
    printf("You are now in room %d.\n", room);
    switch (room) {
        case 1:
            printf("This room is dark and filled with old, dusty furniture.\n");
            break;
        case 2:
            printf("You see shadows moving on the wall. A chill runs down your spine.\n");
            break;
        case 3:
            printf("The floor creaks as you step forward. You sense you are not alone.\n");
            break;
        case 4:
            printf("You find an old portrait that seems to follow your movements.\n");
            break;
        case 5:
            printf("A cold wind blows through. Whispers can be heard.\n");
            break;
        default:
            printf("You are in the final room filled with fog and despair...\n");
            break;
    }
}

void displayMenu() {
    printf("What would you like to do?\n");
    printf("1. Move deeper into the house.\n");
    printf("2. Exit the house.\n");
    printf("3. Sit down and wait.\n");
}

int getChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void exitHouse() {
    printf("Thank you for playing the Haunted House Simulator!\n");
}