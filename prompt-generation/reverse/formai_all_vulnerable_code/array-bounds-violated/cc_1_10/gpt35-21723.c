//FormAI DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define WHITE 'W'
#define BLACK 'B'

// Move structure to store move coordinates
typedef struct {
    int fromX;
    int fromY;
    int toX;
    int toY;
} Move;

// Chess piece structure to store piece type and color
typedef struct {
    char type;
    char color;
} Piece;

// Chess board array to store piece locations
Piece board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the chess board with starting positions
void initBoard() {
    // Black pieces
    board[0][0] = (Piece) {.type='R', .color=BLACK};
    board[1][0] = (Piece) {.type='N', .color=BLACK};
    board[2][0] = (Piece) {.type='B', .color=BLACK};
    board[3][0] = (Piece) {.type='Q', .color=BLACK};
    board[4][0] = (Piece) {.type='K', .color=BLACK};
    board[5][0] = (Piece) {.type='B', .color=BLACK};
    board[6][0] = (Piece) {.type='N', .color=BLACK};
    board[7][0] = (Piece) {.type='R', .color=BLACK};
    for(int i=0; i<BOARD_SIZE; i++) {
        board[i][1] = (Piece) {.type='P', .color=BLACK};
    }
    // White pieces
    board[0][7] = (Piece) {.type='R', .color=WHITE};
    board[1][7] = (Piece) {.type='N', .color=WHITE};
    board[2][7] = (Piece) {.type='B', .color=WHITE};
    board[3][7] = (Piece) {.type='Q', .color=WHITE};
    board[4][7] = (Piece) {.type='K', .color=WHITE};
    board[5][7] = (Piece) {.type='B', .color=WHITE};
    board[6][7] = (Piece) {.type='N', .color=WHITE};
    board[7][7] = (Piece) {.type='R', .color=WHITE};
    for(int i=0; i<BOARD_SIZE; i++) {
        board[i][6] = (Piece) {.type='P', .color=WHITE};
    }
}

// Function to print the current state of the chess board
void printBoard() {
    printf("\n");
    for(int y=BOARD_SIZE-1; y>=0; y--) {
        printf("%d  ", y+1);
        for(int x=0; x<BOARD_SIZE; x++) {
            if(board[x][y].type != '\0') {
                printf("%c%s ", board[x][y].color, &board[x][y].type);
            } else {
                printf("-- ");
            }
        }
        printf("\n");
    }
    printf("   A  B  C  D  E  F  G  H\n");
}

// Function to convert move string to Move structure
Move strToMove(char* moveStr) {
    Move move = {
        .fromX = moveStr[0] - 'A',
        .fromY = moveStr[1] - '1',
        .toX = moveStr[2] - 'A',
        .toY = moveStr[3] - '1'
    };
    return move;
}

// Function to check if move is valid for given piece
int isValidMove(Move move, Piece piece) {
    // TODO: Implement this function to check if move is valid for given piece
    return 1;
}

// Function to move the piece on the board for the given move
int movePiece(Move move) {
    Piece piece = board[move.fromX][move.fromY];
    if(piece.type == '\0') { // There is no piece at 'from' location
        return 0;
    }
    if(piece.color == WHITE) {
        printf("White: ");
    } else {
        printf("Black: ");
    }
    printf("Moved %c from %c%d to %c%d\n", piece.type, move.fromX+'A', move.fromY+1, move.toX+'A', move.toY+1);
    // Move the piece
    board[move.toX][move.toY] = piece;
    board[move.fromX][move.fromY].type = '\0';
    return 1;
}

// Main function to run the chess engine
int main() {
    char input[10];
    Move move = {0, 0, 0, 0};
    initBoard();
    // Print the initial state of the board
    printBoard();
    while(1) {
        printf("Enter move (e.g. A2A4): ");
        fgets(input, 10, stdin);
        if(input[0] == 'q' || input[0] == 'Q') { // Quit the game
            printf("Game over!\n");
            break;
        }
        if(strlen(input) != 5 || !isalpha(input[0]) || !isdigit(input[1]) || !isalpha(input[2]) || !isdigit(input[3])) {
            printf("Invalid input. Enter move in the format 'A2A4'\n");
            continue;
        }
        move = strToMove(input);
        if(!isValidMove(move, board[move.fromX][move.fromY])) { // Move is not valid for the selected piece
            printf("Invalid move. Try again.\n");
            continue;
        }
        if(movePiece(move)) { // Move the selected piece to the new location
            printBoard();
        } else { // No piece at the 'from' location
            printf("No piece at location %c%d. Try again.\n", move.fromX+'A', move.fromY+1);
        }
    }
    return 0;
}