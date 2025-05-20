//FormAI DATASET v1.0 Category: Game ; Style: Romeo and Juliet
#include <stdio.h>

char board[3][3], player1 = 'X', player2 = 'O';

void print_board() {
    printf("-------------\n");
    for(int i=0; i<3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int check_winner() {
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == player1 || board[i][0] == player2)
                return 1;
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if(board[0][i] == player1 || board[0][i] == player2)
                return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == player1 || board[0][0] == player2)
            return 1;
    }
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if(board[2][0] == player1 || board[2][0] == player2)
            return 1;
    }
    return 0;
}

void play_game() {
    int row, column, count = 0, gameover = 0;
    while(!gameover) {
        printf("Player %c's turn - Enter row and column (1-3): ", count%2==0 ? player1 : player2);
        scanf("%d %d", &row, &column);
        if(board[row-1][column-1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[row-1][column-1] = count%2 == 0 ? player1 : player2;
        print_board();
        if(check_winner()){
            printf("Player %c wins!\n", count%2==0 ? player1 : player2);
            gameover = 1;
        }
        if(count == 8){
            printf("It's a tie!\n");
            gameover = 1;
        }
        count++;
    }
}

int main() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
    printf("Welcome to Tic-Tac-Toe\n");
    print_board();
    play_game();
    return 0;
}