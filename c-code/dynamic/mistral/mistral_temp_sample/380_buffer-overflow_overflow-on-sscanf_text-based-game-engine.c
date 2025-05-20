#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Game title
const char GAME_TITLE[] = "Secret of the Golden Chalice";

// Player's name
char player_name[26];

// Function to print game menu
void print_menu() {
    printf("Welcome to the game, %s!\n", player_name);
    printf("1. Start Game\n");
    printf("2. Load Game\n");
    printf("3. Quit Game\n");
}

// Function to read player's choice from the menu
void read_player_choice(int* choice) {
    int input;
    scanf("%d", &input);
    *choice = input;
}

int main() {
    // Clear the player_name buffer
    memset(player_name, 0, sizeof(player_name));

    // Ask for player's name (deliberate buffer overflow on sscanf)
    printf("Enter your name (up to 25 characters): ");
    // Scan the input into player_name array with maximum 25 characters (vulnerable to overflow)
    scanf("%s", player_name);

    int choice;
    print_menu();
    read_player_choice(&choice);

    // Simulate the game starting process (ignore the overflow for simplicity)
    if (choice == 1) {
        printf("Starting the game...\n");
    } else if (choice == 2) {
        printf("Loading the game...\n");
    } else if (choice == 3) {
        printf("Quitting the game...\n");
    }

    return 0;
}
