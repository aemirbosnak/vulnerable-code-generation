//FormAI DATASET v1.0 Category: Memory Game ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 4
#define COLS 4

void displayBoard(char board[][COLS], int tries);
void populateBoard(char board[][COLS]);
void updateBoard(char board[][COLS], int row1, int col1, int row2, int col2);
int checkIfWon(char board[][COLS]);

int main()
{
    char board[ROWS][COLS];
    int tries = 0;
    int row1, col1, row2, col2;
    
    srand(time(NULL)); //set the random seed for generating random board
    
    populateBoard(board);
    
    do {
        displayBoard(board, tries);
        
        printf("Enter the row and column number of first card: ");
        scanf("%d %d", &row1, &col1);
        
        printf("Enter the row and column number of second card: ");
        scanf("%d %d", &row2, &col2);
        
        if(board[row1 - 1][col1 - 1] == board[row2 - 1][col2 - 1]){
            updateBoard(board, row1 - 1, col1 - 1, row2 - 1, col2 - 1);
        }
        else {
            system("clear"); //clear the console before displaying the message
            printf("\n\nOops! Cards do not match, Please try again! \n\n");
            tries++;
        }
        
    } while(checkIfWon(board) != 1);
    
    displayBoard(board, tries);
    printf("\n\nCongratulations! You have won!\n\n");
    
    return 0;
}

void populateBoard(char board[][COLS])
{
    int count = 1;
    
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(count > 8){
                count = 1;
            }
            board[i][j] = count + '0'; //convert the integer to character
            count++;
        }
    }
    
    //shuffle the cards randomly
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            int randRow = rand() % ROWS;
            int randCol = rand() % COLS;
            char temp = board[i][j];
            board[i][j] = board[randRow][randCol];
            board[randRow][randCol] = temp;
        }
    }
}

void displayBoard(char board[][COLS], int tries)
{
    system("clear"); //clear the console before displaying board
    
    printf("\n***WELCOME TO MEMORY GAME***\n\n");
    printf("\nNumber of tries: %d\n\n", tries);
    
    printf("    ");
    for(int i = 1; i <= COLS; i++){
        printf("%d   ", i);
    }
    
    printf("\n");
    
    for(int i = 0; i < ROWS; i++){
        printf(" %d  ", i + 1);
        for(int j = 0; j < COLS; j++){
            if(board[i][j] == 'X'){
                printf("%c   ", board[i][j]);
            }
            else {
                printf("*   ");
            }
        }
        printf("\n");
    }
    
    printf("\n");
}

void updateBoard(char board[][COLS], int row1, int col1, int row2, int col2)
{
    board[row1][col1] = 'X';
    board[row2][col2] = 'X';
}

int checkIfWon(char board[][COLS])
{
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(board[i][j] == '*'){
                return 0;
            }
        }
    }
    
    return 1;
}