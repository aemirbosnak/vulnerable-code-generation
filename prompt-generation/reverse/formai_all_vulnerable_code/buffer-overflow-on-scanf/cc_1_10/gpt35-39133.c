//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // tic tac toe board

int moves[9][2] = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}}; // available moves

void draw_board(); // function to draw board
int take_turn(int player); // function for player's turn
int has_won(int player); // function to check if player has won
int get_winner(); // function to get winner of game

int get_ai_move(); // function for AI to make a move
int ai_has_won(); // function to check if AI has won

int main() {
    srand(time(NULL)); // seed random number generator
    int turn = 1; // keeps track of player turn
    int winner = 0; // 0 = no winner yet, 1 = player won, 2 = AI won, 3 = draw
    
    // initialize board to '-'
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    
    printf("\n\t*** Tic Tac Toe ***\n\n");
    draw_board(); // draw initial board
    
    while (winner == 0) {
        if (turn % 2 == 1) { // player's turn
            int move = take_turn(1); // get player's move
            board[moves[move][0]][moves[move][1]] = 'X'; // update board
            if (has_won(1)) { // check if player has won
                winner = 1;
            }
        } else { // AI's turn
            int move = get_ai_move(); // get AI's move
            board[moves[move][0]][moves[move][1]] = 'O'; // update board
            if (ai_has_won()) { // check if AI has won
                winner = 2;
            }
        }
        turn++; // increment turn counter
        draw_board(); // draw updated board
        
        // check for draw
        if (turn > 9 && winner == 0) {
            winner = 3;
        }
    }
    
    // print winner message
    if (winner == 1) {
        printf("\n\n\tCongratulations! You won!\n\n");
    } else if (winner == 2) {
        printf("\n\n\tSorry! The AI won!\n\n");
    } else {
        printf("\n\n\tIt's a draw!\n\n");
    }
    
    return 0;
}

void draw_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
    printf("\n");
}

int take_turn(int player) {
    int valid_move = 0;
    int move;
    while (!valid_move) {
        printf("\nPlayer %d, enter your move (1-9): ", player);
        scanf("%d", &move);
        move--; // convert to 0-indexed array
        if (move < 0 || move > 8) {
            printf("\nInvalid move. Please enter a number between 1 and 9.\n");
            continue;
        }
        if (board[moves[move][0]][moves[move][1]] != '-') {
            printf("\nThat space is already taken. Please choose another move.\n");
            continue;
        }
        valid_move = 1;
    }
    return move;
}

int has_won(int player) {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
            return 1;
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == 'X') {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        return 1;
    }
    else if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
        return 1;
    }
    return 0;
}

int get_winner() {
    if (has_won(1)) { // player has won
        return 1;
    }
    else if (ai_has_won()) { // AI has won
        return 2;
    }
    else { // game is a draw
        return 3;
    }
}

int get_ai_move() {
    printf("\nAI is thinking...\n");
    int move;
    while (1) {
        move = rand() % 9; // random move
        if (board[moves[move][0]][moves[move][1]] == '-') {
            break;
        }
    }
    return move;
}

int ai_has_won() {
    // check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
            return 1;
        }
    }
    // check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == 'O') {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
        return 1;
    }
    else if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
        return 1;
    }
    return 0;
}