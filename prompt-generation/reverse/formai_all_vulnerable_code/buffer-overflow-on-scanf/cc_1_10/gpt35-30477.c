//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int check_board(int []);
void print_board(int []);
void play(int [], int);
void computer_play(int []);

int main()
{
    int board[9] = {0,0,0,0,0,0,0,0,0};
    int player;

    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Please choose a number from 1 to 9 to place your 'X'.\n\n");

    while(check_board(board) == 0) {
        printf("Player 1 (X):\n");
        player = 1;
        play(board, player);
        print_board(board);

        if(check_board(board) == 1) {
            break;
        }
        printf("Computer (O):\n");
        player = -1;
        computer_play(board);
        print_board(board);
    }

    if(check_board(board) == 1) {
        printf("Player 1 wins!");
    }
    else if(check_board(board) == -1) {
        printf("Computer wins!");
    }
    else {
        printf("Game ended in a tie.");
    }

    return 0;
}

int check_board(int board[])
{
    int i;

    // Check rows
    for(i=0; i<9; i+=3) {
        if(board[i] == board[i+1] && board[i] == board[i+2]) {
            if(board[i] == 1) {
                return 1;
            }
            else if(board[i] == -1) {
                return -1;
            }
        }
    }

    // Check columns
    for(i=0; i<3; i++) {
        if(board[i] == board[i+3] && board[i] == board[i+6]) {
            if(board[i] == 1) {
                return 1;
            }
            else if(board[i] == -1) {
                return -1;
            }
        }
    }

    // Check diagonals
    if(board[0] == board[4] && board[0] == board[8]) {
        if(board[0] == 1) {
            return 1;
        }
        else if(board[0] == -1) {
            return -1;
        }
    }
    if(board[2] == board[4] && board[2] == board[6]) {
        if(board[2] == 1) {
            return 1;
        }
        else if(board[2] == -1) {
            return -1;
        }
    }

    // Check if the game is a tie
    for(i=0; i<9; i++) {
        if(board[i] == 0) {
            return 0;
        }
    }

    return 2;
}

void print_board(int board[]) 
{
    int i;
    printf("\n");
    for(i=0; i<9; i++) {
        if(board[i] == 1) {
            printf(" X ");
        }
        else if(board[i] == -1) {
            printf(" O ");
        }
        else {
            printf("   ");
        }

        if(i == 2 || i == 5) {
            printf("\n-----------\n");
        }
        else if(i == 8) {
            printf("\n\n");
        }
        else {
            printf("|");
        }
    }
}

void play(int board[], int player)
{
    int position;
    scanf("%d", &position);

    while(position < 1 || position > 9 || board[position-1] != 0) {
        printf("\nInvalid input. Please choose a number from 1 to 9 to place your 'X'.\n");
        scanf("%d", &position);
    }

    board[position-1] = player;
}

void computer_play(int board[])
{
    int position, i;

    // Check if the computer can win
    for(i=0; i<9; i++) {
        if(board[i] == 0) {
            board[i] = -1;
            if(check_board(board) == -1) {
                return;
            }
            else {
                board[i] = 0;
            }
        }
    }

    // Check if the player can win
    for(i=0; i<9; i++) {
        if(board[i] == 0) {
            board[i] = 1;
            if(check_board(board) == 1) {
                board[i] = -1;
                return;
            }
            else {
                board[i] = 0;
            }
        }
    }

    // Otherwise, make a random move
    srand(time(NULL));

    do {
        position = rand() % 9;
    } while(board[position] != 0);

    board[position] = -1;
}