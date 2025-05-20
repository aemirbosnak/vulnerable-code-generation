//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_ROWS 5
#define MAX_BINGO_COLS 5

void printHeader(char *playerName);
void printBingoBoard(int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS]);
void fillBingoBoard(int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS]);
int checkBingo(int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS], int checkType);

int main() {
    char playerName[50];
    int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS];
    int gameRunning = 1;
    int gameStatus = 0; //0 = game in progress, 1 = bingo, 2 = tie
    
    srand(time(NULL));
    
    printHeader(playerName);
    fillBingoBoard(bingoBoard);
    
    while(gameRunning) {
        printBingoBoard(bingoBoard);
        
        int checkType;
        printf("Enter 1 to check for horizontal bingo,\n2 for vertical bingo or\n3 for diagonal bingo: ");
        scanf("%d", &checkType);
        
        gameStatus = checkBingo(bingoBoard, checkType);
        if(gameStatus == 1) {
            printf("BINGO! Congratulations %s, you win!\n", playerName);
            gameRunning = 0;
        } else if(gameStatus == 2) {
            printf("It's a tie.\n");
            gameRunning = 0;
        }
    }
    
    return 0;
}

void printHeader(char *playerName) {
    printf("Welcome to Paranoid Bingo Simulator!\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);
    printf("Welcome, %s, let's get started!\n", playerName);
}

void fillBingoBoard(int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS]) {
    for(int row=0; row<MAX_BINGO_ROWS; row++) {
        for(int col=0; col<MAX_BINGO_COLS; col++) {
            int randomNum = rand() % 15 + 1;
            while(randomNum == bingoBoard[row][col]) {
                randomNum = rand() % 15 + 1;
            }
            bingoBoard[row][col] = randomNum;
        }
    }
    
    //set middle square as free space
    bingoBoard[2][2] = 0;
}

void printBingoBoard(int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS]) {
    printf("\nB I N G O\n");
    for(int row=0; row<MAX_BINGO_ROWS; row++) {
        for(int col=0; col<MAX_BINGO_COLS; col++) {
            printf("%2d ", bingoBoard[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkBingo(int bingoBoard[MAX_BINGO_ROWS][MAX_BINGO_COLS], int checkType) {
    int sumRow, sumCol, sumDiag1, sumDiag2;
    int bingoFlag = 0;
    int tieCond = 0;
    
    switch(checkType) {
        case 1:
            //Horizontal Bingo
            for(int row=0; row<MAX_BINGO_ROWS; row++) {
                sumRow = 0;
                for(int col=0; col<MAX_BINGO_COLS; col++) {
                    sumRow += bingoBoard[row][col];
                }
                if(sumRow == 0) {
                    bingoFlag = 1;
                    break;
                } else if(sumRow > 0) {
                    tieCond = 1;
                }
            }
            break;
        case 2:
            //Vertical Bingo
            for(int col=0; col<MAX_BINGO_COLS; col++) {
                sumCol = 0;
                for(int row=0; row<MAX_BINGO_ROWS; row++) {
                    sumCol += bingoBoard[row][col];
                }
                if(sumCol == 0) {
                    bingoFlag = 1;
                    break;
                } else if(sumCol > 0) {
                    tieCond = 1;
                }
            }
            break;
        case 3:
            //Diagonal Bingo
            sumDiag1 = 0;
            for(int i=0; i<MAX_BINGO_ROWS; i++) {
                sumDiag1 += bingoBoard[i][i];
            }
            if(sumDiag1 == 0) {
                bingoFlag = 1;
                break;
            } else if(sumDiag1 > 0) {
                tieCond = 1;
            }
            sumDiag2 = 0;
            for(int i=0; i<MAX_BINGO_ROWS; i++) {
                sumDiag2 += bingoBoard[i][MAX_BINGO_ROWS-i-1];
            }
            if(sumDiag2 == 0) {
                bingoFlag = 1;
                break;
            } else if(sumDiag2 > 0) {
                tieCond = 1;
            }
            break;
        default:
            printf("Invalid choice. Please enter valid choice.\n");
    }
    
    if(bingoFlag == 1) {
        return 1;
    } else if(bingoFlag == 0 && tieCond == 0) {
        return 2;
    }
    
    return 0;
}