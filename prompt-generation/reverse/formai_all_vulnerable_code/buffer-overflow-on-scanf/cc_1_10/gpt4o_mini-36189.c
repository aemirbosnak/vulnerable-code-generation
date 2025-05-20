//GPT-4o-mini DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Board structure
char board[BOARD_SIZE][BOARD_SIZE];

// Function declarations
void initializeBoard();
void displayBoard();
int makeMove(int sr, int sc, int dr, int dc, char player);
int isValidMove(int sr, int sc, int dr, int dc, char player);
void switchPlayer(char *player);
int isKing(int row, char player);
void playGame();

int main() {
    playGame();
    return 0;
}

void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 != 0) {
                if (i < 3) {
                    board[i][j] = 'B'; // Black pieces
                } else if (i > 4) {
                    board[i][j] = 'R'; // Red pieces
                } else {
                    board[i][j] = '.'; // Empty
                }
            } else {
                board[i][j] = '.'; // Empty squares
            }
        }
    }
}

void displayBoard() {
    printf("  a b c d e f g h\n");
    printf(" +-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("+-----------------\n\n");
}

int makeMove(int sr, int sc, int dr, int dc, char player) {
    if (isValidMove(sr, sc, dr, dc, player)) {
        board[dr][dc] = player;
        board[sr][sc] = '.';
        if (dr == 0 && player == 'R') {
            board[dr][dc] = 'K'; // King promotion for Red
        } else if (dr == BOARD_SIZE - 1 && player == 'B') {
            board[dr][dc] = 'K'; // King promotion for Black
        }
        return 1;
    }
    return 0;
}

int isValidMove(int sr, int sc, int dr, int dc, char player) {
    // Check if moving out of bounds
    if (dr < 0 || dr >= BOARD_SIZE || dc < 0 || dc >= BOARD_SIZE) return 0;
    // Check for valid diagonal movement based on player type
    int direction = (player == 'R') ? 1 : -1;
    int step = (player == 'R' && sr < dr && isKing(dr, player)) || 
               (player == 'B' && sr > dr && isKing(dr, player)) ? 1 : 0;

    if (step || abs(sr - dr) == 1) {
        return (board[dr][dc] == '.' && board[(sr + dr) / 2][(sc + dc) / 2] != player && board[(sr + dr) / 2][(sc + dc) / 2] != '.') ?
                (abs(sr - dr) == 2 && abs(sc - dc) == 2) : (abs(sr - dr) == 1 && abs(sc - dc) == 1);
    }
    return 0;
}

int isKing(int row, char player) {
    return (player == 'K') ? 1 : 0;
}

void playGame() {
    char player = 'R';
    int sr, sc, dr, dc;
    initializeBoard();
    displayBoard();

    while (1) {
        printf("Player %c's turn. Enter move (e.g., 'a3 b4'): ", player);
        char source[3], dest[3];
        scanf("%s %s", source, dest);
        sr = source[1] - '1';
        sc = source[0] - 'a';
        dr = dest[1] - '1';
        dc = dest[0] - 'a';

        if (makeMove(sr, sc, dr, dc, player)) {
            displayBoard();
            switchPlayer(&player);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

void switchPlayer(char *player) {
    *player = (*player == 'R') ? 'B' : 'R';
}