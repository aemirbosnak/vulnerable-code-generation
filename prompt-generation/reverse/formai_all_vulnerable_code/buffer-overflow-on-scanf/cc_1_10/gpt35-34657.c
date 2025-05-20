//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; //the Tic Tac Toe board
char ai_char, player_char; //AI and player markers

//function to print the current state of the board
void print_board() {
    for(int i=0; i<3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i != 2) {
            printf("---|---|---\n");
        }
    }
}

//function to check if the given row, column, or diagonal is filled with one player marker
int check_win(char ch, int r1, int c1, int r2, int c2, int r3, int c3) {
    if(board[r1][c1] == ch && board[r2][c2] == ch && board[r3][c3] == ch) {
        return 1;
    }
    return 0;
}

//function to check if the game has been won
int check_gameover() {
    //check rows
    for(int i=0; i<3; i++) {
        if(check_win(player_char, i, 0, i, 1, i, 2)) {
            printf("Congratulations, you won!\n");
            return 1;
        }
        else if(check_win(ai_char, i, 0, i, 1, i, 2)) {
            printf("Sorry, the AI won. Better luck next time!\n");
            return 1;
        }
    }
    //check columns
    for(int i=0; i<3; i++) {
        if(check_win(player_char, 0, i, 1, i, 2, i)) {
            printf("Congratulations, you won!\n");
            return 1;
        }
        else if(check_win(ai_char, 0, i, 1, i, 2, i)) {
            printf("Sorry, the AI won. Better luck next time!\n");
            return 1;
        }
    }
    //check diagonals
    if(check_win(player_char, 0, 0, 1, 1, 2, 2)) {
        printf("Congratulations, you won!\n");
        return 1;
    }
    else if(check_win(ai_char, 0, 0, 1, 1, 2, 2)) {
        printf("Sorry, the AI won. Better luck next time!\n");
        return 1;
    }
    if(check_win(player_char, 0, 2, 1, 1, 2, 0)) {
        printf("Congratulations, you won!\n");
        return 1;
    }
    else if(check_win(ai_char, 0, 2, 1, 1, 2, 0)) {
        printf("Sorry, the AI won. Better luck next time!\n");
        return 1;
    }
    //check for draw
    int count = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                count++;
            }
        }
    }
    if(count == 0) {
        printf("It's a draw!\n");
        return 1;
    }
    return 0;
}

//function to get the player's move
void player_move() {
    int row, col;
    printf("Your move (row column): ");
    scanf("%d %d", &row, &col);
    if(row<1 || row>3 || col<1 || col>3 || board[row-1][col-1] != ' ') {
        printf("Invalid move, try again.\n");
        player_move();
    }
    else {
        board[row-1][col-1] = player_char;
    }
}

//function to get the AI's move
void ai_move() {
    printf("AI's move: ");
    //random move
    int rand_row = rand() % 3;
    int rand_col = rand() % 3;
    while(board[rand_row][rand_col] != ' ') {
        rand_row = rand() % 3;
        rand_col = rand() % 3;
    }
    board[rand_row][rand_col] = ai_char;
    printf("%d %d\n", rand_row+1, rand_col+1);
}

int main() {
    //initialize board
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
    //choose player marker
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose your marker (X/O): ");
    scanf("%c", &player_char);
    while(player_char != 'X' && player_char != 'O') {
        printf("Invalid marker, try again.\n");
        printf("Choose your marker (X/O): ");
        scanf("%c", &player_char);
    }
    ai_char = (player_char == 'X') ? 'O' : 'X';
    printf("You have chosen %c. Let's begin!\n", player_char);
    //play game
    while(!check_gameover()) {
        print_board();
        player_move();
        if(check_gameover()) {
            break;
        }
        printf("\n");
        ai_move();
        printf("\n");
    }
    print_board();
    return 0;
}