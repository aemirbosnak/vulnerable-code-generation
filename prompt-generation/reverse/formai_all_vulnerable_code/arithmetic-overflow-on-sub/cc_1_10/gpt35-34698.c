//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void display_board(char board[3][3]);
int check_winner(char board[3][3]);
void player_move(char board[3][3], char player);
void computer_move(char board[3][3], char computer, char player);

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player, computer;
    int winner = 0;
    srand(time(NULL));
    
    // choose player and computer symbols
    printf("Choose your symbol (X/O): ");
    scanf(" %c", &player);
    if (player == 'X') {
        computer = 'O';
    } else {
        computer = 'X';
    }
    printf("You are %c, computer is %c\n", player, computer);
    
    // game loop
    while (!winner) {
        display_board(board);
        player_move(board, player);
        winner = check_winner(board);
        if (winner) {
            break;
        }
        computer_move(board, computer, player);
        winner = check_winner(board);
    }
    
    // game over
    display_board(board);
    if (winner == 1) {
        printf("You won!\n");
    } else if (winner == 2) {
        printf("Computer won!\n");
    } else {
        printf("Tie game!\n");
    }
    
    return 0;
}

// displays the tic tac toe board
void display_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// checks if there is a winner
int check_winner(char board[3][3]) {
    int i, j, row, col;
    
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                return 1;
            } else if (board[i][0] == 'O') {
                return 2;
            }
        }
    }
    
    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') {
                return 1;
            } else if (board[0][i] == 'O') {
                return 2;
            }
        }
    }
    
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            return 1;
        } else if (board[0][0] == 'O') {
            return 2;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            return 1;
        } else if (board[0][2] == 'O') {
            return 2;
        }
    }
    
    // check for tie
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 3;
}

// allows the player to make a move
void player_move(char board[3][3], char player) {
    int row, col;
    do {
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
    } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ');
    board[row][col] = player;
}

// allows the computer to make a move
void computer_move(char board[3][3], char computer, char player) {
    int i, j, row, col;
    // check if computer can win
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computer;
                if (check_winner(board) == 2) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // check if player can win
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (check_winner(board) == 1) {
                    board[i][j] = computer;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // choose random spot
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = computer;
}