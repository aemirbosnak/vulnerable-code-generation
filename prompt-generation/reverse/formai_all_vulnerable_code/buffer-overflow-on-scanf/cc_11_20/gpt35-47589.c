//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: light-weight
#include <stdio.h>

// global board array
char board[3][3];

// function to print the board
void print_board() {
    printf("\n");
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the game is over
int is_game_over() {
    // check rows
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '-') {
            return 1;
        }
    }
    // check columns
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '-') {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return 1;
    }
    // check draw
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board[row][col] == '-') {
                return 0;
            }
        }
    }
    return 2;
}

// function to get AI move
void get_AI_move() {
    int row, col, found = 0;
    // check rows
    for (row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][0] != '-' && board[row][2] == '-') {
            board[row][2] = 'O';
            found = 1;
            break;
        }
        if (board[row][1] == board[row][2] && board[row][1] != '-' && board[row][0] == '-') {
            board[row][0] = 'O';
            found = 1;
            break;
        }
        if (board[row][0] == board[row][2] && board[row][0] != '-' && board[row][1] == '-') {
            board[row][1] = 'O';
            found = 1;
            break;
        }
    }
    if (found) {
        return;
    }
    // check columns
    for (col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[0][col] != '-' && board[2][col] == '-') {
            board[2][col] = 'O';
            found = 1;
            break;
        }
        if (board[1][col] == board[2][col] && board[1][col] != '-' && board[0][col] == '-') {
            board[0][col] = 'O';
            found = 1;
            break;
        }
        if (board[0][col] == board[2][col] && board[0][col] != '-' && board[1][col] == '-') {
            board[1][col] = 'O';
            found = 1;
            break;
        }
    }
    if (found) {
        return;
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] != '-' && board[2][2] == '-') {
        board[2][2] = 'O';
        found = 1;
    }
    if (board[0][0] == board[2][2] && board[0][0] != '-' && board[1][1] == '-') {
        board[1][1] = 'O';
        found = 1;
    }
    if (board[1][1] == board[2][2] && board[1][1] != '-' && board[0][0] == '-') {
        board[0][0] = 'O';
        found = 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] != '-' && board[2][0] == '-') {
        board[2][0] = 'O';
        found = 1;
    }
    if (board[0][2] == board[2][0] && board[0][2] != '-' && board[1][1] == '-') {
        board[1][1] = 'O';
        found = 1;
    }
    if (board[2][0] == board[1][1] && board[2][0] != '-' && board[0][2] == '-') {
        board[0][2] = 'O';
        found = 1;
    }
    if (found) {
        return;
    }
    // random move
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != '-');
    board[row][col] = 'O';
}

// function to play the game
void play_game() {
    // initialize the board
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = '-';
        }
    }
    // print initial board
    print_board();
    // game loop
    while (1) {
        // get user move
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);
        if (board[row][col] == '-') {
            board[row][col] = 'X';
        } else {
            printf("Invalid move. Try again.\n");
            continue;
        }
        // check game over
        int status = is_game_over();
        if (status == 1) {
            printf("You win!\n");
            break;
        } else if (status == 2) {
            printf("Draw!\n");
            break;
        }
        // get AI move
        get_AI_move();
        // print board
        print_board();
        // check game over
        status = is_game_over();
        if (status == 1) {
            printf("AI wins!\n");
            break;
        } else if (status == 2) {
            printf("Draw!\n");
            break;
        }
    }
}

// main function
int main() {
    play_game();
    return 0;
}