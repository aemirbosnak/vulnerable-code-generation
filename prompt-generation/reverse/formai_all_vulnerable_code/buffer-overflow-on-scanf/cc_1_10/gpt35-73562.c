//FormAI DATASET v1.0 Category: Table Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype for game logic functions
void print_rules();
void initialize_board(char board[3][3]);
void print_board(char board[3][3]);
void player_move(char board[3][3], char player_marker);
void computer_move(char board[3][3], char computer_marker);
int check_win(char board[3][3]);

int main() {
    char board[3][3];
    char player_marker, computer_marker;
    int turn = 0, winner = 0;
    
    // initialize random number generator
    srand(time(NULL));
    
    // print game rules
    print_rules();
    
    // determine player marker (X or O)
    printf("Do you want to play as X or O? ");
    scanf("%c", &player_marker);
    while (getchar() != '\n'); // flush input buffer
    
    // assign opposing marker to computer
    if (player_marker == 'X') {
        computer_marker = 'O';
    } else {
        computer_marker = 'X';
    }
    
    // initialize game board
    initialize_board(board);
    
    // loop until game is won or tied
    while (winner == 0) {
        // alternate turns between player and computer
        if (turn % 2 == 0) {
            // player move
            printf("Your turn:\n");
            print_board(board);
            player_move(board, player_marker);
        } else {
            // computer move
            printf("Computer's turn:\n");
            print_board(board);
            computer_move(board, computer_marker);
        }
        
        // check for win
        winner = check_win(board);
        
        // increment turn counter
        turn++;
    }
    
    // print final game board and winner
    print_board(board);
    if (winner == 1) {
        printf("Congratulations! You won!\n");
    } else if (winner == 2) {
        printf("Better luck next time. Computer wins!\n");
    } else {
        printf("The game is a tie!\n");
    }
    
    return 0;
}

void print_rules() {
    printf("Welcome to the C Table Game!\n");
    printf("To win, get three of your markers in a row (vertical, horizontal, or diagonal).\n");
    printf("The game board is a 3x3 table, each cell can be marked with 'X' or 'O'.\n");
    printf("Take turns with the computer to place your marker.\n");
}

void initialize_board(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void player_move(char board[3][3], char player_marker) {
    int row, col;
    do {
        printf("Enter row (1-3) and column (1-3) to place your mark: ");
        scanf("%d %d", &row, &col);
        while (getchar() != '\n'); // flush input buffer
        row--;
        col--;
    } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-');
    board[row][col] = player_marker;
}

void computer_move(char board[3][3], char computer_marker) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != '-');
    board[row][col] = computer_marker;
}

int check_win(char board[3][3]) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                return 1;
            } else {
                return 2;
            }
        }
    }
    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1;
        } else {
            return 2;
        }
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1;
        } else {
            return 2;
        }
    }
    // check if all cells are filled
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 3; // tie game
}