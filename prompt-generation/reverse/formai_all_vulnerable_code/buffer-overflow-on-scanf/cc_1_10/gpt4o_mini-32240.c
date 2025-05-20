//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_INPUT_LENGTH 256
#define MAX_TURNS 5

typedef struct {
    char name[30];
    int score;
} Player;

int is_valid_syntax(const char *input) {
    // Simple rules for valid C syntax (just for demonstration purposes)
    // In a real scenario, this could include checks for variable declarations, 
    // function definitions, etc.
    return strchr(input, ';') != NULL;
}

void print_scores(Player players[], int num_players) {
    printf("\nFinal Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    char input[MAX_INPUT_LENGTH];
    int num_players;

    printf("Welcome to the C Syntax Parsing Game!\n");
    
    // Set up players
    printf("Enter number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar();  // Consume newline character

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting game.\n");
        return 1;
    }

    // Get player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for player %d: ", i + 1);
        fgets(players[i].name, sizeof(players[i].name), stdin);
        players[i].name[strcspn(players[i].name, "\n")] = 0;  // Remove newline
        players[i].score = 0;  // Initialize score to 0
    }

    // Game turns
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        printf("\n--- Turn %d ---\n", turn + 1);
        for (int i = 0; i < num_players; i++) {
            printf("%s, enter a C syntax command: ", players[i].name);
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;  // Remove newline
            
            if (is_valid_syntax(input)) {
                printf("Valid syntax! Well done.\n");
                players[i].score++;
            } else {
                printf("Invalid syntax. Try again!\n");
            }
        }
    }

    // Print final scores
    print_scores(players, num_players);

    return 0;
}