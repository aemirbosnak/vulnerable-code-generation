//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_PLAYERS 4

typedef struct {
    int id;
    char name[20];
    int position;
} Player;

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void display_board(char board[BOARD_SIZE][BOARD_SIZE], Player players[], int num_players);
void move_player(Player *player, int steps);
void roll_dice(int *dice1, int *dice2);
int check_winner(Player players[], int num_players);
void play_turn(Player *player, char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    Player players[MAX_PLAYERS];
    int num_players, i, winner;

    // Initialize the random number generator
    srand(time(NULL));

    // Input the number of players
    printf("Enter number of players (2-4): ");
    scanf("%d", &num_players);
    
    // Input player names
    for (i = 0; i < num_players; i++) {
        players[i].id = i + 1;
        printf("Enter name for Player %d: ", players[i].id);
        scanf("%s", players[i].name);
        players[i].position = 0;
    }

    // Initialize board
    initialize_board(board);

    // Game loop
    while ((winner = check_winner(players, num_players)) == -1) {
        display_board(board, players, num_players);
        
        for (i = 0; i < num_players; i++) {
            play_turn(&players[i], board);
        }
    }

    // Announce the winner
    printf("Congratulations, %s wins the game!\n", players[winner].name);
    return 0;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void display_board(char board[BOARD_SIZE][BOARD_SIZE], Player players[], int num_players) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            char found = '.';
            for (int k = 0; k < num_players; k++) {
                if (players[k].position == (i * BOARD_SIZE + j)) {
                    found = 'P'+ players[k].id;  // Display player ID
                }
            }
            printf("%c ", found);
        }
        printf("\n");
    }
}

void move_player(Player *player, int steps) {
    player->position += steps;
    if (player->position >= BOARD_SIZE * BOARD_SIZE) {
        player->position = BOARD_SIZE * BOARD_SIZE - 1; // Cap to the last cell
    }
}

void roll_dice(int *dice1, int *dice2) {
    *dice1 = rand() % 6 + 1;
    *dice2 = rand() % 6 + 1;
}

int check_winner(Player players[], int num_players) {
    for (int i = 0; i < num_players; i++) {
        if (players[i].position == (BOARD_SIZE * BOARD_SIZE - 1)) {
            return i; // Return winning player's index
        }
    }
    return -1; // No winner yet
}

void play_turn(Player *player, char board[BOARD_SIZE][BOARD_SIZE]) {
    int dice1, dice2;
    printf("%s's turn:\n", player->name);
    
    roll_dice(&dice1, &dice2);
    printf("Rolled: %d and %d\n", dice1, dice2);
    
    int total_steps = dice1 + dice2;
    move_player(player, total_steps);
    
    printf("%s moved to position %d\n", player->name, player->position);
}