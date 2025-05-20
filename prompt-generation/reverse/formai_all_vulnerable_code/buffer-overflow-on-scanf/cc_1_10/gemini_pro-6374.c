//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LEN 20

// Player struct
typedef struct {
    char name[MAX_NAME_LEN];
    int score;
    int x, y;
} Player;

// Game board struct
typedef struct {
    char grid[10][10];
    int width, height;
} GameBoard;

// Function to initialize the game board
void initGameBoard(GameBoard *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            board->grid[i][j] = '.';
        }
    }
}

// Function to print the game board
void printGameBoard(GameBoard *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            printf("%c", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to get a random position on the game board
void getRandomPosition(GameBoard *board, int *x, int *y) {
    *x = rand() % board->width;
    *y = rand() % board->height;
}

// Function to place a player on the game board
void placePlayer(GameBoard *board, Player *player) {
    int x, y;
    getRandomPosition(board, &x, &y);
    player->x = x;
    player->y = y;
    board->grid[y][x] = player->name[0];
}

// Function to move a player on the game board
void movePlayer(GameBoard *board, Player *player, int dx, int dy) {
    int newX = player->x + dx;
    int newY = player->y + dy;
    if (newX >= 0 && newX < board->width && newY >= 0 && newY < board->height) {
        board->grid[player->y][player->x] = '.';
        player->x = newX;
        player->y = newY;
        board->grid[player->y][player->x] = player->name[0];
    }
}

// Function to check if a player has won
int checkWin(GameBoard *board) {
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            if (board->grid[i][j] != '.') {
                // Check for horizontal win
                if (j + 4 < board->width && board->grid[i][j] == board->grid[i][j + 1] && board->grid[i][j] == board->grid[i][j + 2] && board->grid[i][j] == board->grid[i][j + 3] && board->grid[i][j] == board->grid[i][j + 4]) {
                    return 1;
                }
                // Check for vertical win
                if (i + 4 < board->height && board->grid[i][j] == board->grid[i + 1][j] && board->grid[i][j] == board->grid[i + 2][j] && board->grid[i][j] == board->grid[i + 3][j] && board->grid[i][j] == board->grid[i + 4][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to start a new game
void startNewGame(GameBoard *board, Player *players, int numPlayers) {
    initGameBoard(board);
    for (int i = 0; i < numPlayers; i++) {
        placePlayer(board, &players[i]);
    }
}

// Main game loop
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the game board
    GameBoard board;
    board.width = 10;
    board.height = 10;

    // Create the players
    Player players[MAX_PLAYERS];
    int numPlayers = 0;

    // Get the player names
    printf("Enter the names of the players: ");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        scanf("%s", players[i].name);
        numPlayers++;
    }

    // Start a new game
    startNewGame(&board, players, numPlayers);

    // Main game loop
    while (!checkWin(&board)) {
        // Get the player input
        for (int i = 0; i < numPlayers; i++) {
            char input;
            printf("%s's turn: ", players[i].name);
            scanf(" %c", &input);

            // Move the player
            switch (input) {
                case 'w':
                    movePlayer(&board, &players[i], 0, -1);
                    break;
                case 'a':
                    movePlayer(&board, &players[i], -1, 0);
                    break;
                case 's':
                    movePlayer(&board, &players[i], 0, 1);
                    break;
                case 'd':
                    movePlayer(&board, &players[i], 1, 0);
                    break;
            }
        }

        // Print the game board
        printGameBoard(&board);
    }

    // Print the winner
    for (int i = 0; i < numPlayers; i++) {
        if (checkWin(&board)) {
            printf("%s wins!\n", players[i].name);
        }
    }

    return 0;
}