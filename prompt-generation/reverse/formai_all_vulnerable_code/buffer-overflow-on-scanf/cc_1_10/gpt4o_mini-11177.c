//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_PLAYERS 4
#define EMPTY '-'
#define PLAYER_SYMBOL 'P'
#define ALIEN_SYMBOL 'A'
#define TREASURE_SYMBOL 'T'

typedef struct {
    int x;
    int y;
    int score;
} Player;

typedef struct {
    int x;
    int y;
} Alien;

typedef struct {
    int x;
    int y;
} Treasure;

char board[SIZE][SIZE];
Player players[MAX_PLAYERS];
Alien alien;
Treasure treasure;
int currentTurn = 0;
int numPlayers = 0;

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void placeAlien() {
    do {
        alien.x = rand() % SIZE;
        alien.y = rand() % SIZE;
    } while (board[alien.x][alien.y] != EMPTY);

    board[alien.x][alien.y] = ALIEN_SYMBOL;
}

void placeTreasure() {
    do {
        treasure.x = rand() % SIZE;
        treasure.y = rand() % SIZE;
    } while (board[treasure.x][treasure.y] != EMPTY);

    board[treasure.x][treasure.y] = TREASURE_SYMBOL;
}

void addPlayer(int player) {
    players[player].x = rand() % SIZE;
    players[player].y = rand() % SIZE;
    players[player].score = 0;

    while (board[players[player].x][players[player].y] != EMPTY) {
        players[player].x = rand() % SIZE;
        players[player].y = rand() % SIZE;
    }
    board[players[player].x][players[player].y] = PLAYER_SYMBOL;
}

void drawBoard() {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int player, int newX, int newY) {
    if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
        // Check if the new position is an alien or treasure
        if (newX == alien.x && newY == alien.y) {
            printf("Player %d encountered the alien! Game Over!\n", player + 1);
            exit(0);
        }

        if (newX == treasure.x && newY == treasure.y) {
            players[player].score += 10;
            printf("Player %d found the treasure! Score: %d\n", player + 1, players[player].score);
            placeTreasure(); // Place new treasure
        }

        // Update position
        board[players[player].x][players[player].y] = EMPTY; // Clear old position
        players[player].x = newX;
        players[player].y = newY;
        board[newX][newY] = PLAYER_SYMBOL; // Mark new position
    } else {
        printf("Invalid move! Player %d stays in the same position.\n", player + 1);
    }
}

void playerTurn() {
    currentTurn %= numPlayers;
    printf("Player %d, enter your move (up: w, down: s, left: a, right: d): ", currentTurn + 1);
    char move;
    scanf(" %c", &move);

    int newX = players[currentTurn].x;
    int newY = players[currentTurn].y;

    switch (move) {
        case 'w':
            newX--; // Move up
            break;
        case 's':
            newX++; // Move down
            break;
        case 'a':
            newY--; // Move left
            break;
        case 'd':
            newY++; // Move right
            break;
        default:
            printf("Invalid move command!\n");
            return;
    }
    movePlayer(currentTurn, newX, newY);
    currentTurn++;
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Galactic Treasure Hunt!\n");
    printf("Enter the number of players (1 to 4): ");
    scanf("%d", &numPlayers);

    if (numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting...\n");
        return 1;
    }

    initializeBoard();
    placeAlien();
    placeTreasure();

    for (int i = 0; i < numPlayers; i++) {
        addPlayer(i);
    }

    while (1) {
        drawBoard();
        playerTurn();
    }

    return 0;
}