//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // tic-tac-toe board
char ai; // X or O
char human; // X or O
int ai_won = 0; // flag for checking if AI has already won
int human_won = 0; // flag for checking if human has already won

// function to display the board
void display_board() {
    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("1  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// function to check if any player has won
int check_win(char player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
        return 1;
    }
    return 0;
}

// function to make the AI move
void ai_move() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' '); // keep generating random coordinates until an empty cell is found
    board[row][col] = ai; // make the move
}

// function to make the human move
void human_move() {
    int row, col;
    printf("Enter your move (row column): ");
    scanf("%d %d", &row, &col);
    while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') { // input validation
        printf("Invalid move, please try again.\nEnter your move (row column): ");
        scanf("%d %d", &row, &col);
    }
    board[row][col] = human; // make the move
}

int main() {
    // initialize the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    // let the player choose between X and O
    printf("Do you want to play as X or O? ");
    scanf(" %c", &human);
    while (human != 'X' && human != 'O') { // input validation
        printf("Invalid choice, please try again.\nDo you want to play as X or O? ");
        scanf(" %c", &human);
    }
    if (human == 'X') {
        ai = 'O';
    } else {
        ai = 'X';
    }
    // game loop
    int turn = 0;
    do {
        system("clear"); // clear the console
        display_board();
        if (turn % 2 == 0) {
            // AI's turn
            ai_move();
            if (check_win(ai)) {
                ai_won = 1;
                break;
            }
        } else {
            // human's turn
            human_move();
            if (check_win(human)) {
                human_won = 1;
                break;
            }
        }
        turn++;
    } while (turn < 9); // maximum number of turns is 9
    system("clear"); // clear the console
    display_board();
    if (ai_won) {
        printf("AI won!\n");
    } else if (human_won) {
        printf("You won!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}