//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// function to print the game board
void print_board(char board[]){
    printf("\n");
    printf("\t\t\t%c | %c | %c\n", board[0], board[1], board[2]);
    printf("\t\t\t--|---|--\n");
    printf("\t\t\t%c | %c | %c\n", board[3], board[4], board[5]);
    printf("\t\t\t--|---|--\n");
    printf("\t\t\t%c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

// function to get player input and validate it
int get_input(char board[]){
    int choice, valid_choice = 0;
    do {
        printf("Enter a number (1-9) to make your move: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 9 && board[choice-1] == ' ') {
            valid_choice = 1;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (!valid_choice);
    return choice;
}

// function to check if the game has been won
int check_winner(char board[]){
    // check horizontal rows
    if ((board[0] == board[1] && board[1] == board[2] && board[0] != ' ') ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != ' ')) {
        return 1; // return 1 if the game has been won
    }
    // check vertical columns
    else if ((board[0] == board[3] && board[3] == board[6] && board[0] != ' ') ||
             (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') ||
             (board[2] == board[5] && board[5] == board[8] && board[2] != ' ')) {
        return 1; // return 1 if the game has been won
    }
    // check diagonal lines
    else if ((board[0] == board[4] && board[4] == board[8] && board[0] != ' ') ||
             (board[2] == board[4] && board[4] == board[6] && board[2] != ' ')) {
        return 1; // return 1 if the game has been won
    }
    // check if the game is a tie
    else if (board[0] != ' ' && board[1] != ' ' && board[2] != ' ' &&
             board[3] != ' ' && board[4] != ' ' && board[5] != ' ' &&
             board[6] != ' ' && board[7] != ' ' && board[8] != ' ') {
        return 2; // return 2 if the game is a tie
    }
    else {
        return 0; // return 0 if the game is not over yet
    }
}

int main(){
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int turn = 1, player = 1, winner = 0, choice;
    do {
        // clear the screen
        system("clear");
        // print the game board
        print_board(board);
        // get the player's move
        printf("Player %d's turn (X/O)\n", player);
        choice = get_input(board);
        // update the game board with the player's move
        if (player == 1) {
            board[choice-1] = 'X';
            player = 2;
        }
        else {
            board[choice-1] = 'O';
            player = 1;
        }
        // check if the game has been won
        winner = check_winner(board);
        turn++;
    } while (winner == 0);
    // clear the screen
    system("clear");
    // print the final game board
    print_board(board);
    // print the winner or tie message
    if (winner == 1) {
        printf("Player %d wins!\n", player);
    }
    else {
        printf("The game is a tie.\n");
    }
    return 0;
}