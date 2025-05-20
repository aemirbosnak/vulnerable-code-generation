//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// function to check if the game is over and who won
int check_game_over(int board[]) {
    // check for a horizontal win
    if((board[0] == board[1] && board[1] == board[2] && board[2] != 0) ||
       (board[3] == board[4] && board[4] == board[5] && board[5] != 0) ||
       (board[6] == board[7] && board[7] == board[8] && board[8] != 0)) {
        return board[0];
    }
    // check for a vertical win
    else if((board[0] == board[3] && board[3] == board[6] && board[6] != 0) ||
            (board[1] == board[4] && board[4] == board[7] && board[7] != 0) ||
            (board[2] == board[5] && board[5] == board[8] && board[8] != 0)) {
        return board[0];
    }
    // check for a diagonal win
    else if((board[0] == board[4] && board[4] == board[8] && board[8] != 0) ||
            (board[2] == board[4] && board[4] == board[6] && board[6] != 0)) {
        return board[0];
    }
    // check if the board is full and there is no winner
    else if(board[0] != 0 && board[1] != 0 && board[2] != 0 &&
            board[3] != 0 && board[4] != 0 && board[5] != 0 &&
            board[6] != 0 && board[7] != 0 && board[8] != 0) {
        return 3;
    }
    // game is not over yet
    else {
        return 0;
    }
}

// function to check if a move is valid
int check_valid_move(int board[], int move) {
    if(board[move] == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

// function to make the AI move
int ai_move(int board[]) {
    int move;
    // check if the AI can win
    for(int i = 0; i < 9; i++) {
        int copy_board[9];
        for(int j = 0; j < 9; j++) {
            copy_board[j] = board[j];
        }
        if(check_valid_move(copy_board, i)) {
            copy_board[i] = 2;
            if(check_game_over(copy_board) == 2) {
                return i;
            }
        }
    }
    // check if the player can win
    for(int i = 0; i < 9; i++) {
        int copy_board[9];
        for(int j = 0; j < 9; j++) {
            copy_board[j] = board[j];
        }
        if(check_valid_move(copy_board, i)) {
            copy_board[i] = 1;
            if(check_game_over(copy_board) == 1) {
                return i;
            }
        }
    }
    // if no winning move, make a random move
    do {
        move = rand() % 9;
    } while(!check_valid_move(board, move));
    return move;
}

// function to print the current state of the board
void print_board(int board[]) {
    printf("\n %c | %c | %c\n", (board[0] == 1) ? 'X' : ((board[0] == 2) ? 'O' : ' '), (board[1] == 1) ? 'X' : ((board[1] == 2) ? 'O' : ' '), (board[2] == 1) ? 'X' : ((board[2] == 2) ? 'O' : ' '));
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", (board[3] == 1) ? 'X' : ((board[3] == 2) ? 'O' : ' '), (board[4] == 1) ? 'X' : ((board[4] == 2) ? 'O' : ' '), (board[5] == 1) ? 'X' : ((board[5] == 2) ? 'O' : ' '));
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", (board[6] == 1) ? 'X' : ((board[6] == 2) ? 'O' : ' '), (board[7] == 1) ? 'X' : ((board[7] == 2) ? 'O' : ' '), (board[8] == 1) ? 'X' : ((board[8] == 2) ? 'O' : ' '));
}

int main() {
    int board[9] = {0,0,0,0,0,0,0,0,0}; // initialize the board to empty
    int player = 1; // player starts first
    int winner = 0; // winner: 0 = ongoing, 1 = player1, 2 = player2
    int move;
    while(winner == 0) {
        print_board(board);
        printf("Player %d, enter a move (0-8): ", player);
        scanf("%d", &move);
        if(check_valid_move(board, move)) {
            board[move] = player;
            winner = check_game_over(board);
            if(winner != 0) {
                break;
            }
            if(player == 1) {
                player = 2;
            }
            else {
                player = 1;
            }
        }
        else {
            printf("Invalid move, please try again.\n");
        }
        move = ai_move(board);
        printf("AI moves: %d\n", move);
        board[move] = player;
        winner = check_game_over(board);
        if(player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    }
    print_board(board);
    if(winner == 1) {
        printf("Congratulations, you win!\n");
    }
    else if(winner == 2) {
        printf("Sorry, you lose!\n");
    }
    else {
        printf("It's a tie!\n");
    }
    return 0;
}