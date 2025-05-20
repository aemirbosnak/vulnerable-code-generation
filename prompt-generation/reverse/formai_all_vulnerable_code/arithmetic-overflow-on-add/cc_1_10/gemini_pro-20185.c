//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game board
char board[3][3];

// Define the player symbols
char player1 = 'X';
char player2 = 'O';

// Define the game state
enum GameState {
    PLAYING,
    PLAYER1_WIN,
    PLAYER2_WIN,
    TIE
};

// Initialize the game board
void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Draw the game board
void drawBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Get the player's move
int getMove(char player) {
    int row, col;
    printf("Player %c, enter your move (row, column): ", player);
    scanf("%d %d", &row, &col);
    return row * 3 + col;
}

// Make the player's move
void makeMove(int move, char player) {
    int row = move / 3;
    int col = move % 3;
    board[row][col] = player;
}

// Check if the game is over
enum GameState checkGameState() {
    // Check for rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
        }
    }

    // Check for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2] == player1 ? PLAYER1_WIN : PLAYER2_WIN;
    }

    // Check for tie
    int numEmptyCells = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                numEmptyCells++;
            }
        }
    }
    if (numEmptyCells == 0) {
        return TIE;
    }

    // Game is still playing
    return PLAYING;
}

// Play the game
void playGame() {
    initBoard();
    drawBoard();

    enum GameState state = PLAYING;
    while (state == PLAYING) {
        int move = getMove(player1);
        makeMove(move, player1);
        drawBoard();
        state = checkGameState();

        if (state == PLAYING) {
            move = getMove(player2);
            makeMove(move, player2);
            drawBoard();
            state = checkGameState();
        }
    }

    switch (state) {
        case PLAYER1_WIN:
            printf("Player 1 wins!");
            break;
        case PLAYER2_WIN:
            printf("Player 2 wins!");
            break;
        case TIE:
            printf("Tie!");
            break;
    }
}

int main() {
    srand(time(NULL));
    playGame();
    return 0;
}