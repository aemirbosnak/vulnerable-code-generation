//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 20
#define MAX_MESSAGE_LEN 50

// Structure to hold player information
typedef struct {
    char name[MAX_NAME_LEN];
    int player_id;
    int fortune;
} Player;

// Array to hold all player information
Player players[MAX_PLAYERS];

// Function to display the fortune
void display_fortune(int fortune) {
    switch(fortune) {
        case 0: printf("Hmm, I can't seem to predict your fortune today. Try again later.\n"); break;
        case 1: printf("Your future is looking bright.\n"); break;
        case 2: printf("You will encounter a great opportunity soon.\n"); break;
        case 3: printf("Beware of someone close to you, they may not have your best interests at heart.\n"); break;
        case 4: printf("You will have great success in your career or education.\n"); break;
        case 5: printf("Travel is in your future.\n"); break;
        case 6: printf("You will find love in unexpected places.\n"); break;
        case 7: printf("Your hard work will pay off soon.\n"); break;
        case 8: printf("You will receive unexpected good news.\n"); break;
        case 9: printf("Be prepared for a major life change.\n"); break;
    }
}

int main() {

    int num_players, i, j, id, fortune;
    char message[MAX_MESSAGE_LEN];

    srand(time(NULL)); // seed random number generator

    // Get the number of players
    printf("Welcome to the automated fortune teller! How many players will there be? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    // Validate input
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("That is not a valid number of players. Please try again.\n");
        return 1;
    }

    // Get player names and IDs
    for (i = 0; i < num_players; i++) {
        printf("Enter name for player %d (max %d characters): ", i+1, MAX_NAME_LEN-1);
        scanf("%s", players[i].name);
        players[i].player_id = i+1;
    }

    // Tell fortunes for each player
    for (i = 0; i < num_players; i++) {
        fortune = rand() % 10;
        players[i].fortune = fortune;
        sprintf(message, "Player %d: Your fortune is...", players[i].player_id);
        printf("%s\n", message);
        display_fortune(fortune);
    }

    // Announce winner
    int max_fortune = -1;
    for (i = 0; i < num_players; i++) {
        if (players[i].fortune > max_fortune) {
            max_fortune = players[i].fortune;
            id = players[i].player_id;
        }
    }
    printf("Congratulations to player %d for having the highest fortune!\n", id);

    // Allow players to play again
    char play_again;
    printf("Would you like to play again? (y/n): ");
    scanf(" %c", &play_again);
    if (play_again != 'y') {
        printf("Thank you for playing!\n");
        return 0;
    }

    // Reset player fortunes
    for (i = 0; i < num_players; i++) {
        players[i].fortune = -1;
    }

    while (1) {
        // Get player names and IDs
        for (i = 0; i < num_players; i++) {
            printf("Enter name for player %d (max %d characters): ", i+1, MAX_NAME_LEN-1);
            scanf("%s", players[i].name);
            players[i].player_id = i+1;
        }

        // Tell fortunes for each player
        for (i = 0; i < num_players; i++) {
            fortune = rand() % 10;
            players[i].fortune = fortune;
            sprintf(message, "Player %d: Your fortune is...", players[i].player_id);
            printf("%s\n", message);
            display_fortune(fortune);
        }

        // Announce winner
        max_fortune = -1;
        for (i = 0; i < num_players; i++) {
            if (players[i].fortune > max_fortune) {
                max_fortune = players[i].fortune;
                id = players[i].player_id;
            }
        }
        printf("Congratulations to player %d for having the highest fortune!\n", id);

        // Ask if players want to play again
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);
        if (play_again != 'y') {
            printf("Thank you for playing!\n");
            return 0;
        }

        // Reset player fortunes
        for (i = 0; i < num_players; i++) {
            players[i].fortune = -1;
        }

    }

}