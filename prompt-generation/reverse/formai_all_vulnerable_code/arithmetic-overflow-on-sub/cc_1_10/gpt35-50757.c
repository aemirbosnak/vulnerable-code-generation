//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // define the tic tac toe board
int moves = 0; // tracks how many moves have been made

// print the tic tac toe board
void print_board() {
    printf("\n-------------\n");
    for(int i=0;i<3;i++) {
        printf("| ");
        for(int j=0;j<3;j++) {
            printf("%c | ",board[i][j]);
        }
        printf("\n-------------\n");
    }
    printf("\n");
}

// initialize the board with empty spaces
void initialize_board() {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            board[i][j] = ' ';
        }
    }
}

// check if there is a winner
char check_winner() {
    // check rows
    for(int i=0;i<3;i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }
    // check columns
    for(int j=0;j<3;j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }
    // check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }
    // check for draw
    if(moves == 9) {
        return 'D';
    }
    // return 0 if no winner or draw
    return 0;
}

// AI move
void ai_move(char ai_char) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(board[row][col] != ' '); // make sure move is valid
    board[row][col] = ai_char; // make move on board
    moves++; // increment moves
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    initialize_board(); // set up an empty board
    print_board(); // print the empty board
    while(moves < 9) {
        // user move
        int row, col;
        printf("Enter row and column (e.g. 1 2): ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if(board[row][col] == ' ') {
            board[row][col] = 'X'; // make move on board
            moves++; // increment moves
        } else {
            printf("Invalid move!\n");
        }
        print_board(); // print the board
        // check for winner
        char winner = check_winner();
        if(winner != 0) {
            if(winner == 'D') {
                printf("It's a draw!\n");
            } else {
                printf("Player %c wins!\n", winner);
            }
            return 0; // game is over
        }
        // AI move
        ai_move('O');
        printf("AI has made its move.\n");
        print_board();
        // check for winner
        winner = check_winner();
        if(winner != 0) {
            if(winner == 'D') {
                printf("It's a draw!\n");
            } else {
                printf("Player %c wins!\n", winner);
            }
            return 0; // game is over
        }
    }
    printf("It's a draw!\n"); // game is over, all moves used and no winner
    return 0;
}