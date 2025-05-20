//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 100 // Maximum number of players allowed

struct player {
    int id;
    char name[20];
    float temperature; // Temperature in Celsius
};

int num_players = 0; // Number of players currently connected
struct player players[MAX_PLAYERS]; // Array to store all player data

// Function to add a new player to the game
void add_player() {

    printf("Enter name of player: ");
    char name[20];
    scanf("%s", name);

    printf("Enter temperature in Celsius: ");
    float temperature;
    scanf("%f", &temperature);

    struct player new_player;
    new_player.id = num_players;
    strcpy(new_player.name, name);
    new_player.temperature = temperature;

    players[num_players] = new_player;
    num_players++;

    printf("New player added successfully!\n\n");

}

// Function to convert temperature from Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

// Function to display all players and their temperatures in Fahrenheit
void display_players() {

    printf("ID\tName\tTemperature (C)\tTemperature (F)\n");

    for (int i = 0; i < num_players; i++) {
        printf("%d\t%s\t%.2f\t\t%.2f\n", players[i].id, players[i].name, players[i].temperature, celsius_to_fahrenheit(players[i].temperature));
    }

    printf("\n");

}

// Main function to run the program
int main() {

    printf("Welcome to the temperature converter game!\n\n");

    // Continuously loop to prompt user for input
    while (1) {

        // Display menu options
        printf("Menu:\n");
        printf("1. Add new player\n");
        printf("2. Display all players and their temperatures in Fahrenheit\n");
        printf("3. Exit game\n\n");

        // Prompt user for input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user input
        switch (choice) {
            case 1:
                add_player();
                break;
            case 2:
                display_players();
                break;
            case 3:
                printf("Thanks for playing! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    }

    return 0;
}