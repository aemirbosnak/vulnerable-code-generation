//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void printIntro();
void playGame();
int choosePath();
void path1();
void path2();
void path3();
int checkInput();
void gameOver();
void winGame();

// Global variable for player's choice
int choice;

// Starting point of the program
int main() {
    srand(time(NULL)); // Initialize random seed
    printIntro(); // Print introduction
    playGame(); // Start the game

    return 0;
}

// Function to print the game introduction
void printIntro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("Your goal is to find a way out of this place and discover the truth.\n\n");
}

// Function to start the game
void playGame() {
    printf("Which path do you choose?\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go straight\n");

    choice = checkInput(); // Get player's choice

    switch(choice) {
        case 1:
            path1(); // Go left
            break;
        case 2:
            path2(); // Go right
            break;
        case 3:
            path3(); // Go straight
            break;
        default:
            printf("Invalid choice.\n"); // Invalid input
            playGame(); // Restart the game
            break;
    }
}

// Function for path 1 (left)
void path1() {
    printf("\nPath 1:\n");
    printf("You encounter a giant spider.\n");
    printf("1. Attack the spider\n");
    printf("2. Run away\n");

    choice = checkInput(); // Get player's choice

    if(choice == 1) { // Attack the spider
        int attack = rand() % 2; // Randomly choose if attack hits or misses
        if(attack) {
            printf("You defeated the spider and continue down the path.\n");
            winGame();
        } else {
            printf("You missed and the spider attacked you.\n");
            gameOver();
        }
    } else if(choice == 2) { // Run away
        printf("You run away from the spider and continue down the path.\n");
        playGame();
    } else { // Invalid input
        printf("Invalid choice.\n");
        path1();
    }
}

// Function for path 2 (right)
void path2() {
    printf("\nPath 2:\n");
    printf("You find a locked door.\n");
    printf("1. Try to pick the lock\n");
    printf("2. Look for another way\n");

    choice = checkInput(); // Get player's choice

    if(choice == 1) { // Try to pick the lock
        printf("You successfully picked the lock and opened the door.\n");
        winGame();
    } else if(choice == 2) { // Look for another way
        printf("You continue down the path and find an alternative route.\n");
        playGame();
    } else { // Invalid input
        printf("Invalid choice.\n");
        path2();
    }
}

// Function for path 3 (straight)
void path3() {
    printf("\nPath 3:\n");
    printf("You come across a dark, murky swamp.\n");
    printf("1. Try to cross the swamp\n");
    printf("2. Look for a different path\n");

    choice = checkInput(); // Get player's choice

    if(choice == 1) { // Try to cross the swamp
        printf("You wade through the swamp, but it turns out to be poisonous.\n");
        gameOver();
    } else if(choice == 2) { // Look for a different path
        printf("You continue down the path and find a safer way around the swamp.\n");
        playGame();
    } else { // Invalid input
        printf("Invalid choice.\n");
        path3();
    }
}

// Function to check user input
int checkInput() {
    printf("Enter your choice: ");
    int input;
    scanf("%d", &input);
    while(getchar() != '\n'); // Clear input buffer
    return input;
}

// Function for game over
void gameOver() {
    printf("Game over.\n");
    printf("Do you want to play again?\n");
    printf("1. Yes\n");
    printf("2. No\n");

    choice = checkInput(); // Get player's choice

    if(choice == 1) { // Play again
        playGame();
    } else if(choice == 2) { // Quit game
        printf("Thanks for playing!\n");
        exit(0);
    } else { // Invalid input
        printf("Invalid choice.\n");
        gameOver();
    }
}

// Function for winning the game
void winGame() {
    printf("Congratulations, you escaped the room and uncovered the truth behind your kidnapping.\n");
    printf("Thanks for playing!\n");
    exit(0);
}