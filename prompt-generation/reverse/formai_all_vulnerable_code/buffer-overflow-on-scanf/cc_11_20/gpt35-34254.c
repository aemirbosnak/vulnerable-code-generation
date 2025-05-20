//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the game board
void display(char board[]) {
    printf("\n\n\tTIC TAC TOE\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", board[7], board[8], board[9]);
    printf("     |     |     \n\n");
}

// Function to check if a player has won
int check_win(char board[]) {
    if (board[1] == board[2] && board[2] == board[3])
        return 1;
    else if (board[4] == board[5] && board[5] == board[6])
        return 1;
    else if (board[7] == board[8] && board[8] == board[9])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[3] == board[6] && board[6] == board[9])
        return 1;
    else if (board[1] == board[5] && board[5] == board[9])
        return 1;
    else if (board[3] == board[5] && board[5] == board[7])
        return 1;
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' 
    && board[4] != '4' && board[5] != '5' && board[6] != '6' 
    && board[7] != '7' && board[8] != '8' && board[9] != '9')
        return 0;
    else
        return -1;
}

// Main function
int main() {
    char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int player = 1, i, move;
    char mark;
    do {
        display(board);
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter a number: ", player);
        scanf("%d", &move);
        mark = (player == 1) ? 'X' : 'O';
        if (move == 1 && board[1] == '1')
            board[1] = mark;
        else if (move == 2 && board[2] == '2')
            board[2] = mark;
        else if (move == 3 && board[3] == '3')
            board[3] = mark;
        else if (move == 4 && board[4] == '4')
            board[4] = mark;
        else if (move == 5 && board[5] == '5')
            board[5] = mark;
        else if (move == 6 && board[6] == '6')
            board[6] = mark;
        else if (move == 7 && board[7] == '7')
            board[7] = mark;
        else if (move == 8 && board[8] == '8')
            board[8] = mark;
        else if (move == 9 && board[9] == '9')
            board[9] = mark;
        else {
            printf("Invalid move ");
            player--;
            getchar();
        }
        i = check_win(board);
        player++;
    } while (i == -1);
    display(board);
    if (i == 1)
        printf("==> Player %d wins.", --player);
    else
        printf("==> Game draw.");
    getchar(); 
    return 0;
}