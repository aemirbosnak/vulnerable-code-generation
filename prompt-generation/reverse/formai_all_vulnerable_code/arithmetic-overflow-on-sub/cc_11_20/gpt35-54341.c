//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int size = 5; //size can be changed according to user preference
    int rows = size + 1; //additional row for reference numbers
    int cols = size + 1; //additional column for reference numbers
    int board[size][size]; //board array to store game values
    int i,j;

    //initialize board values to 0
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            board[i][j] = 0;
        }
    }

    //print column reference numbers
    printf("\n  ");
    for(i=1;i<=size;i++){
        printf("%2d ",i);
    }

    //print top border of table
    printf("\n  +");
    for(i=0;i<size;i++){
        printf("--+");
    }

    //print game board values with row reference numbers
    for(i=0;i<size;i++){
        printf("\n%2d|",i+1);
        for(j=0;j<size;j++){
            printf("%2d|",board[i][j]);
        }
        printf("\n  +");
        for(j=0;j<size;j++){
            printf("--+");
        }
    }

    //generate random row and column values for player to guess
    srand(time(NULL)); //initialize random seed
    int randomRow = rand() % size;
    int randomCol = rand() % size;

    int guessRow, guessCol; //initialize variables for player's guess

    //loop for player to make guesses until correct
    do{
        //get player's guess values
        printf("\nEnter row and column values to guess: ");
        scanf("%d %d",&guessRow,&guessCol);

        //check if guess is correct
        if(guessRow-1==randomRow && guessCol-1==randomCol){
            printf("\nCongratulations! You guessed correctly.\n");
            break;
        }
        else{
            //update board with X for incorrect guess
            printf("\nSorry, that guess was incorrect. Please try again.\n");
            board[guessRow-1][guessCol-1] = 'X';

            //print updated game board
            printf("\n  ");
            for(i=1;i<=size;i++){
                printf("%2d ",i);
            }
            printf("\n  +");
            for(i=0;i<size;i++){
                printf("--+");
            }
            for(i=0;i<size;i++){
                printf("\n%2d|",i+1);
                for(j=0;j<size;j++){
                    printf("%2c|",board[i][j]);
                }
                printf("\n  +");
                for(j=0;j<size;j++){
                    printf("--+");
                }
            }
        }

    }while(1);

    return 0;
}