//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: all-encompassing
// Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the board
void display(char board[]) {
    printf("\n\n\t\t\t Tic Tac Toe\n\n");
    printf("\t Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);

    printf("\t_____|_____|_____\n");
    printf("\t     |     |     \n");

    printf("\t  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);

    printf("\t     |     |     \n");
}

// Function to check if the board is full
int check_board_full(char board[]) {
    for (int i = 1; i < 10; i++) {
        if (board[i] == ' ')
            return 0;
    }
    return 1;
}

// Function for the AI move
int ai_move(char board[], char player_char, char ai_char) {
    int flag = 0, move;
    if (board[5] == ' ') {
        board[5] = ai_char;
        flag = 1;
    }
    else {
        if (board[1] == ' ') {
            board[1] = ai_char;
            flag = 1;
        }
        else if (board[3] == ' ') {
            board[3] = ai_char;
            flag = 1;
        }
        else if (board[7] == ' ') {
            board[7] = ai_char;
            flag = 1;
        }
        else if (board[9] == ' ') {
            board[9] = ai_char;
            flag = 1;
        }
    }

    // If AI hasn't got a right move yet, loop this section until AI gets a correct move
    while (!flag) {
        srand((unsigned)time(NULL)); // Seed with current time
        move = rand() % 9 + 1; // Random move between 1-9
        if (board[move] == ' ') {
            board[move] = ai_char;
            flag = 1;
        }
    }

    return 1;
}

// Function to check if the game is over
int game_over(char board[], char player_char, char ai_char) {
    for (int i = 1; i <= 7; i += 3) {
        if ((board[i] == player_char && board[i + 1] == player_char && board[i + 2] == player_char) ||
            (board[i] == ai_char && board[i + 1] == ai_char && board[i + 2] == ai_char))
            return 1;
    }

    for (int i = 1; i <= 3; i++) {
        if ((board[i] == player_char && board[i + 3] == player_char && board[i + 6] == player_char) ||
            (board[i] == ai_char && board[i + 3] == ai_char && board[i + 6] == ai_char))
            return 1;
    }

    if ((board[1] == player_char && board[5] == player_char && board[9] == player_char) ||
        (board[1] == ai_char && board[5] == ai_char && board[9] == ai_char))
        return 1;

    if ((board[3] == player_char && board[5] == player_char && board[7] == player_char) ||
        (board[3] == ai_char && board[5] == ai_char && board[7] == ai_char))
        return 1;

    if (check_board_full(board))
        return 2;

    return 0;
}

int main() {
    char board[10] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char player_char, ai_char;
    int player_turn, game_status;
    printf("\n===============================\n");
    printf("Welcome to the Tic Tac Toe game!\n");
    printf("===============================\n");
    printf("Do you want to play as 'X' or 'O'?\n");
    printf("Choice (X or O): ");
    scanf(" %c", &player_char);

    if(player_char == 'X')
      ai_char = 'O';
    else if(player_char == 'O')
      ai_char = 'X';
    
    // Randomly choose who goes first
    srand((unsigned)time(NULL));
    player_turn = rand() % 2;
    if(player_turn == 0)
      printf("\nThe AI goes first!\n");
    else 
      printf("\nYou will go first!\n");
    
    
    // Loop through the game until it's over
    while (1) {
        if (player_turn == 0) {
            ai_move(board, player_char, ai_char);
            display(board);
        }
        else {
            int player_move;
            printf("\nWhat is your move?\nEnter a number from the board above: ");
            scanf(" %d", &player_move);
            if (board[player_move] == ' ') {
                board[player_move] = player_char;
                display(board);
            }
            else {
                printf("Invalid Move! Try again.");
                continue;
            }
        }

        game_status = game_over(board, player_char, ai_char);
        if (game_status == 1) {
            if (player_turn == 0) {
                printf("\nThe AI wins!\n");
            }
            else {
                printf("\nYou win!\n");
            }
            break;
        }
        else if (game_status == 2) {
            printf("\nThe game is a draw!\n");
            break;
        }

        player_turn = !player_turn; // Switch player turn
    }
    return 0;
}