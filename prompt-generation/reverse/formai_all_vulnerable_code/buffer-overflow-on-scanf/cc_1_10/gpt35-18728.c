//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>

// function to display the tic tac toe board
void display_board(char board[][3]) {
    printf("\n-------------\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n-------------\n");
    }
}

// function to check if the game has been won
int check_win(char board[][3], char player) {
    int i, j;
    // checking rows
    for(i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // checking columns
    for(j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // checking diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// function to check if the game has been drawn
int check_draw(char board[][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// function to make the move for the AI
void make_move(char board[][3], char ai) {
    // check if AI can win in the next move
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = ai;
                if(check_win(board, ai)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // check if player can win in the next move and block them
    char player = (ai == 'X') ? 'O' : 'X';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = player;
                if(check_win(board, player)) {
                    board[i][j] = ai;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // make a random move
    int i, j;
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while(board[i][j] != ' ');
    board[i][j] = ai;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char player, ai;
    printf("Do you want to play as X or O? ");
    scanf("%c", &player);
    ai = (player == 'X') ? 'O' : 'X';
    // play until the game is won or drawn
    while(!check_win(board, player) && !check_win(board, ai) && !check_draw(board)) {
        if(player == 'X') {
            int x, y;
            printf("Enter the x and y coordinates (0-2) of your move: ");
            scanf("%d %d", &x, &y);
            if(board[x][y] == ' ') {
                board[x][y] = player;
            } else {
                printf("Invalid move! Try again.\n");
                continue;
            }
        } else {
            make_move(board, ai);
        }
        display_board(board);
        if(check_win(board, player)) {
            printf("Congratulations! You have won the game.\n");
        } else if(check_win(board, ai)) {
            printf("Sorry, you lost. Better luck next time.\n");
        }
    }
    if(check_draw(board)) {
        printf("Game drawn!\n");
    }
    return 0;
}