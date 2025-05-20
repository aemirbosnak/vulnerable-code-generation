//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Function to check if a player has won or not
int check_win(char *board, char player) {

    // Check for horizontal wins
    for(int i = 0; i < 9; i += 3) {
        if(board[i] == player && board[i+1] == player && board[i+2] == player) {
            return 1;
        }
    }

    // Check for vertical wins
    for(int i = 0; i < 3; i++) {
        if(board[i] == player && board[i+3] == player && board[i+6] == player) {
            return 1;
        }
    }

    // Check for diagonal wins
    if(board[0] == player && board[4] == player && board[8] == player) {
        return 1;
    }
    if(board[2] == player && board[4] == player && board[6] == player) {
        return 1;
    }

    // No wins found
    return 0;
}

// Function to evaluate the score of a given move
int evaluate_move(char *board, int move, char player) {

    // Make a copy of the board to simulate the move
    char temp_board[9];
    for(int i = 0; i < 9; i++) {
        temp_board[i] = board[i];
    }
    temp_board[move] = player;

    // Check for wins and losses
    if(check_win(temp_board, player)) {
        return 10;
    }
    if(check_win(temp_board, (player == 'X') ? 'O' : 'X')) {
        return -10;
    }

    // No wins or losses found; return 0
    return 0;
}

// Function to execute the computer's turn
int computer_turn(char *board, char computer) {

    int best_score = -1000;
    int best_move;

    // Evaluate all possible moves
    for(int i = 0; i < 9; i++) {
        if(board[i] == ' ') {
            int score = evaluate_move(board, i, computer);
            if(score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }

    // Make the best move
    board[best_move] = computer;

    return best_move;
}

// Function to execute a player's turn
int player_turn(char *board, char player) {

    int move;

    printf("Enter move for %c: ", player);
    scanf("%d", &move);
    while(move < 1 || move > 9 || board[move-1] != ' ') {
        printf("Invalid move. Enter move for %c: ", player);
        scanf("%d", &move);
    }

    board[move-1] = player;

    return move-1;
}

// Function to display the current state of the board
void display_board(char *board) {

    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int main() {

    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player, computer;
    int turn = 0;

    // Determine player and computer
    printf("Do you want to play X or O? ");
    scanf("%c", &player);
    while(player != 'X' && player != 'O') {
        printf("Invalid input! Do you want to play X or O? ");
        scanf(" %c", &player);
    }
    computer = (player == 'X') ? 'O' : 'X';

    // Main game loop
    while(1) {
        display_board(board);

        if(turn % 2 == 0) {
            printf("Computer's turn:\n");
            computer_turn(board, computer);
        }
        else {
            printf("Player's turn:\n");
            player_turn(board, player);
        }

        // Check for tie
        if(turn == 8) {
            display_board(board);
            printf("The game ended in a tie!\n");
            break;
        }

        // Check for win
        if(check_win(board, player)) {
            display_board(board);
            printf("Congratulations! You win!\n");
            break;
        }
        if(check_win(board, computer)) {
            display_board(board);
            printf("Sorry, you lost.\n");
            break;
        }

        turn++;
    }

    return 0;
}