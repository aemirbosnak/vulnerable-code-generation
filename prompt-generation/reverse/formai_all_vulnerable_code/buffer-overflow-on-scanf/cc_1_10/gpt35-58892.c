//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Board size
#define N 3

//The player's symbols
#define PLR1 'X'
#define PLR2 'O'

//Used to represent the board
char board[N][N] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

//Used to check if a position on the board is free
bool is_free(int x, int y) {
    return board[x][y] == ' ';
}

//Used to check if a player has won the game
bool has_won(char symbol) {
    //First check the rows
    for (int i = 0; i < N; i++) {
        if (board[i][0] == symbol &&
            board[i][1] == symbol &&
            board[i][2] == symbol) {
            return true;
        }
    }
    //Then check the columns
    for (int j = 0; j < N; j++) {
        if (board[0][j] == symbol &&
            board[1][j] == symbol &&
            board[2][j] == symbol) {
            return true;
        }
    }
    //Finally check the diagonal
    if (board[0][0] == symbol &&
        board[1][1] == symbol &&
        board[2][2] == symbol) {
        return true;
    }
    //And the other diagonal
    if (board[0][2] == symbol &&
        board[1][1] == symbol &&
        board[2][0] == symbol) {
        return true;
    }
    //If no winning combination was found
    return false;
}

//Used to print the board
void print_board() {
    printf("-------------------\n");
    for (int i = 0; i < N; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------------\n");
    }
}

//The recursive minimax function used to calculate the best move for the AI
int minimax(char player) {
    //First we check if the game is over
    if (has_won(PLR1)) {
        return 10; //Player 1 has won
    }
    if (has_won(PLR2)) {
        return -10; //Player 2 has won
    }
    bool tie = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_free(i, j)) {
                tie = false;
            }
        }
    }
    if (tie) {
        return 0; //The game is a tie
    }
    
    //If the game is not over, we calculate the score for each possible move
    int best_score;
    if (player == PLR1) { //maximizing player
        best_score = -1000; //initial value
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (is_free(i, j)) { //if the position is free
                    board[i][j] = PLR1; //make the move
                    int score = minimax(PLR2); //calculate the score for the opponent's move
                    board[i][j] = ' '; //undo the move
                    if (score > best_score) {
                        best_score = score; //update the best score
                    }
                }
            }
        }
    } else { //minimizing player
        best_score = 1000; //initial value
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (is_free(i, j)) { //if the position is free
                    board[i][j] = PLR2; //make the move
                    int score = minimax(PLR1); //calculate the score for the opponent's move
                    board[i][j] = ' '; //undo the move
                    if (score < best_score) {
                        best_score = score; //update the best score
                    }
                }
            }
        }
    }
    return best_score;
}

//The function used to get the best move for the AI
void get_ai_move(int* x, int* y) {
    int best_score = -1000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (is_free(i, j)) {
                board[i][j] = PLR1;
                int score = minimax(PLR2);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    *x = i;
                    *y = j;
                }
            }
        }
    }
}

//The main function
int main() {
    int player_choice;
    printf("Welcome to Tic Tac Toe!\n");
    while (true) {
        printf("Do you want to go first (1) or second (2)? ");
        scanf("%d", &player_choice);
        if (player_choice == 1) {
            printf("You are player %c\n", PLR1);
            break;
        }
        if (player_choice == 2) {
            printf("You are player %c\n", PLR2);
            break;
        }
        printf("Invalid choice, please try again.\n");
    }
    int turn = 0;
    while (true) {
        if (turn % 2 == player_choice - 1) { //player's turn
            int row, col;
            while (true) {
                printf("Enter your move (row, column): ");
                scanf("%d %d", &row, &col);
                if (row < 1 || row > N || col < 1 || col > N) {
                    printf("Invalid move, please try again.\n");
                    continue;
                }
                if (!is_free(row - 1, col - 1)) {
                    printf("That position is already taken, please try again.\n");
                    continue;
                }
                break;
            }
            board[row - 1][col - 1] = player_choice == 1 ? PLR1 : PLR2;
            print_board();
            if (has_won(player_choice == 1 ? PLR1 : PLR2)) {
                printf("Congratulations! Player %c has won the game.\n", player_choice == 1 ? PLR1 : PLR2);
                break;
            }
        } else { //AI's turn
            printf("AI is thinking...\n");
            int ai_row, ai_col;
            get_ai_move(&ai_row, &ai_col);
            board[ai_row][ai_col] = PLR1;
            print_board();
            if (has_won(PLR1)) {
                printf("AI has won the game.\n");
                break;
            }
        }
        turn++;
        if (turn == 9) { //board is full
            printf("The game is a tie.\n");
            break;
        }
    }
    return 0;
}