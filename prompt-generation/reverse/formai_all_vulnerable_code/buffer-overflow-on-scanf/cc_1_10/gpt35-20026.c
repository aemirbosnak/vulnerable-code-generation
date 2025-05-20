//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

// Define function prototypes.
void intro();
void start_game();
void choice_1();
void choice_2();
void choice_3();
void win();
void lose();
void game_over();

// Declare global variables.
char player_name[MAX_NAME_LENGTH];
int health = 50;
int coins = 0;
int choice;

int main() {
    // Call intro function.
    intro();

    // Call start_game function.
    start_game();

    return 0;
}

void intro() {
    printf("Welcome to the Adventure Game!\n");

    // Get player name.
    printf("What's your name?\n");
    scanf("%s", player_name);

    // Display player name.
    printf("Hello, %s!\n", player_name);

    // Set initial player stats.
    printf("You have %d health and %d coins.\n", health, coins);
}

void start_game() {
    printf("You are standing in a dark forest.\n");
    printf("There are three paths ahead of you.\n");
    printf("Which do you choose? (1, 2, 3)\n");

    // Get player choice.
    scanf("%d", &choice);

    // Perform action based on player choice.
    switch(choice) {
        case 1: choice_1();
                break;
        case 2: choice_2();
                break;
        case 3: choice_3();
                break;
        default: printf("Invalid choice.\n");
                 start_game();
                 break;
    }
}

void choice_1() {
    printf("You chose path 1.\n");
    printf("You encounter a pack of wolves.\n");
    printf("What do you do? (1. Fight, 2. Run)\n");

    // Get player choice.
    scanf("%d", &choice);

    // Perform action based on player choice.
    switch(choice) {
        case 1: printf("You engage the wolves in battle.\n");
                printf("You defeat them and earn 10 coins.\n");
                coins += 10;
                printf("You have %d health and %d coins.\n", health, coins);
                win();
                break;
        case 2: printf("You run away from the wolves.\n");
                printf("You trip and lose 5 health.\n");
                health -= 5;
                printf("You have %d health and %d coins.\n", health, coins);
                if (health <= 0) {
                    lose();
                } else {
                    start_game();
                }
                break;
        default: printf("Invalid choice.\n");
                 choice_1();
                 break;
    }
}

void choice_2() {
    printf("You chose path 2.\n");
    printf("You find a treasure chest.\n");
    printf("What do you do? (1. Open, 2. Ignore)\n");

    // Get player choice.
    scanf("%d", &choice);

    // Perform action based on player choice.
    switch(choice) {
        case 1: printf("You open the treasure chest and find 20 coins.\n");
                coins += 20;
                printf("You have %d health and %d coins.\n", health, coins);
                win();
                break;
        case 2: printf("You ignore the treasure chest and continue on your way.\n");
                start_game();
                break;
        default: printf("Invalid choice.\n");
                 choice_2();
                 break;
    }
}

void choice_3() {
    printf("You chose path 3.\n");
    printf("You come across a river.\n");
    printf("What do you do? (1. Swim, 2. Build a raft)\n");

    // Get player choice.
    scanf("%d", &choice);

    // Perform action based on player choice.
    switch(choice) {
        case 1: printf("You swim across the river.\n");
                printf("You make it across safely.\n");
                printf("You have %d health and %d coins.\n", health, coins);
                win();
                break;
        case 2: printf("You build a raft and float across the river.\n");
                printf("You make it across safely.\n");
                printf("You have %d health and %d coins.\n", health, coins);
                win();
                break;
        default: printf("Invalid choice.\n");
                 choice_3();
                 break;
    }
}

void win() {
    printf("Congratulations, %s! You win!\n", player_name);
    printf("You finish the game with %d health and %d coins.\n", health, coins);
    exit(0);
}

void lose() {
    printf("Sorry, %s. You lose.\n", player_name);
    printf("You finish the game with %d health and %d coins.\n", health, coins);
    game_over();
}

void game_over() {
    printf("Would you like to play again? (1. Yes, 2. No)\n");

    // Get player choice.
    scanf("%d", &choice);

    // Perform action based on player choice.
    switch(choice) {
        case 1: printf("Let's play again!\n");
                // Reset player stats.
                health = 50;
                coins = 0;
                start_game();
                break;
        case 2: printf("Goodbye, %s! Thanks for playing!\n", player_name);
                exit(0);
                break;
        default: printf("Invalid choice.\n");
                 game_over();
                 break;
    }
}