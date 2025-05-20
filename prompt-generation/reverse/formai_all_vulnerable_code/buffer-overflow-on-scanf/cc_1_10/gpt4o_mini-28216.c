//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void display_instructions();
void start_game(int player_count);

int main() {
    int player_count;

    printf("Welcome to the Multiplayer Temperature Converter Game!\n");
    printf("Please enter the number of players (1-4): ");
    scanf("%d", &player_count);

    // Validate player count
    while (player_count < 1 || player_count > 4) {
        printf("Invalid number of players. Please enter a number between 1 and 4: ");
        scanf("%d", &player_count);
    }

    // Start the game with the given player count
    start_game(player_count);

    printf("Thanks for playing! Goodbye!\n");
    return 0;
}

// Function to display instructions
void display_instructions() {
    printf("\nInstructions:\n");
    printf("1. Each player will input a temperature to convert.\n");
    printf("2. Each player can choose to convert Celsius to Fahrenheit or vice versa.\n");
    printf("3. The player closest to a specified target temperature wins!\n");
    printf("4. Let’s see who can get the closest!\n");
}

// Function to start the game
void start_game(int player_count) {
    float temperature;
    char choice;
    float converted_temp;
    float target = 100.0; // Target temperature (can be modified)
    float closest_distance[player_count];
    char player_names[player_count][20];
    int i;

    display_instructions();

    // Get player names
    for (i = 0; i < player_count; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", player_names[i]);
        closest_distance[i] = 1000.0; // Initialize with a large value
    }

    // Main game loop
    for (i = 0; i < player_count; i++) {
        char play_again;

        do {
            printf("\n%s's turn.\n", player_names[i]);
            printf("Enter temperature: ");
            scanf("%f", &temperature);
            printf("Convert to (C)elsius or (F)ahrenheit? ");
            scanf(" %c", &choice);

            if (choice == 'C' || choice == 'c') {
                converted_temp = fahrenheit_to_celsius(temperature);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", temperature, converted_temp);
                // Calculate distance from target
                closest_distance[i] = fabs(target - converted_temp);
            } else if (choice == 'F' || choice == 'f') {
                converted_temp = celsius_to_fahrenheit(temperature);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", temperature, converted_temp);
                // Calculate distance from target
                closest_distance[i] = fabs(target - converted_temp);
            } else {
                printf("Invalid choice. Please choose C or F.\n");
                continue; // Skip to next player
            }

            printf("Do you want to play again %s? (Y/N): ", player_names[i]);
            scanf(" %c", &play_again);
        } while (play_again == 'Y' || play_again == 'y');
    }

    // Determine winner
    float min_distance = closest_distance[0];
    int winner_index = 0;

    for (i = 1; i < player_count; i++) {
        if (closest_distance[i] < min_distance) {
            min_distance = closest_distance[i];
            winner_index = i;
        }
    }

    printf("\nThe winner is %s with a distance of %.2f° from the target %.2f°!\n",
           player_names[winner_index], min_distance, target);
}

// Convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}