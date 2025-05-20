//FormAI DATASET v1.0 Category: Chess engine ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

// Structure to hold move information
typedef struct Move {
    int x_start;
    int y_start;
    int x_dest;
    int y_dest;
} Move;

// Function to initialize the chess board
char ** initBoard() {
    char ** board = (char **)malloc(sizeof(char *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (char *)malloc(sizeof(char) * BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    // Place the pieces in initial positions
    board[0][0] = board[0][7] = 'R';
    board[0][1] = board[0][6] = 'N';
    board[0][2] = board[0][5] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
    }
    board[7][0] = board[7][7] = 'r';
    board[7][1] = board[7][6] = 'n';
    board[7][2] = board[7][5] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = 'p';
    }
    return board;
}

// Function to print the current state of the chess board
void printBoard(char ** board) {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

// Function that checks if the move is valid
int isValidMove(int x_start, int y_start, int x_dest, int y_dest, char ** board) {
    // Check if the move is within the bounds of the board
    if (x_start < 0 || x_start >= BOARD_SIZE || y_start < 0 || y_start >= BOARD_SIZE ||
        x_dest < 0 || x_dest >= BOARD_SIZE || y_dest < 0 || y_dest >= BOARD_SIZE) {
        return 0;
    }
    // Check if the start and dest positions are not the same
    if (x_start == x_dest && y_start == y_dest) {
        return 0;
    }
    // Check if the piece at the start position is not empty
    if (board[x_start][y_start] == '-') {
        return 0;
    }
    // Check if the dest position has a friendly piece
    if (board[x_dest][y_dest] != '-' && board[x_start][y_start] == board[x_dest][y_dest]) {
        return 0;
    }
    // Check if the move is valid for the type of piece
    char piece = board[x_start][y_start];
    int dx = x_dest - x_start;
    int dy = y_dest - y_start;
    // Pawn moves
    if (piece == 'P' || piece == 'p') {
        if (piece == 'P') { // White Pawn moves
            if (dx == -1 && abs(dy) == 1 && board[x_dest][y_dest] != '-') { // Capturing move
                return 1;
            } else if (dx == -1 && dy == 0 && board[x_dest][y_dest] == '-') { // One step forward
                return 1;
            } else if (dx == -2 && dy == 0 && x_start == 6 && board[x_dest][y_dest] == '-') { // Two steps forward on first move
                return 1;
            }
        } else { // Black Pawn moves
            if (dx == 1 && abs(dy) == 1 && board[x_dest][y_dest] != '-') { // Capturing move
                return 1;
            } else if (dx == 1 && dy == 0 && board[x_dest][y_dest] == '-') { // One step forward
                return 1;
            } else if (dx == 2 && dy == 0 && x_start == 1 && board[x_dest][y_dest] == '-') { // Two steps forward on first move
                return 1;
            }
        }
    }
    // Knight moves
    if (piece == 'N' || piece == 'n') {
        if (abs(dx) == 1 && abs(dy) == 2) {
            return 1;
        }
        if (abs(dx) == 2 && abs(dy) == 1) {
            return 1;
        }
    }
    // Bishop moves
    if (piece == 'B' || piece == 'b') {
        if (abs(dx) != abs(dy)) {
            return 0;
        }
        int sgn_x = dx > 0 ? 1 : -1;
        int sgn_y = dy > 0 ? 1 : -1;
        int i = x_start + sgn_x, j = y_start + sgn_y;
        while (i != x_dest && j != y_dest) {
            if (board[i][j] != '-') {
                return 0;
            }
            i += sgn_x;
            j += sgn_y;
        }
    }
    // Rook moves
    if (piece == 'R' || piece == 'r') {
        if (dx != 0 && dy != 0) {
            return 0;
        }
        int sgn_x = dx > 0 ? 1 : dx < 0 ? -1 : 0;
        int sgn_y = dy > 0 ? 1 : dy < 0 ? -1 : 0;
        int i = x_start + sgn_x, j = y_start + sgn_y;
        while (i != x_dest || j != y_dest) {
            if (board[i][j] != '-') {
                return 0;
            }
            i += sgn_x;
            j += sgn_y;
        }
    }
    // Queen moves
    if (piece == 'Q' || piece == 'q') {
        if (abs(dx) != abs(dy) && dx != 0 && dy != 0) {
            return 0;
        }
        if (dx == 0 || dy == 0) { // Rook moves
            int sgn_x = dx > 0 ? 1 : dx < 0 ? -1 : 0;
            int sgn_y = dy > 0 ? 1 : dy < 0 ? -1 : 0;
            int i = x_start + sgn_x, j = y_start + sgn_y;
            while (i != x_dest || j != y_dest) {
                if (board[i][j] != '-') {
                    return 0;
                }
                i += sgn_x;
                j += sgn_y;
            }
        } else { // Bishop moves
            int sgn_x = dx > 0 ? 1 : -1;
            int sgn_y = dy > 0 ? 1 : -1;
            int i = x_start + sgn_x, j = y_start + sgn_y;
            while (i != x_dest && j != y_dest) {
                if (board[i][j] != '-') {
                    return 0;
                }
                i += sgn_x;
                j += sgn_y;
            }
        }
    }
    // King moves
    if (piece == 'K' || piece == 'k') {
        if (abs(dx) > 1 || abs(dy) > 1) {
            return 0;
        }
    }
    // The move is valid
    return 1;
}

// Function to randomly generate a move
Move generateMove(char ** board) {
    Move m;
    m.x_start = rand() % BOARD_SIZE;
    m.y_start = rand() % BOARD_SIZE;
    m.x_dest = rand() % BOARD_SIZE;
    m.y_dest = rand() % BOARD_SIZE;
    while (!isValidMove(m.x_start, m.y_start, m.x_dest, m.y_dest, board)) {
        m.x_start = rand() % BOARD_SIZE;
        m.y_start = rand() % BOARD_SIZE;
        m.x_dest = rand() % BOARD_SIZE;
        m.y_dest = rand() % BOARD_SIZE;
    }
    return m;
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    // Initialize the chess board
    char ** board = initBoard();
    // Print the starting state of the board
    printf("Starting state of the board:\n");
    printBoard(board);
    // Play 10 random moves
    for (int i = 1; i <= 10; i++) {
        printf("\nMove %d:\n", i);
        // Generate a random move
        Move m = generateMove(board);
        // Make the move
        board[m.x_dest][m.y_dest] = board[m.x_start][m.y_start];
        board[m.x_start][m.y_start] = '-';
        // Print the new state of the board
        printBoard(board);
    }
    // Free the memory allocated for the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
    // Return success
    return 0;
}