//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: futuristic
//This is a high-level example of a Tic Tac Toe AI program in C.

#include <stdio.h>

int main() 
{
    //Initialize the game board as a 3x3 array
    char board[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    //Assign random weights to each empty slot on the board.
    //The scores will be a value between -100 and 100, which will be used to determine the AI's move.
    int scores[3][3] = {
        {-10, 5, -10},
        {5, 10, 5},
        {-10, 5, -10}
    };

    int winner = 0; //0 if no winner yet, 1 if player wins, 2 if AI wins.
    int player = 1; //1 if player, 2 if AI.
    int move; //Player or AI move.
    int i, j, k; //Loop variables.

    while (winner == 0) {
        //Player's turn
        if (player == 1) {
            printf("Enter your move (1-9): ");
            scanf("%d", &move);
            //Update the board with player's move
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == move + '0') {
                        board[i][j] = 'X';
                        scores[i][j] = -100; //Mark the slot as bad
                    }
                }
            }
            player = 2; //Switch to AI's turn.
        }
        //AI's turn
        else {
            int max_score = -1000; //Initialize to an arbitrary low value.
            int best_move = 0;
            //Check all empty slots and their scores, find the slot with the highest score.
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] != 'X' && board[i][j] != 'O') {
                        if (scores[i][j] > max_score) {
                            max_score = scores[i][j];
                            best_move = board[i][j] - '0';
                        }
                    }
                }
            }
            //Update the board with AI's move
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == best_move + '0') {
                        board[i][j] = 'O';
                        scores[i][j] = 100; //Mark the slot as good.
                    }
                }
            }
            printf("AI chooses %d\n", best_move);
            player = 1; //Switch to player's turn.
        }
        //Print the current state of the board.
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        //Check if someone has won or if the game has ended in a tie.
        //Horizontal wins
        for (i = 0; i < 3; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                if (board[i][0] == 'X')
                    winner = 1;
                else if (board[i][0] == 'O')
                    winner = 2;
            }
        }
        //Vertical wins
        for (j = 0; j < 3; j++) {
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                if (board[0][j] == 'X')
                    winner = 1;
                else if (board[0][j] == 'O')
                    winner = 2;
            }
        }
        //Diagonal wins
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'X')
                winner = 1;
            else if (board[0][0] == 'O')
                winner = 2;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'X')
                winner = 1;
            else if (board[0][2] == 'O')
                winner = 2;
        }
        //Tie game
        int tie = 1;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    tie = 0;
            }
        }
        if (tie == 1) {
            winner = 3;
        }
    }
    //Print the winner.
    if (winner == 1)
        printf("Player wins!\n");
    else if (winner == 2)
        printf("AI wins!\n");
    else if (winner == 3)
        printf("Tie game!\n");

    return 0;
}