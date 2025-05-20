//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chess board is represented using a simple 8x8 array.
char chess_board[8][8];

// Function to initialize the chess board.
void initialize_board() {
    // Clear the board i.e., assign '-' to each square.
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            chess_board[i][j] = '-';
        }
    }

    // Set up the initial positions of white pieces.
    chess_board[0][0] = 'R';
    chess_board[0][1] = 'N';
    chess_board[0][2] = 'B';
    chess_board[0][3] = 'Q';
    chess_board[0][4] = 'K';
    chess_board[0][5] = 'B';
    chess_board[0][6] = 'N';
    chess_board[0][7] = 'R';

    for(int i=0; i<8; i++) {
        chess_board[1][i] = 'P';
    }

    // Set up the initial positions of black pieces.
    chess_board[7][0] = 'r';
    chess_board[7][1] = 'n';
    chess_board[7][2] = 'b';
    chess_board[7][3] = 'q';
    chess_board[7][4] = 'k';
    chess_board[7][5] = 'b';
    chess_board[7][6] = 'n';
    chess_board[7][7] = 'r';

    for(int i=0; i<8; i++) {
        chess_board[6][i] = 'p';
    }
}

// Function to print the current state of the chess board.
void print_board() {
    printf("  a b c d e f g h\n");
    for(int i=0; i<8; i++) {
        printf("%d ", i+1);
        for(int j=0; j<8; j++) {
            printf("%c ", chess_board[i][j]);
        }
        printf("%d\n", i+1);
    }
    printf("  a b c d e f g h\n\n");
}

// Function to convert the given user input into board positions.
void get_positions(char input[], int* src_x, int* src_y, int* dest_x, int* dest_y) {
    *src_x = 8 - (int)(input[1]-'0');
    *dest_x = 8 - (int)(input[4]-'0');
    *src_y = (int)(input[0]-'a');
    *dest_y = (int)(input[3]-'a');
}

// Function to validate the given move.
int validate_move(int src_x, int src_y, int dest_x, int dest_y) {
    // Check if source and destination positions are within the range (0-7).
    if(src_x < 0 || src_x > 7 || dest_x < 0 || dest_x > 7 ||
        src_y < 0 || src_y > 7 || dest_y < 0 || dest_y > 7) {
        return 0;
    }

    // Check if the source position contains a valid chess piece.
    char piece = chess_board[src_x][src_y];
    if(piece == '-') {
        return 0;
    }

    // Check if the destination position is free or contains a valid opponent piece.
    char dest_piece = chess_board[dest_x][dest_y];
    if(dest_piece != '-' && (isupper(piece) == isupper(dest_piece))) {
        return 0;
    }

    // TODO: Add more rules for specific chess pieces (e.g. pawn movements, castling, en passant).

    // If the move is valid, return 1.
    return 1;
}

// Function to execute the given move.
void execute_move(int src_x, int src_y, int dest_x, int dest_y) {
    char piece = chess_board[src_x][src_y];
    chess_board[src_x][src_y] = '-';
    chess_board[dest_x][dest_y] = piece;
}

int main() {
    initialize_board();
    print_board();

    char input[10];
    int src_x, src_y, dest_x, dest_y;

    while(1) {
        printf("Enter the move (e.g. a2-a3): ");
        scanf("%s", input);

        get_positions(input, &src_x, &src_y, &dest_x, &dest_y);

        if(validate_move(src_x, src_y, dest_x, dest_y)) {
            execute_move(src_x, src_y, dest_x, dest_y);
            print_board();
        } else {
            printf("Invalid move! Try again.\n\n");
        }
    }

    return 0;
}