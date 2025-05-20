//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 20
#define BOARD_SIZE 10
#define WINNING_SCORE 50

typedef struct {
    char name[20];
    int position;
    int score;
} Player;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} GameBoard;

void initializeBoard(GameBoard *gameBoard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            gameBoard->board[i][j] = '-';
        }
    }
    gameBoard->board[0][0] = 'S'; // Starting point
    gameBoard->board[BOARD_SIZE - 1][BOARD_SIZE - 1] = 'E'; // Ending point
}

void printBoard(GameBoard *gameBoard, Player players[], int playerCount) {
    printf("\nGame Board:\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int foundPlayer = 0;
            for (int k = 0; k < playerCount; k++) {
                if (players[k].position == i * BOARD_SIZE + j) {
                    printf("%c ", 'A' + k); // Print player ID
                    foundPlayer = 1;
                    break;
                }
            }
            if (!foundPlayer) {
                printf("%c ", gameBoard->board[i][j]);
            }
        }
        printf("\n");
    }
}

void initializePlayers(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].position = 0;
        players[i].score = 0;
    }
}

int rollDice() {
    return (rand() % 6) + 1; // Roll a number between 1 and 6
}

void updatePosition(Player *player, int diceRoll) {
    player->position += diceRoll;
    if (player->position >= BOARD_SIZE * BOARD_SIZE) {
        player->position = BOARD_SIZE * BOARD_SIZE - 1; // Keep within bounds
    }
    player->score += diceRoll; // Update score as per dice roll
}

void playTurn(Player *player) {
    printf("%s's turn:\n", player->name);
    int diceRoll = rollDice();
    printf("%s rolled a %d!\n", player->name, diceRoll);
    updatePosition(player, diceRoll);
}

int checkWin(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        if (players[i].score >= WINNING_SCORE) {
            printf("%s wins with a score of %d!\n", players[i].name, players[i].score);
            return 1; // Player has won
        }
    }
    return 0; // No winner yet
}

int main() {
    srand(time(NULL));
    
    Player players[MAX_PLAYERS];
    int playerCount;
    
    printf("Enter the number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &playerCount);
    
    if (playerCount < 2 || playerCount > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    GameBoard gameBoard;
    initializeBoard(&gameBoard);
    initializePlayers(players, playerCount);
    
    for (int turn = 0; turn < MAX_TURNS; turn++) {
        printBoard(&gameBoard, players, playerCount);
        
        for (int i = 0; i < playerCount; i++) {
            playTurn(&players[i]);
            if (checkWin(players, playerCount)) {
                return 0; // End game on win
            }
        }
    }
    
    printf("Game over! No one reached the winning score of %d.\n", WINNING_SCORE);
    return 0;
}