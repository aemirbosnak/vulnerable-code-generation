//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define DEBUG 0

void clearScreen(){
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void printGrid(int grid[SIZE][SIZE]){
    clearScreen();
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(grid[i][j]==0){
                printf("░ ");
            }
            else{
                printf("█ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void percolate(int grid[SIZE][SIZE]){
    int flag = 1;
    while(flag){
        flag=0;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(grid[i][j]==1){
                    if(i>0 && grid[i-1][j]==0){
                        grid[i-1][j]=1;
                        flag=1;
                    }
                    if(i<SIZE-1 && grid[i+1][j]==0){
                        grid[i+1][j]=1;
                        flag=1;
                    }
                    if(j>0 && grid[i][j-1]==0){
                        grid[i][j-1]=1;
                        flag=1;
                    }
                    if(j<SIZE-1 && grid[i][j+1]==0){
                        grid[i][j+1]=1;
                        flag=1;
                    }
                }
            }
        }
        if(DEBUG){
            printGrid(grid);
        }
    }
}

int main(){
    int grid[SIZE][SIZE];
    srand(time(NULL));
    int count = 0;
    int p;
    printf("Enter probability of percolation in percentage (0-100): ");
    scanf("%d",&p);
    while(p<0 || p>100){
        printf("Invalid input. Enter probability of percolation in percentage (0-100): ");
        scanf("%d",&p);
    }
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            int randNum = rand()%100;
            if(randNum<p){
                grid[i][j]=1;
                count++;
            }
            else{
                grid[i][j]=0;
            }
        }
    }

    printGrid(grid);

    printf("Press any key to percolate...");
    getchar();
    getchar();

    percolate(grid);

    printf("Percolation complete.\n");
    printf("%d cells percolated.\n",count);
    printGrid(grid);

    return 0;
}