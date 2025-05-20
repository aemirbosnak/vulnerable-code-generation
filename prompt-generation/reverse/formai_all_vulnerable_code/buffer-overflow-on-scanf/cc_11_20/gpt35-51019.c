//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to draw the playing board
void draw_board(int board[]) {
    system("clear");
    printf("\n\n\n\tTerminal Game | Retro Style\n\n");
    printf("\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[0], board[1], board[2]);
    printf("\t_____|_____|_____\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[3], board[4], board[5]);
    printf("\t_____|_____|_____\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c \n", board[6], board[7], board[8]);
    printf("\t     |     |     \n\n");
}

// Function to check if any player has won the game
int check_win(int board[]) {
    if (board[0] == board[1] && board[1] == board[2])
        return 1;
    else if (board[3] == board[4] && board[4] == board[5])
        return 1;
    else if (board[6] == board[7] && board[7] == board[8])
        return 1;
    else if (board[0] == board[3] && board[3] == board[6])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] == board[4] && board[4] == board[6])
        return 1;
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' &&
             board[3] != '4' && board[4] != '5' && board[5] != '6' &&
             board[6] != '7' && board[7] != '8' && board[8] != '9')
        return -1;
    else
        return 0;
}

// Main function
int main() {
    int player = 1, choice, result, board[9];
    char mark;
    time_t t;

    // Initialize random number generator
    srand((unsigned) time(&t));

    // Initialize the board
    for (int i = 0; i < 9; i++) {
        board[i] = '1' + i;
    }

    // Display the initial board
    draw_board(board);
    printf("\tInstructions:\n\t-------------\n");
    printf("\tType the number of the square where you want to place your mark.\n\n");

    // Loop until the game is over
    do {
        player = (player % 2) ? 1 : 2;

        // Generate a random delay to simulate computer player
        if (player == 2) {
            usleep((rand() % 3 + 1) * 1000000);
        }

        // Set the mark based on the current player
        mark = (player == 1) ? 'X' : 'O';

        // Prompt the player to make a move
        printf("\tPlayer %d, enter a number: ", player);
        scanf("%d", &choice);

        // Check if the player entered a valid choice
        if (choice < 1 || choice > 9) {
            printf("\tInvalid choice. Please try again.\n");
            player--;
            continue;
        }

        // Check if the chosen square is available
        if (board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            printf("\tThat square is already taken. Please try again.\n");
            player--;
            continue;
        }

        // Set the chosen square to the player's mark
        board[choice - 1] = mark;

        // Draw the updated board
        draw_board(board);

        // Check if the game is over
        result = check_win(board);

        player++;

    } while (result == 0);

    if (result == 1) {
        printf("\tPlayer %d wins!\n", --player);
    } else {
        printf("\tIt's a tie!\n");
    }

    return 0;
}