//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
char player, computer;

void clear_board(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j] = ' ';
        }
    }
}

void draw_board(){
    printf("\n\t     1   2   3  \n");
    printf("\t   +---+---+---+\n");
    for(int i=0; i<3; i++){
        printf("\t%d ", i+1);
        for(int j=0; j<3; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n\t   +---+---+---+\n");
    }
}

int choose_first_player(){
    srand(time(NULL));
    int first = rand() % 2;
    if(first == 0){
        printf("\nYou will play first.\n");
        player = 'X';
        computer = 'O';
    } else {
        printf("\nThe computer will play first.\n");
        player = 'O';
        computer = 'X';
    }
    return first;
}

int player_move(){
    int row, col;
    do {
        printf("\nEnter your move (row column): ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
    } while(board[row][col] != ' ');
    board[row][col] = player;
    return row * 3 + col;
}

int computer_ai_move(){
    int move;
    // check for winning move
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' '){
                board[i][j] = computer;
                if(check_win() == 1){
                    move = i * 3 + j;
                    return move;
                }
                board[i][j] = ' ';
            }
        }
    }
    // check for blocking move
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' '){
                board[i][j] = player;
                if(check_win() == 1){
                    board[i][j] = computer;
                    return i * 3 + j;
                }
                board[i][j] = ' ';
            }
        }
    }
    // play in the center
    if(board[1][1] == ' '){
        move = 4;
        board[1][1] = computer;
        return move;
    }
    // play in random empty cell
    int empty_cells = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' '){
                empty_cells++;
            }
        }
    }
    srand(time(NULL));
    int random = rand() % empty_cells;
    int count = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] == ' '){
                if(count == random){
                    move = i * 3 + j;
                    board[i][j] = computer;
                    return move;
                } else {
                    count++;
                }
            }
        }
    }
}

int check_win(){
    // check rows
    for(int i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' '){
            return 1;
        }
    }
    // check columns
    for(int j=0; j<3; j++){
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' '){
            return 1;
        }
    }
    // check diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' '){
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' '){
        return 1;
    }
    return 0;
}

int main(){
    printf("\nWelcome to Tic Tac Toe!\n");
    printf("-----------------------\n");
    printf("Instructions:\n");
    printf("Enter the row and column number for your move.\n");
    printf("Rows and columns are numbered from 1 to 3.\n");
    printf("You will play as X and the computer will play as O.\n");
    int first = choose_first_player();
    clear_board();
    draw_board();
    int move, winner, turn = 0;
    while(1){
        if(turn % 2 == first){
            move = player_move();
        } else {
            move = computer_ai_move();
            printf("\nThe computer has played in row %d, column %d.\n", move/3+1, move%3+1);
        }
        draw_board();
        winner = check_win();
        if(winner == 1){
            if(turn % 2 == first){
                printf("\nCongratulations! You have won!\n");
            } else {
                printf("\nSorry, the computer has won. Better luck next time!\n");
            }
            break;
        } else if(turn == 8){
            printf("\nThe game is a tie.\n");
            break;
        }
        turn++;
    }
    return 0;
}