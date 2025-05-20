//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGE_LEN 256

typedef struct {
    char name[32];
    int score;
    char message[MAX_MESSAGE_LEN];
} player_t;

void init_players(player_t players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].score = 0;
        strcpy(players[i].message, "");
    }
}

void print_players(player_t players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
        if (strlen(players[i].message) > 0) {
            printf("    Message: %s\n", players[i].message);
        }
    }
}

int main() {
    player_t players[MAX_PLAYERS];
    int num_players;

    printf("Enter the number of players (1-%d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    init_players(players, num_players);

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Play Game\n");
        printf("2. View Scores\n");
        printf("3. Send Message\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Play game
                printf("Not implemented yet.\n");
                break;
            case 2:
                // View scores
                print_players(players, num_players);
                break;
            case 3:
                // Send message
                printf("Enter the player number to send a message to (1-%d): ", num_players);
                int player_num;
                scanf("%d", &player_num);

                if (player_num < 1 || player_num > num_players) {
                    printf("Invalid player number.\n");
                } else {
                    printf("Enter your message: ");
                    char message[MAX_MESSAGE_LEN];
                    scanf(" %[^\n]s", message); // Read the entire line, including spaces

                    strcpy(players[player_num - 1].message, message);
                    printf("Message sent.\n");
                }
                break;
            case 4:
                // Quit
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}