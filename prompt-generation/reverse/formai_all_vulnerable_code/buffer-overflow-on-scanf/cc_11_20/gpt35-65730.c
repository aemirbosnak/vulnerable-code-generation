//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

// Function to display the game board
void display_board(char board[]) {
    printf("\n");
    printf("\t %c | %c | %c \n",board[0],board[1],board[2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n",board[3],board[4],board[5]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n",board[6],board[7],board[8]);
    printf("\n");
}

// Function to check if the given player has won the game
int check_win(char board[], char player) {
    if ((board[0] == player && board[1] == player && board[2] == player) ||
        (board[3] == player && board[4] == player && board[5] == player) ||
        (board[6] == player && board[7] == player && board[8] == player) ||
        (board[0] == player && board[3] == player && board[6] == player) ||
        (board[1] == player && board[4] == player && board[7] == player) ||
        (board[2] == player && board[5] == player && board[8] == player) ||
        (board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player)) {
            return 1;
        }
    else {
        return 0;
    }
}

// Function to get the next move of the computer
int get_computer_move(char board[]) {
    int move = 0;

    // Check if the computer can win in the next move
    for (int i=0; i<9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            if (check_win(board, 'O')) {
                move = i+1;
                return move;
            }
            else {
                board[i] = ' ';
            }
        }
    }

    // Check if the player can win in the next move and block them
    for (int i=0; i<9; i++) {
        if (board[i] == ' ') {
            board[i] = 'X';
            if (check_win(board, 'X')) {
                move = i+1;
                board[i] = 'O';
                return move;
            }
            else {
                board[i] = ' ';
            }
        }
    }

    // If the center is empty, take it
    if (board[4] == ' ') {
        move = 5;
        return move;
    }

    // If the corners are available, take them
    if (board[0] == ' ') {
        move = 1;
        return move;
    }
    if (board[2] == ' ') {
        move = 3;
        return move;
    }
    if (board[6] == ' ') {
        move = 7;
        return move;
    }
    if (board[8] == ' ') {
        move = 9;
        return move;
    }

    // If there are no good moves left
    return 0;
}

int main() {

    int player_choice = 0;
    int computer_choice = 0;
    char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    // Display instructions
    printf("Welcome to Tic Tac Toe!\n");
    printf("To play, enter the number of the cell you want to place your X in (1-9).\n");
    printf("The computer will then make its move.\n");
    printf("If you get three X's in a row, you win!\n");
    printf("If the computer gets three O's in a row, you lose!\n");
    printf("\n");
    printf("You are X, computer is O.\n\n");

    // Loop through the game
    while (1) {
        display_board(board);

        // Get the player's input
        printf("Enter your move: ");
        scanf("%d",&player_choice);

        // Validate the player's input and make the move
        if (player_choice < 1 || player_choice > 9) {
            printf("Invalid choice. Please choose a number between 1 and 9.\n\n");
            continue;
        }
        if (board[player_choice-1] != ' ') {
            printf("That cell is already taken. Please choose another.\n\n");
            continue;
        }
        board[player_choice-1] = 'X';

        // Check if the player has won
        if (check_win(board, 'X')) {
            display_board(board);
            printf("Congratulations! You win!\n");
            break;
        }

        // Get the computer's move and make it
        computer_choice = get_computer_move(board);
        board[computer_choice-1] = 'O';
        printf("The computer chose cell %d.\n\n",computer_choice);

        // Check if the computer has won
        if (check_win(board, 'O')) {
            display_board(board);
            printf("Sorry, the computer wins. Better luck next time!\n");
            break;
        }

        // Check if the game is a tie
        int game_is_tie = 1;
        for (int i=0; i<9; i++) {
            if (board[i] == ' ') {
                game_is_tie = 0;
                break;
            }
        }
        if (game_is_tie) {
            display_board(board);
            printf("The game is a tie!\n");
            break;
        }
    }

    return 0;
}