//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_LENGTH_NAME 20

// Define a struct to hold player data
typedef struct {
    char name[MAX_LENGTH_NAME];
    int age;
    float weight;
    float height;
    float bmi;
} Player;

// Global variables
Player players[MAX_PLAYERS];
int num_players = 0;

// Function prototypes
Player create_player();
void add_player(Player player);
float calculate_bmi(float weight, float height);
void display_players();
void display_player(Player player);
void sort_players_by_bmi_desc();

int main() {
    // Set up random number generator
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Fitness Tracker!\n\n");

    // Loop to get player information
    char cont;
    do {
        Player player = create_player();
        add_player(player);

        printf("\nWould you like to add another player? (y/n) ");
        scanf(" %c", &cont);
    } while (cont == 'y' && num_players < MAX_PLAYERS);

    // Display player information
    printf("\nHere are the players you entered:\n");
    display_players();

    // Sort players by BMI in descending order
    sort_players_by_bmi_desc();

    // Display player information (sorted by BMI)
    printf("\nHere are the players sorted by BMI in descending order:\n");
    display_players();

    return 0;
}

/**
 * Prompts the user to enter player information and creates a new player.
 *
 * @return The new player.
 */
Player create_player() {
    Player player;

    // Get player name
    printf("Please enter the player's name (up to %d characters): ", MAX_LENGTH_NAME);
    scanf("%s", player.name);

    // Get player age
    printf("Please enter the player's age: ");
    scanf("%d", &player.age);

    // Get player weight
    printf("Please enter the player's weight (in kg): ");
    scanf("%f", &player.weight);

    // Get player height
    printf("Please enter the player's height (in m): ");
    scanf("%f", &player.height);

    // Calculate player BMI
    player.bmi = calculate_bmi(player.weight, player.height);

    return player;
}

/**
 * Adds a player to the global array of players.
 *
 * @param player The player to add.
 */
void add_player(Player player) {
    if (num_players < MAX_PLAYERS) {
        players[num_players] = player;
        num_players++;
    } else {
        printf("\nMaximum number of players reached (%d).", MAX_PLAYERS);
    }
}

/**
 * Calculates the BMI for a given weight and height.
 *
 * @param weight The weight in kg.
 * @param height The height in m.
 * @return The BMI.
 */
float calculate_bmi(float weight, float height) {
    float bmi = weight / (height * height);
    return bmi;
}

/**
 * Displays all players in the global array of players.
 */
void display_players() {
    printf("\n");
    for (int i = 0; i < num_players; i++) {
        display_player(players[i]);
    }
}

/**
 * Displays the information for a single player.
 *
 * @param player The player to display.
 */
void display_player(Player player) {
    printf("%s (%d years old)\n", player.name, player.age);
    printf("  Weight: %.2f kg\n", player.weight);
    printf("  Height: %.2f m\n", player.height);
    printf("  BMI: %.2f\n", player.bmi);
}

/**
 * Sorts the global array of players by BMI in descending order using the bubble sort algorithm.
 */
void sort_players_by_bmi_desc() {
    for (int i = 0; i < num_players - 1; i++) {
        for (int j = 0; j < num_players - i - 1; j++) {
            if (players[j].bmi < players[j + 1].bmi) {
                Player temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
}