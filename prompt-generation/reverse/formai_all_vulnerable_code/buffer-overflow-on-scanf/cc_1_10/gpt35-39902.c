//FormAI DATASET v1.0 Category: Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define NUMBER_OF_PLAYERS 2

struct Player {
    int id;
    int x;
    int y;
    char symbol;
};

// Function prototypes
void initBoard(char board[][BOARD_SIZE]);
void displayBoard(char board[][BOARD_SIZE]);
void movePlayer(struct Player *player, char board[][BOARD_SIZE], int dx, int dy);

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    struct Player players[NUMBER_OF_PLAYERS];
    int i, j, numberOfMoves = 0;
    srand((unsigned) time(0)); // Seed random number generator

    // Initialize the board
    initBoard(board);

    // Initialize players
    for (i = 0; i < NUMBER_OF_PLAYERS; i++) {
        players[i].id = i + 1;
        players[i].symbol = '0' + players[i].id;
        // Place player randomly on the board
        do {
            players[i].x = rand() % BOARD_SIZE;
            players[i].y = rand() % BOARD_SIZE;
        } while (board[players[i].x][players[i].y] != ' ');
        board[players[i].x][players[i].y] = players[i].symbol;
    }

    // Display initial board
    displayBoard(board);

    // Game loop
    while (1) {
        for (i = 0; i < NUMBER_OF_PLAYERS; i++) {
            int dx = 0, dy = 0;
            char move = ' ';
            printf("Player %d's turn\n", players[i].id);
            printf("Enter move (w = up, a = left, s = down, d = right): ");
            scanf(" %c", &move);

            // Calculate new position based on move
            switch (move) {
                case 'w':
                    dy = -1;
                    break;
                case 'a':
                    dx = -1;
                    break;
                case 's':
                    dy = 1;
                    break;
                case 'd':
                    dx = 1;
                    break;
                default:
                    printf("Invalid move\n");
                    break;
            }

            // Move player if move is valid
            if (dx != 0 || dy != 0) {
                movePlayer(&players[i], board, dx, dy);
                numberOfMoves++;
            }

            // Display board after move
            displayBoard(board);

            // Check if game is over
            for (j = 0; j < NUMBER_OF_PLAYERS; j++) {
                if (i != j && players[i].x == players[j].x && players[i].y == players[j].y) {
                    printf("Player %d collided with player %d and lost!\n", players[i].id, players[j].id);
                    printf("Number of moves: %d\n", numberOfMoves);
                    return 0;
                }
            }
        }
    }
}

void initBoard(char board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[][BOARD_SIZE]) {
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void movePlayer(struct Player *player, char board[][BOARD_SIZE], int dx, int dy) {
    int newx = player->x + dx;
    int newy = player->y + dy;
    if (newx < 0 || newx >= BOARD_SIZE || newy < 0 || newy >= BOARD_SIZE) {
        printf("Cannot move outside board!\n");
        return;
    }
    if (board[newx][newy] != ' ') {
        printf("Cannot move on occupied space!\n");
        return;
    }
    board[player->x][player->y] = ' ';
    player->x = newx;
    player->y = newy;
    board[player->x][player->y] = player->symbol;
}