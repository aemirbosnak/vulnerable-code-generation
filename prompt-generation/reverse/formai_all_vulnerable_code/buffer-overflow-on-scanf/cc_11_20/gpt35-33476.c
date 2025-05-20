//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int isGameOver(char symb) {
    //Check if game is over
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == symb) {
            return 1;
        }
    }
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == symb) {
            return 1;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == symb) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == symb) {
        return 1;
    }
    return 0;
}

void displayBoard() {
    //Display board
    printf("\n   1   2   3\n");
    for(int i=0; i<3; i++) {
        printf(" %c ", 'A'+i);
        for(int j=0; j<3; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
}

int getPoints() {
    int points = 0;
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'O') {
            points += 10;
        }
    }
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'O') {
            points += 10;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O') {
        points += 10;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O') {
        points += 10;
    }
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'X') {
            points -= 10;
        }
    }
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'X') {
            points -= 10;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X') {
        points -= 10;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X') {
        points -= 10;
    }
    return points;
}

void AI_Plays(char symb) {
    //AI plays here
    int row = -1, col = -1, maxPoints = -100;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = symb;
                int points = getPoints();
                if(points > maxPoints) {
                    maxPoints = points;
                    row = i;
                    col = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    board[row][col] = symb;
}

int main() {
    printf("Welcome to Tic Tac Toe AI!\n");
    displayBoard();
    while(1) {
        printf("Enter Row and Column (eg. A1): ");
        char choice[3];
        scanf("%s", choice);
        int row = choice[0]-'A';
        int col = choice[1]-'1';
        if(board[row][col] == ' ') {
            board[row][col] = 'X';
        }
        else {
            printf("Invalid move, try again.\n");
            continue;
        }
        displayBoard();
        if(isGameOver('X')) {
            printf("Congratulations, you won!\n");
            break;
        }
        AI_Plays('O');
        displayBoard();
        if(isGameOver('O')) {
            printf("Sorry, you lost...\n");
            break;
        }
    }
    return 0;
}