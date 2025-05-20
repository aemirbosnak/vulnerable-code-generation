//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int score = 0; // Initializing score variable

// Function prototypes
void startGame();
void intro();
void firstRoom();
void secondRoom();
void thirdRoom();
void fourthRoom();

int main() {
    startGame();
    return 0;
}

// Function to start the game
void startGame() {
    char choice;
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    intro(); // Call the intro function
    printf("Do you want to play the game? (Y/N) ");
    scanf(" %c", &choice);

    if (toupper(choice) == 'Y') {
        firstRoom(); // Call the first room function
    } else {
        printf("Thanks for playing!\n");
        exit(0);
    }
}

// Function for Introduction and backstory
void intro() {
    printf("You are a scientist who has just discovered a new planet.\n");
    printf("Your goal is to explore the planet and collect samples.\n");
    printf("But be careful, the planet is filled with dangerous creatures.\n");
}

// Function for the first room
void firstRoom() {
    printf("\nYou are now inside a dark room with no windows or doors.\n");
    printf("There's a table in front of you with a lantern and a note on it.\n");
    printf("What do you want to do?\n\n");
    printf("1. Read the note.\n");
    printf("2. Take the lantern.\n");
    printf("3. Ignore the table and search for an exit.\n\n");

    int choice;
    scanf("%d", &choice); // Get user input
    
    switch (choice) {
        case 1:
            printf("\nThe note says: 'Use the lantern to find a way out.'\n");
            firstRoom(); // Call the first room function again
            break;
        case 2:
            printf("\nYou take the lantern.\n");
            score += 10; // Increment the score
            secondRoom(); // Call the second room function
            break;
        case 3:
            printf("\nYou can't find anything, so you turn back to the table.\n");
            firstRoom(); // Call the first room function again
            break;
        default:
            printf("\nInvalid choice, please enter again.\n");
            firstRoom(); // Call the first room function again
            break;
    }
}

// Function for the second room
void secondRoom() {
    printf("\nYou are now in a room with 3 doors.\n");
    printf("Each door is labeled with a number: 1, 2 or 3.\n");
    printf("Which door do you want to go through?\n\n");
    printf("1. Door 1\n");
    printf("2. Door 2\n");
    printf("3. Door 3\n\n");

    int choice;
    scanf("%d", &choice); // Get user input

    switch (choice) {
        case 1:
            printf("\nYou open the door and enter a dark hallway.\n");
            thirdRoom(); // Call the third room function
            break;
        case 2:
            printf("\nYou open the door and find a room filled with treasure!\n");
            printf("Unfortunately, it's guarded by a dragon and it immediately attacks you.\n");
            printf("You die.\n");
            printf("Your final score is: %d\n", score);
            exit(0); // Exit the program
        case 3:
            printf("\nYou open the door and enter a room with a big mirror.\n");
            printf("As you look into the mirror, you see your reflection and nothing else.\n");
            secondRoom(); // Call the second room function again
            break;
        default:
            printf("Invalid choice, please enter again.\n");
            secondRoom(); // Call the second room function again
            break;
    }
}

// Function for the third room
void thirdRoom() {
    printf("\nYou are now in the dark hallway, but you see a dim light in the distance.\n");
    printf("What do you want to do?\n\n");
    printf("1. Walk towards the light.\n");
    printf("2. Turn back and go to the second room.\n\n");

    int choice;
    scanf("%d", &choice); // Get user input

    switch (choice) {
        case 1:
            printf("\nAs you walk towards the light, you hear a growling sound and suddenly a monster attacks you.\n");
            printf("You fight with all your might, but you are no match for the monster.\n");
            printf("You die.\n");
            printf("Your final score is: %d\n", score);
            exit(0); // Exit the program
        case 2:
            secondRoom(); // Call the second room function again
            break;
        default:
            printf("Invalid choice, please enter again.\n");
            thirdRoom(); // Call the third room function again
            break;
    }
}

// Function for the fourth room
void fourthRoom() {
    printf("\nYou are now in a room with a strange machine in the center.\n");
    printf("The machine has a note attached to it.\n");
    printf("What do you want to do?\n\n");
    printf("1. Read the note.\n");
    printf("2. Investigate the machine.\n");
    printf("3. Leave the room.\n\n");

    int choice;
    scanf("%d", &choice); // Get user input

    switch (choice) {
        case 1:
            printf("\nThe note says: 'Use the machine to transport to the laboratory.'\n");
            score += 50; // Increment the score
            printf("Your score is now: %d\n", score);
            fourthRoom(); // Call the fourth room function again
            break;
        case 2:
            printf("\nAs you investigate the machine, you accidentally trigger it.\n");
            printf("You are transported to a different dimension and never seen again.\n");
            printf("Your final score is: %d\n", score);
            exit(0); // Exit the program
        case 3:
            printf("\nYou leave the room and find yourself back in the second room.\n");
            secondRoom(); // Call the second room function again
            break;
        default:
            printf("\nInvalid choice, please enter again.\n");
            fourthRoom(); // Call the fourth room function again
            break;
    }
}