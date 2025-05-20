//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char board[3][3];
char player = 'X';
char computer = 'O';
int moves = 0;

void initialize_board() { //initializes the board as empty
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() { //prints the current state of the board
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() { //checks for a winner in the current state of the board
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            if(board[i][0] == player) return 1;
            else if(board[i][0] == computer) return 2;
        }
    }
    for(int j = 0; j < 3; j++) {
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            if(board[0][j] == player) return 1;
            else if(board[0][j] == computer) return 2;
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        if(board[0][0] == player) return 1;
        else if(board[0][0] == computer) return 2;
    }
    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        if(board[0][2] == player) return 1;
        else if(board[0][2] == computer) return 2;
    }
    return 0;
}

int user_move() { //updates the board with the user move and checks for the winner
    int x,y;
    printf("Enter the row and column number of cell you want to place your move: ");
    scanf("%d %d",&x,&y);
    if(board[x-1][y-1] != '-') {
        printf("Invalid move, please try again.\n");
        return user_move();
    } else {
        board[x-1][y-1] = player;
        return check_winner();
    }
}

void computer_move() { //updates the board with the computer's move and checks for the winner
    int x,y;
    do {
        srand(time(NULL));
        x = rand() % 3;
        y = rand() % 3;
    } while(board[x][y] != '-');
    board[x][y] = computer;
    printf("Computer made its move.\n");
    check_winner();
}

int main() {
    initialize_board();
    printf("Welcome to TicTacToe!\n");
    printf("You will be playing against the computer.\n");
    printf("You will be playing with X and the computer will be playing with O.\n");
    printf("To make a move, enter the row and column number of the cell where you want to place your X.\n");
    print_board();

    while(1) {
        int result = user_move();
        moves++;
        print_board();
        if(result == 1) {
            printf("Congratulations! You won!\n");
            break;
        } else if(result == 2) {
            printf("Sorry, you lost. Better luck next time!\n");
            break;
        } else if(moves == 9) {
            printf("It's a tie!\n");
            break;
        }
        computer_move();
        moves++;
        print_board();
        result = check_winner();
        if(result == 1) {
            printf("Congratulations! You won!\n");
            break;
        } else if(result == 2) {
            printf("Sorry, you lost. Better luck next time!\n");
            break;
        } else if(moves == 9) {
            printf("It's a tie!\n");
            break;
        }
    }

    return 0;
}