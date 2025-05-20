//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 3
#define MAX_MOVES 9

char TTT[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };

void printBoard() {
    printf("-------------\n");
    printf("| %c | %c | %c |\n", TTT[0][0], TTT[0][1], TTT[0][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", TTT[1][0], TTT[1][1], TTT[1][2]);
    printf("-------------\n");
    printf("| %c | %c | %c |\n", TTT[2][0], TTT[2][1], TTT[2][2]);
    printf("-------------\n");
}

int isMoveLegal(int row, int col) {
    if(TTT[row][col] == ' ')
        return 1;
    return 0;
}

int didSomeoneWin() {
    if(TTT[0][0] == TTT[0][1] && TTT[0][0] == TTT[0][2] && TTT[0][0] != ' ')
        return 1;
    if(TTT[1][0] == TTT[1][1] && TTT[1][0] == TTT[1][2] && TTT[1][0] != ' ')
        return 1;
    if(TTT[2][0] == TTT[2][1] && TTT[2][0] == TTT[2][2] && TTT[2][0] != ' ')
        return 1;
    if(TTT[0][0] == TTT[1][0] && TTT[0][0] == TTT[2][0] && TTT[0][0] != ' ')
        return 1;
    if(TTT[0][1] == TTT[1][1] && TTT[0][1] == TTT[2][1] && TTT[0][1] != ' ')
        return 1;
    if(TTT[0][2] == TTT[1][2] && TTT[0][2] == TTT[2][2] && TTT[0][2] != ' ')
        return 1;
    if(TTT[0][0] == TTT[1][1] && TTT[0][0] == TTT[2][2] && TTT[0][0] != ' ')
        return 1;
    if(TTT[0][2] == TTT[1][1] && TTT[0][2] == TTT[2][0] && TTT[0][2] != ' ')
        return 1;
    return 0;
}

int getRand(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void AIMove() {
    int i, j;
    srand(time(0));
    do {
        i = getRand(0,2);
        j = getRand(0,2);
    } while(!isMoveLegal(i,j));
    TTT[i][j] = 'O';
    printf("The AI made its move!\n");
}

int main() {
    int i, j, r, c, playerTurn = 1, moveCounter = 0;
    char p;

    printf("*** Welcome to Tic Tac Toe ***\n");
    printf("You are X, AI is O.\n");
    printf("Get three in a row to win!\n");
    printf("Good luck!\n");

    printBoard();

    while(!didSomeoneWin() && moveCounter < MAX_MOVES) { 
        if(playerTurn) {
            printf("Please enter your move in row, column format (e.g. 2,1): ");
            scanf("%d,%d", &r, &c);
            if(isMoveLegal(r,c)) {
                TTT[r][c] = 'X';
                playerTurn = 0;
                printf("You made your move!\n");
            } else {
                printf("Invalid move! Please try again.\n");
            }
        } else {
            AIMove();
            playerTurn = 1;
        }
        printBoard();
        moveCounter++;
    }
    if(didSomeoneWin())
        printf("%s wins!\n", (playerTurn ? "AI" : "Player"));
    else
        printf("It's a tie!\n");
    return 0;
}