//FormAI DATASET v1.0 Category: Chess AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int BOARD_SIZE = 8;

// Function to print the game board
void printBoard(char board[][BOARD_SIZE]) {

    printf("\n   ");

    for (int k = 0; k < BOARD_SIZE; k++) {
        printf("| %d ", k + 1);
    }

    printf("|\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|%d| ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf(" %d", i + 1);
        printf("\n");

        printf("   ");
        for (int k = 0; k < BOARD_SIZE; k++) {
            printf("----");
        }

        printf("\n");
    }

    printf("   ");
    for (int k = 0; k < BOARD_SIZE; k++) {
        printf("| %d ", k + 1);
    }

    printf("|\n\n");
}

// Function to initialize the game board
void initializeBoard(char board[][BOARD_SIZE]) {

    for (int i = 0; i < BOARD_SIZE; i++) {

        board[1][i] = 'P';
        board[6][i] = 'p';

        switch (i) {
            case 0:
            case 7:
                board[0][i] = 'R';
                board[7][i] = 'r';
                break;
            case 1:
            case 6:
                board[0][i] = 'N';
                board[7][i] = 'n';
                break;
            case 2:
            case 5:
                board[0][i] = 'B';
                board[7][i] = 'b';
                break;
            case 3:
                board[0][i] = 'Q';
                board[7][i] = 'q';
                break;
            case 4:
                board[0][i] = 'K';
                board[7][i] = 'k';
                break;
        }
    }

    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to get the player input
void getPlayerInput(char board[][BOARD_SIZE], int *x1, int *y1, int *x2, int *y2) {

    char input[10];
    printf("\nEnter the piece you want to move (eg. a2): ");
    fflush(stdin);
    gets(input);

    *x1 = input[1] - '0' - 1;
    *y1 = input[0] - 'a';

    printf("\nEnter the position where you want to move the piece (eg. a4): ");
    fflush(stdin);
    gets(input);

    *x2 = input[1] - '0' - 1;
    *y2 = input[0] - 'a';
}

// Function to check if the move is valid
int isMoveValid(char board[][BOARD_SIZE], int x1, int y1, int x2, int y2) {

    if (x1 == x2 && y1 == y2) {
        printf("\nInvalid move! Exiting...\n");
        exit(0);
    }

    char piece = board[x1][y1];

    // Checking if the piece being moved is a pawn
    if (piece == 'P' || piece == 'p') {

        int dy = y2 - y1;
        int dx = x2 - x1;

        if (piece == 'P') {
            dx = -dx;
        }

        if (dx > 0) {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        }

        if (dy == 0) {
            if ((piece == 'P' && x1 != 1) || (piece == 'p' && x1 != 6)) {
                if (board[x2][y2] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                }
            } else {
                if (dx == -1 && board[x2][y2] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                } else if (dx == -2 && board[x1 - 1][y1] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                }
            }
        } else if (abs(dy) > 1 || abs(dx) != 1) {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        } else if (board[x2][y2] == ' ') {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        }
    }

    // Checking if the piece being moved is a rook
    if (piece == 'R' || piece == 'r') {

        if (x1 != x2 && y1 != y2) {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        }

        if (x1 == x2) {
            int start = y1 < y2 ? y1 : y2;
            int end = y1 < y2 ? y2 : y1;

            for (int i = start + 1; i < end; i++) {
                if (board[x1][i] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                }
            }
        } else {
            int start = x1 < x2 ? x1 : x2;
            int end = x1 < x2 ? x2 : x1;

            for (int i = start + 1; i < end; i++) {
                if (board[i][y1] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                }
            }
        }
    }

    // Checking if the piece being moved is a knight
    if (piece == 'N' || piece == 'n') {

        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);

        if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1))) {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        }
    }

    // Checking if the piece being moved is a bishop
    if (piece == 'B' || piece == 'b') {

        int dx = x2 - x1;
        int dy = y2 - y1;

        if (abs(dx) != abs(dy)) {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        }

        int i = x1 < x2 ? x1 + 1 : x2 + 1;
        int j = y1 < y2 ? y1 + 1 : y2 + 1;

        for (; i < x2 && j < y2; i++, j++) {
            if (board[i][j] != ' ') {
                printf("\nInvalid move! Exiting...\n");
                exit(0);
            }
        }

        i = x1 < x2 ? x2 - 1 : x1 - 1;
        j = y1 < y2 ? y2 - 1 : y1 - 1;

        for (; i > x1 && j > y1; i--, j--) {
            if (board[i][j] != ' ') {
                printf("\nInvalid move! Exiting...\n");
                exit(0);
            }
        }
    }

    // Checking if the piece being moved is a queen
    if (piece == 'Q' || piece == 'q') {

        // Checking if the move is valid for a rook
        if (x1 == x2 || y1 == y2) {

            if (x1 == x2) {
                int start = y1 < y2 ? y1 : y2;
                int end = y1 < y2 ? y2 : y1;

                for (int i = start + 1; i < end; i++) {
                    if (board[x1][i] != ' ') {
                        printf("\nInvalid move! Exiting...\n");
                        exit(0);
                    }
                }
            } else {
                int start = x1 < x2 ? x1 : x2;
                int end = x1 < x2 ? x2 : x1;

                for (int i = start + 1; i < end; i++) {
                    if (board[i][y1] != ' ') {
                        printf("\nInvalid move! Exiting...\n");
                        exit(0);
                    }
                }
            }

        // Checking if the move is valid for a bishop
        } else {

            int dx = x2 - x1;
            int dy = y2 - y1;

            if (abs(dx) != abs(dy)) {
                printf("\nInvalid move! Exiting...\n");
                exit(0);
            }

            int i = x1 < x2 ? x1 + 1 : x2 + 1;
            int j = y1 < y2 ? y1 + 1 : y2 + 1;

            for (; i < x2 && j < y2; i++, j++) {
                if (board[i][j] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                }
            }

            i = x1 < x2 ? x2 - 1 : x1 - 1;
            j = y1 < y2 ? y2 - 1 : y1 - 1;

            for (; i > x1 && j > y1; i--, j--) {
                if (board[i][j] != ' ') {
                    printf("\nInvalid move! Exiting...\n");
                    exit(0);
                }
            }
        }
    }

    // Checking if the piece being moved is a king
    if (piece == 'K' || piece == 'k') {

        int dx = abs(x1 - x2);
        int dy = abs(y1 - y2);

        if (!((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1))) {
            printf("\nInvalid move! Exiting...\n");
            exit(0);
        }
    }

    return 1;
}

// Function to move the piece
void movePiece(char board[][BOARD_SIZE], int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
}

// Function to check for checkmate
int isCheckmate(char board[][BOARD_SIZE]) {
    return 0;
}

// Main game function
void playChess() {

    // Initializing the board
    char board[BOARD_SIZE][BOARD_SIZE];

    initializeBoard(board);

    // Printing the starting board
    printBoard(board);

    // Game loop
    while (1) {

        // Printing the current board
        printBoard(board);

        // Getting the player input
        int x1, y1, x2, y2;
        getPlayerInput(board, &x1, &y1, &x2, &y2);

        // Checking if the move is valid
        isMoveValid(board, x1, y1, x2, y2);

        // Moving the piece
        movePiece(board, x1, y1, x2, y2);

        // Checking for checkmate
        if (isCheckmate(board)) {
            printf("\nCHECKMATE\n");
            break;
        }
    }
}

int main() {
    printf("Curious Chess AI Program\n\n");
    printf("Rules:\n1. Enter the position of the piece you want to move and the position you want to move it to.\n2. Input the positions in the format 'a2'.\n3. Have fun!\n\n");
    playChess();
    return 0;
}