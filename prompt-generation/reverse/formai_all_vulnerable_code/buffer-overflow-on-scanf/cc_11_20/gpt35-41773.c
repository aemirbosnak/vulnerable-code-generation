//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include<stdio.h>
//Defining the board size
#define BOARD_SIZE 8

//Global variables
char player1[20], player2[20];
char board[BOARD_SIZE][BOARD_SIZE];

//Function to print the board
void print_board() {
    printf("\n    A B C D E F G H\n");
    printf("  +-----------------+\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }

    printf("  +-----------------+\n\n");
}

//Function to initialize the board
void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = 'B'; //Player 1
            }
            else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = 'W'; //Player 2
            }
            else {
                board[i][j] = '_'; //Blank space
            }
        }
    }
}

//Function to check if the move is valid
int is_valid_move(int x1, int y1, int x2, int y2, char player) {
    if (board[x2][y2] != '_') {
        return 0;
    }

    if (player == 'B' || player == 'K') {
        if (x2 - x1 == 1 && (y2 - y1 == 1 || y2 - y1 == -1)) {
            return 1;
        }
        else if (x2 - x1 == 2 && (y2 - y1 == 2 || y2 - y1 == -2)) {
            if (board[x1 + (x2 - x1)/2][y1 + (y2 - y1)/2] == 'W' || board[x1 + (x2 - x1)/2][y1 + (y2 - y1)/2] == 'K') {
                board[x1 + (x2 - x1)/2][y1 + (y2 - y1)/2] = '_';
                return 1;
            }
        }
    }

    if (player == 'W' || player == 'K') {
        if (x1 - x2 == 1 && (y2 - y1 == 1 || y2 - y1 == -1)) {
            return 1;
        }
        else if (x1 - x2 == 2 && (y2 - y1 == 2 || y2 - y1 == -2)) {
            if (board[x1 - (x1 - x2)/2][y1 + (y2 - y1)/2] == 'B' || board[x1 - (x1 - x2)/2][y1 + (y2 - y1)/2] == 'K') {
                board[x1 - (x1 - x2)/2][y1 + (y2 - y1)/2] = '_';
                return 1;
            }
        }
    }

    return 0;
}

//Function to make a move
void make_move(int x1, int y1, int x2, int y2, char player) {
    if (player == 'B' && x2 == BOARD_SIZE - 1) {
        board[x2][y2] = 'K';
    }
    else if (player == 'W' && x2 == 0) {
        board[x2][y2] = 'K';
    }
    else {
        board[x2][y2] = board[x1][y1];
    }

    board[x1][y1] = '_';
}

//Function to check if any player has won
int has_won(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == 'K') {
                if (player == 'B' && board[i][j] == 'K' && (i - 2 >= 0 && j - 2 >= 0 && board[i-1][j-1] == 'W' && board[i-2][j-2] == '_') ||
                    (i - 2 >= 0 && j + 2 < BOARD_SIZE && board[i-1][j+1] == 'W' && board[i-2][j+2] == '_') ||
                    (i + 2 < BOARD_SIZE && j - 2 >= 0 && board[i+1][j-1] == 'W' && board[i+2][j-2] == '_') ||
                    (i + 2 < BOARD_SIZE && j + 2 < BOARD_SIZE && board[i+1][j+1] == 'W' && board[i+2][j+2] == '_')) {
                    return 0;
                }
                else if (player == 'W' && board[i][j] == 'K' && (i - 2 >= 0 && j - 2 >= 0 && board[i-1][j-1] == 'B' && board[i-2][j-2] == '_') ||
                    (i - 2 >= 0 && j + 2 < BOARD_SIZE && board[i-1][j+1] == 'B' && board[i-2][j+2] == '_') ||
                    (i + 2 < BOARD_SIZE && j - 2 >= 0 && board[i+1][j-1] == 'B' && board[i+2][j-2] == '_') ||
                    (i + 2 < BOARD_SIZE && j + 2 < BOARD_SIZE && board[i+1][j+1] == 'B' && board[i+2][j+2] == '_')) {
                    return 0;
                }
                else if (player == 'B' && (i - 1 >= 0 && j - 1 >= 0 && board[i-1][j-1] == '_' || 
                    (i - 1 >= 0 && j + 1 < BOARD_SIZE && board[i-1][j+1] == '_'))) {
                    return 0;
                }
                else if (player == 'W' && (i + 1 < BOARD_SIZE && j - 1 >= 0 && board[i+1][j-1] == '_' || 
                    (i + 1 < BOARD_SIZE && j + 1 < BOARD_SIZE && board[i+1][j+1] == '_'))) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

//Main function
int main() {
    printf("Enter player 1 name: ");
    scanf("%s", player1);
    printf("Enter player 2 name: ");
    scanf("%s", player2);

    init_board();

    int winner = -1;
    int turn = 0;
    int x1, y1, x2, y2;

    while (winner == -1) {
        print_board();

        if (turn % 2 == 0) {
            printf("%s's turn (Black)\n", player1);
        }
        else {
            printf("%s's turn (White)\n", player2);
        }

        printf("Enter the coordinates of the piece you want to move (e.g. 2,3): ");
        scanf("%d,%d", &x1, &y1);
        printf("Enter the coordinates of the space you want to move to (e.g. 3,4): ");
        scanf("%d,%d", &x2, &y2);

        char player = turn % 2 == 0 ? 'B' : 'W';

        if (is_valid_move(x1 - 1, y1 - 1, x2 - 1, y2 - 1, player)) {
            make_move(x1 - 1, y1 - 1, x2 - 1, y2 - 1, player);

            if (has_won('B')) {
                winner = 1;
            }
            else if (has_won('W')) {
                winner = 2;
            }

            turn++;
        }
        else {
            printf("Invalid move!\n");
        }
    }

    print_board();

    if (winner == 1) {
        printf("%s has won!\n", player1);
    }
    else {
        printf("%s has won!\n", player2);
    }

    return 0;
}