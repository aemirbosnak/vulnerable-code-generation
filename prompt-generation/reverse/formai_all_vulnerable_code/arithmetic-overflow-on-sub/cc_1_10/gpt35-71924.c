//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// function to display the Tic Tac Toe board
void display_board() {
    printf("\n- Tic Tac Toe -\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);
    printf("     |     |     \n");
}

// function to make a move for the player
void player_move(char mark){
    int choice;
    printf("Enter the position you want to place your mark (1-9): ");
    scanf("%d", &choice);
    if(board[choice-1] == 'X' || board[choice-1] == 'O') {
        printf("Position already taken. Please try again.\n");
        player_move(mark);
    } else {
        board[choice-1] = mark;
    }
    display_board();
}

// function to check if the game is over
int check_game_over() {
    if(board[0] == board[1] && board[1] == board[2]) {
        return 1;
    } else if(board[3] == board[4] && board[4] == board[5]) {
        return 1;
    } else if(board[6] == board[7] && board[7] == board[8]) {
        return 1;
    } else if(board[0] == board[3] && board[3] == board[6]) {
        return 1;
    } else if(board[1] == board[4] && board[4] == board[7]) {
        return 1;
    } else if(board[2] == board[5] && board[5] == board[8]) {
        return 1;
    } else if(board[0] == board[4] && board[4] == board[8]) {
        return 1;
    } else if(board[2] == board[4] && board[4] == board[6]) {
        return 1;
    } else if(board[0] != '1' && board[1] != '2' && board[2] != '3' && 
        board[3] != '4' && board[4] != '5' && board[5] != '6' && 
        board[6] != '7' && board[7] != '8' && board[8] != '9') {
        return -1;
    } else {
        return 0;
    }
}

// function to make a move for the computer
void computer_move(char mark){
    int choice, i;
    char opponent_mark;
    if(mark == 'X') {
        opponent_mark = 'O';
    } else {
        opponent_mark = 'X';
    }

    // check if computer can win in next move
    for(i = 0; i < 9; i++) {
        if(board[i] == ' ') {
            board[i] = mark;
            if(check_game_over() == 1) {
                display_board();
                printf("Computer has placed a mark at position %d\n", i+1);
                return;
            } else {
                board[i] = ' ';
            }
        }
    }

    // check if opponent can win in next move and block it
    for(i = 0; i < 9; i++) {
        if(board[i] == ' ') {
            board[i] = opponent_mark;
            if(check_game_over() == 1) {
                board[i] = mark;
                display_board();
                printf("Computer has placed a mark at position %d\n", i+1);
                return;
            } else {
                board[i] = ' ';
            }
        }
    }

    // make a random move
    srand(time(NULL));
    do{
        choice = rand() % 9;
    }while(board[choice] == 'X' || board[choice] == 'O');
    board[choice] = mark;
    display_board();
    printf("Computer has placed a mark at position %d\n", choice+1);
}

int main(){
    int game_over;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: X\nPlayer 2: O\n\n");
    display_board();

    while(1) {
        // player 1 turn
        player_move('X');
        game_over = check_game_over();
        if(game_over != 0) {
            break;
        }

        // computer turn
        computer_move('O');
        game_over = check_game_over();
        if(game_over != 0) {
            break;
        }
    }

    if(game_over == 1) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Computer won. Better luck next time!\n");
    }

    return 0;
}