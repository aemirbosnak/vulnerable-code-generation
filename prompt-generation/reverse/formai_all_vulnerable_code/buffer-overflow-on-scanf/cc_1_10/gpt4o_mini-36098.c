//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 5
#define BUFFER_SIZE 256

void convertDate(const char *input) {
    struct tm tm;
    char output[BUFFER_SIZE];

    if (strptime(input, "%B %d, %Y", &tm) != NULL || 
        strptime(input, "%d %B %Y", &tm) != NULL ||
        strptime(input, "%Y-%m-%d", &tm) != NULL) {
        
        strftime(output, sizeof(output), "%Y-%m-%d", &tm);
        printf("Converted date: %s\n", output);
    } else {
        printf("Invalid date format: %s\n", input);
    }
}

void handlePlayerInput(int playerId) {
    char input[BUFFER_SIZE];

    printf("Player %d, enter a date (e.g., 'March 15, 2021', '15 March 2021', '2021-03-15'): ", playerId);
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    convertDate(input);
}

int main() {
    int numberOfPlayers;
    
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Enter the number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numberOfPlayers);
    getchar(); // Clear newline character from input buffer

    if (numberOfPlayers > MAX_PLAYERS || numberOfPlayers < 1) {
        printf("Invalid number of players! Please start again with a valid number between 1 and %d.\n", MAX_PLAYERS);
        return 1;
    }

    printf("\nStarting the date conversion game for %d players...\n", numberOfPlayers);

    for (int i = 1; i <= numberOfPlayers; i++) {
        handlePlayerInput(i);
        printf("\n");
    }

    printf("Thank you for playing the Natural Language Date Converter!\n");
    return 0;
}