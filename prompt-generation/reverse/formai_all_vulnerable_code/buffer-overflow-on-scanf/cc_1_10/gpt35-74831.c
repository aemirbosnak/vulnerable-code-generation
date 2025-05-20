//FormAI DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printTable(char table[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf(" %c ", table[i][j]);
            if(j<2) {
                printf("|");
            }
        }
        printf("\n");
        if(i<2) {
            printf("-----------\n");
        }
    }
}

char checkWin(char table[3][3]) {
    for(int i=0; i<3; i++) {
        if(table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != ' ') {
            return table[i][0];
        }
        if(table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != ' ') {
            return table[0][i];
        }
    }
    if(table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != ' ') {
        return table[0][0];
    }
    if(table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != ' ') {
        return table[0][2];
    }
    return ' ';
}

int main() {
    char table[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    char winner = ' ';
    int row, col;
    
    srand(time(NULL));
    int turns = rand() % 2;
    if(turns == 0) {
        printf("Player X goes first!\n");
    } else {
        printf("Player O goes first!\n");
        player = 'O';
    }
    
    while(winner == ' ') {
        printTable(table);
        printf("Turn: Player %c\n", player);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input. Row and column must be between 1 and 3.\n");
        } else if(table[row-1][col-1] != ' ') {
            printf("Invalid move. Cell already occupied.\n");
        } else {
            table[row-1][col-1] = player;
            winner = checkWin(table);
            if(player == 'X') {
                player = 'O';
            } else {
                player = 'X';
            }
        }
    }
    printTable(table);
    printf("Player %c wins!\n", winner);
    
    return 0;
}