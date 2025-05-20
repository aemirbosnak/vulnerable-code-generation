//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function prototypes
void printIntro();
int roomOne();
int roomTwo();
void endGame();

int main() {
    printIntro();

    int currentRoom = roomOne();
  
    // Loop through rooms until endGame() function is called
    while (currentRoom != 3) {
        switch (currentRoom) {
            case 1:
                currentRoom = roomOne();
                break;
            case 2:
                currentRoom = roomTwo();
                break;
            default:
                printf("Invalid room number!\n");
                exit(1);
        }
    }

    endGame();
    return 0;
}

/* prints game introduction */
void printIntro() {
    printf("Welcome to the adventure game!\n\n");
    printf("You find yourself in a room with two doors.\n");
    printf("One door is labelled '1' and the other '2'.\n\n");
}

/* represents the story and choices in the first room */
int roomOne() {
    printf("Which door would you like to go through?\n");
    printf("Enter '1' to go through the first door.\n");
    printf("Enter '2' to go through the second door.\n\n");

    char choice;
    scanf(" %c", &choice);
    choice = tolower(choice);

    // Loop through input validation until valid input is given
    while (choice != '1' && choice != '2') {
        printf("Invalid choice! Please enter '1' or '2'.\n\n");
        scanf(" %c", &choice);
        choice = tolower(choice);
    }

    // Return the chosen room
    if (choice == '1') {
        printf("\nYou enter the first door.\n\n");
        return 2;
    } else {
        printf("\nYou enter the second door.\n\n");
        return 3;
    }
}

/* represents the story and choices in the second room */
int roomTwo() {
    printf("You find yourself in a room with a treasure chest.\n");
    printf("Do you want to open the chest?\n");
    printf("Enter 'y' for yes or 'n' for no.\n\n");

    char choice;
    scanf(" %c", &choice);
    choice = tolower(choice);

    // Loop through input validation until valid input is given
    while (choice != 'y' && choice != 'n') {
        printf("Invalid choice! Please enter 'y' or 'n'.\n\n");
        scanf(" %c", &choice);
        choice = tolower(choice);
    }

    if (choice == 'y') {
        printf("\nYou open the chest and find a key!\n\n");
    } else {
        printf("\nYou decide not to open the chest.\n\n");
    }

    printf("Where do you want to go now?\n");
    printf("Enter '1' to go back to the first room.\n");
    printf("Enter '2' to exit the game.\n\n");

    scanf(" %c", &choice);
    choice = tolower(choice);

    // Loop through input validation until valid input is given
    while (choice != '1' && choice != '2') {
        printf("Invalid choice! Please enter '1' or '2'.\n\n");
        scanf(" %c", &choice);
        choice = tolower(choice);
    }

    // Return the chosen room
    if (choice == '1') {
        printf("\nYou go back to the first room.\n\n");
        return 1;
    } else {
        return 3;
    }
}

/* prints the end of the game message */
void endGame() {
    printf("Congrats on finishing the game!\n");
    printf("Thanks for playing!\n");
}