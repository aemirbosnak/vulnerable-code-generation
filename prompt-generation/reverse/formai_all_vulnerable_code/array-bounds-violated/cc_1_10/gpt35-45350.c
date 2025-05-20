//FormAI DATASET v1.0 Category: Checkers Game ; Style: inquisitive
#include <stdio.h> // for input/output functions
#include <stdbool.h> // for boolean values
#define SIZE 8 // size of the board

char board[SIZE][SIZE]; // global variable for our board

// function to initialize the board
void initialize_board() {
    int row, col;
    // loop through each cell and set its value to "-"
    for(row = 0; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            board[row][col] = '-';
        }
    }
}

// function to print the board
void print_board() {
    int row, col;
    printf("\n    ");
    for(row = 0; row < SIZE; row++) {
        printf("%d ", row); // print column numbers
    }
    printf("\n\n");
    for(row = 0; row < SIZE; row++) {
        printf("%d   ", row); // print row numbers
        for(col = 0; col < SIZE; col++) {
            printf("%c ", board[row][col]); // print cell content
        }
        printf("\n");
    }
    printf("\n");
}

// function to place pieces on the board
void place_pieces() {
    int row, col;
    // place "W" pieces on top 3 rows
    for(row = 0; row < 3; row++) {
        for(col = 0; col < SIZE; col++) {
            if((row+col) % 2 == 0) {
                board[row][col] = 'W';
            }
        }
    }
    // place "B" pieces on bottom 3 rows
    for(row = 5; row < SIZE; row++) {
        for(col = 0; col < SIZE; col++) {
            if((row+col) % 2 == 0) {
                board[row][col] = 'B';
            }
        }
    }
}

// function to move pieces on the board
bool move_piece(char piece, int from_row, int from_col, int to_row, int to_col) {
    // check if move is legal
    if(to_row < 0 || to_row >= SIZE || to_col < 0 || to_col >= SIZE) {
        printf("Invalid move - out of bounds.\n");
        return false;
    }
    if(board[to_row][to_col] != '-') {
        printf("Invalid move - destination cell is occupied.\n");
        return false;
    }
    if(piece == 'W' && to_row >= from_row) {
        printf("Invalid move - white pieces can only move diagonally upwards.\n");
        return false;
    }
    if(piece == 'B' && to_row <= from_row) {
        printf("Invalid move - black pieces can only move diagonally downwards.\n");
        return false;
    }
    if(abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) {
        board[to_row][to_col] = piece; // make the move
        board[from_row][from_col] = '-'; // remove the piece from its previous position
        return true;
    }
    else if(abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
        int cap_row = (from_row + to_row) / 2;
        int cap_col = (from_col + to_col) / 2;
        if(board[cap_row][cap_col] == piece || board[cap_row][cap_col] == '-') {
            printf("Invalid move - must capture an opponent's piece.\n");
            return false;
        }
        board[to_row][to_col] = piece; // make the move
        board[from_row][from_col] = '-'; // remove the piece from its previous position
        board[cap_row][cap_col] = '-'; // remove the captured piece from the board
        printf("Captured %c at (%d, %d)\n", board[cap_row][cap_col], cap_row, cap_col); // print captured piece info
        return true;
    }
    else {
        printf("Invalid move - piece can only move one or two diagonal spaces.\n");
        return false;
    }
}

int main() {
    char turn = 'W'; // initialize turn to white
    int from_row, from_col, to_row, to_col;
    initialize_board();
    place_pieces();
    printf("Welcome to Checkers!\n");
    printf("To make a move, enter the row and column of the piece you want to move,\n");
    printf("followed by the row and column of the destination.\n");
    printf("For example, '2 1 3 2' would move the piece at (2,1) to (3,2).\n");
    printf("White pieces are represented by 'W' and black pieces are represented by 'B'.\n");
    while(true) {
        print_board();
        printf("It's %c's turn.\n", turn);
        printf("Enter your move: ");
        scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
        if(board[from_row][from_col] == turn) { // make sure player's piece is being moved
            if(move_piece(turn, from_row, from_col, to_row, to_col)) {
                if(turn == 'W') {
                    turn = 'B'; // switch turn to black
                }
                else {
                    turn = 'W'; // switch turn to white
                }
            }
        }
        else {
            printf("Invalid move - you can only move your own pieces.\n");
        }
    }
    return 0;
}