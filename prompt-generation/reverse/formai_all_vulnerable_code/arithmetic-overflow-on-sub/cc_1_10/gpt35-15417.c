//FormAI DATASET v1.0 Category: Game ; Style: genious
#include<stdio.h>

void printBanner(int);
void createGameboard(char [3][3], int);
void takeTurn(int, int, char [3][3], int);
int checkWin(char [3][3]);

int main(){
    int currentPlayer = 1;
    int numMoves = 0;
    char gameboard[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    printBanner(currentPlayer);
    createGameboard(gameboard, numMoves);
    while(numMoves < 9){
        int row, col;
        printf("\nPlayer %d, it's your turn!\n", currentPlayer);
        printf("Enter row number (1-3): ");
        scanf("%d", &row);
        printf("Enter column number (1-3): ");
        scanf("%d", &col);
        takeTurn(row-1, col-1, gameboard, currentPlayer);
        createGameboard(gameboard, numMoves);
        if(checkWin(gameboard)){
            printf("\n\nPlayer %d wins!\n\n", currentPlayer);
            return 0;
        }
        numMoves++;
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
    printf("\n\nIt's a tie!\n\n");
    return 0;
}

void printBanner(int player){
    printf(" _____ _   _ _____ __  __ _   _ ______ _____  \n");
    printf("|_   _| \\ | |_   _|  \\/  | \\ | |  ____|  __ \\ \n");
    printf("  | | |  \\| | | | | \\  / |  \\| | |__  | |__) |\n");
    printf("  | | | . ` | | | | |\\/| | . ` |  __| |  _  / \n");
    printf(" _| |_| |\\  |_| |_|  |  | |\\  | |____| | \\ \\ \n");
    printf("|_____|_| \\_|_____|_|  |_| \\_|______|_|  \\_\\\n\n\n");
    printf("Player %d, you are X's.\n", player);
    printf("Player %d, you are O's.\n", (player == 1) ? 2 : 1);
}

void createGameboard(char gameboard[3][3], int numMoves){
    printf("\nNumber of Moves: %d\n", numMoves);
    printf("    1   2   3\n");
    printf("  +---+---+---+\n");
    for(int i=0; i<3; i++){
        printf("%d ", i+1);
        for(int j=0; j<3; j++){
            printf("| %c ", gameboard[i][j]);
        }
        printf("|\n");
        printf("  +---+---+---+\n");
    }
}

void takeTurn(int row, int col, char gameboard[3][3], int player){
    gameboard[row][col] = (player == 1) ? 'X' : 'O';
}

int checkWin(char gameboard[3][3]){
    for(int i=0; i<3; i++){
        // Check rows
        if(gameboard[i][0] == gameboard[i][1] && gameboard[i][1] == gameboard[i][2] && gameboard[i][0] != ' '){
            return 1;
        }
        // Check columns
        if(gameboard[0][i] == gameboard[1][i] && gameboard[1][i] == gameboard[2][i] && gameboard[0][i] != ' '){
            return 1;
        }
    }
    // Check diagonals
    if(gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2] && gameboard[0][0] != ' '){
        return 1;
    }
    if(gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0] && gameboard[0][2] != ' '){
        return 1;
    }
    return 0;
}