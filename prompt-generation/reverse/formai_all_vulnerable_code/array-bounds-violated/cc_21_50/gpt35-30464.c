//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int row, col, count, input_row, input_col;
    int mine[50][50] = {0};
    char reveal[50][50];
    int i, j;
    int gameover = 0;
    int num_of_mines;
    srand(time(NULL));  

    printf("--------------MINESWEEPER--------------\n");

    printf("Enter number of rows (<=50): ");
    scanf("%d", &row);
    printf("Enter number of columns (<=50): ");
    scanf("%d", &col);

    printf("Enter number of mines (<= %d): ", row * col - 1);
    scanf("%d", &num_of_mines);

    // place mines
    for(i=0; i<num_of_mines;){
        int r = rand() % row;
        int c = rand() % col;
        if(mine[r][c] != 1){
            mine[r][c] = 1;
            i++;
        }
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            reveal[i][j] = '_';
        }
    }

    printf("\n");
    printf("******** BOARD ********\n\n");

    for(i=0; i<row; i++){
        printf("   ");
        for(j=0; j<col; j++){
            printf("%d ", j+1);
        }
        printf("\n");

        printf("%d| ", i+1);

        for(j=0; j<col; j++){
            printf("%c ", reveal[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    while(!gameover){
        printf("Enter Cell row (1-%d) and column (1-%d): ", row, col);
        scanf("%d %d", &input_row, &input_col);

        if(mine[input_row-1][input_col-1] == 1){
            printf("\nBOOM!! You hit a mine\n");
            gameover = 1;
        }
        else{
            count = 0;
            if(input_row-2>=0 && mine[input_row-2][input_col-1]==1){
                count++;
            }
            if(input_row<=row-1 && mine[input_row][input_col-1]==1){
                count++;
            }
            if(input_col-2>=0 && mine[input_row-1][input_col-2]==1){
                count++;
            }
            if(input_col<=col-1 && mine[input_row-1][input_col]==1){
                count++;
            }
                    
            if(count<=0){
                reveal[input_row-1][input_col-1] = ' ';
            }
            else{
                reveal[input_row-1][input_col-1] = count + '0';
            }
            printf("\n");
            printf("******** BOARD ********\n\n");
            for(i=0; i<row; i++){
                printf("   ");
                for(j=0; j<col; j++){
                    printf("%d ", j+1);
                }
                printf("\n");

                printf("%d| ", i+1);

                for(j=0; j<col; j++){
                    printf("%c ", reveal[i][j]);
                }
                printf("\n");
            }

            int sum = 0;
            for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                    if(mine[i][j]==1){
                        if(reveal[i][j]=='_') sum++;
                    }
                }
            }

            if(sum==num_of_mines){
                printf("\nCONGRATULATIONS! You Won!!\n\n");
                gameover = 1;
            }
        }
    }

    return 0;
}