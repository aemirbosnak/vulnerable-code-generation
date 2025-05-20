//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <ctype.h>
#define MAX_NAME_LENGTH 20
#define MAX_NUM_OF_PLAYERS 4

// Function to sanitize user input strings
void sanitize_input(char* input) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = toupper(input[i]);
        }
        else if (input[i] == ' ' || input[i] == '-') {
            input[i] = '_';
        }
        else if (input[i] < '0' || input[i] > '9') {
            input[i] = 'X';
        }
        i++;
    }
}

int main() {
    char player_names[MAX_NUM_OF_PLAYERS][MAX_NAME_LENGTH];
    int num_of_players = 0;
    
    // Get the number of players from the user
    printf("Enter the number of players (1-4): ");
    scanf("%d", &num_of_players);
    
    // Validate the number of players
    while (num_of_players < 1 || num_of_players > 4) {
        printf("Invalid number of players. Enter again (1-4): ");
        scanf("%d", &num_of_players);
    }
    
    // Get the player names from the user and sanitize them
    for (int i = 0; i < num_of_players; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", player_names[i]);
        sanitize_input(player_names[i]);
    }
    
    // Display the sanitized player names
    printf("\nSanitized player names:\n");
    for (int i = 0; i < num_of_players; i++) {
        printf("%d. %s\n", i+1, player_names[i]);
    }

    return 0;
}