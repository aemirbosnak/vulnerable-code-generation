//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
void display_board(char board[]);
int check_winner(char board[]);
void take_player_input(char board[], int player);
void take_ai_input(char board[], int ai);
int calculate_best_move(char board[]);

#define BOARD_SIZE 9

int main() {

    char board[BOARD_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int current_player = 1;
    int winner = 0;
    int ai_player = 2;

    printf("Welcome to Tic Tac Toe!\n");
    display_board(board);
    printf("Player %d will go first.\n", current_player);

    while (winner == 0) {
        if (current_player == 1) {
            take_player_input(board, current_player);
            winner = check_winner(board);
            current_player++;
        }
        else {
            take_ai_input(board, ai_player);
            winner = check_winner(board);
            current_player--;
        }

        if (winner == 1) {
            printf("Player 1 wins! Congratulations!\n");
            display_board(board);
        }
        else if (winner == 2) {
            printf("The AI wins! Better luck next time!\n");
            display_board(board);
        }
        else if (winner == -1) {
            printf("The game ends in a tie!\n");
            display_board(board);
        }
    }

    return 0;
}

//Function to display the board
void display_board(char board[]) {
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n\n", board[6], board[7], board[8]);
}

//Function to check if a player has won the game
int check_winner(char board[]) {

    if (board[0] == board[1] && board[1] == board[2]) {
        return board[0] == 'X' ? 1 : 2;
    }
    else if (board[3] == board[4] && board[4] == board[5]) {
        return board[3] == 'X' ? 1 : 2;
    }
    else if (board[6] == board[7] && board[7] == board[8]) {
        return board[6] == 'X' ? 1 : 2;
    }
    else if (board[0] == board[3] && board[3] == board[6]) {
        return board[0] == 'X' ? 1 : 2;
    }
    else if (board[1] == board[4] && board[4] == board[7]) {
        return board[1] == 'X' ? 1 : 2;
    }
    else if (board[2] == board[5] && board[5] == board[8]) {
        return board[2] == 'X' ? 1 : 2;
    }
    else if (board[0] == board[4] && board[4] == board[8]) {
        return board[0] == 'X' ? 1 : 2;
    }
    else if (board[2] == board[4] && board[4] == board[6]) {
        return board[2] == 'X' ? 1 : 2;
    }

    //Check if game is over due to a tie
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return 0;
        }
    }

    return -1;
}

//Function to take input from player
void take_player_input(char board[], int player) {
    int input = 0;
    int valid_input = 0;

    while (!valid_input) {
        printf("Player %d, enter a number to place your 'X': ", player);
        scanf("%d", &input);

        if (input < 1 || input > 9) {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            continue;
        }
        if (board[input-1] == 'X' || board[input-1] == 'O') {
            printf("That space is already taken. Please choose a different space.\n");
            continue;
        }

        board[input-1] = 'X';
        valid_input = 1;
    }

    display_board(board);
}

//Function to take input from the AI
void take_ai_input(char board[], int ai) {
    int best_move = calculate_best_move(board);

    printf("The AI places an 'O' at position %d.\n", best_move+1);
    board[best_move] = 'O';

    display_board(board);
}

//Function to calculate the AI's best move
int calculate_best_move(char board[]) {
    
    int scores[BOARD_SIZE] = {0};

    //Check all possible moves
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            board[i] = 'O';
            scores[i] = -(calculate_best_move(board));
            board[i] = i+1+'0';
        }
    }

    //Find the best move
    int best_score = -100000;
    int best_move = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (scores[i] > best_score && board[i] != 'X' && board[i] != 'O') {
            best_score = scores[i];
            best_move = i;
        }
    }

    //Return the best move
    if (best_move == -1) {
        //If there is no best move, pick the first available space
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                best_move = i;
                break;
            }
        }
    }

    return best_move;
}