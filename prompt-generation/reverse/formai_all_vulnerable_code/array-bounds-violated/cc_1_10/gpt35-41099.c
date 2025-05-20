//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printBoard(char arr[][SIZE])
{
    printf("\t");
    for(int i=0;i<SIZE;i++) printf("%d\t",i+1);
    printf("\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d\t",i+1);
        for(int j=0;j<SIZE;j++)
        {
            printf("%c\t",arr[i][j]);
        }
        printf("\n");
    }
}

void shuffle(char arr[][SIZE])
{
    srand(time(NULL));
    char temp;
    int x1,y1,x2,y2;
    for(int i=0;i<100;i++)
    {
        x1=rand()%SIZE;
        y1=rand()%SIZE;
        x2=rand()%SIZE;
        y2=rand()%SIZE;
        temp=arr[x1][y1];
        arr[x1][y1]=arr[x2][y2];
        arr[x2][y2]=temp;
    }
}

void startGame(char arr[][SIZE])
{
    int count=0;
    char cur;
    char temp[5];
    int match=0,x1,y1,x2,y2;
    while(count<(SIZE*SIZE))
    {
        printf("Enter the coordinates of your first move (x y) \n");
        scanf("%d %d",&x1,&y1);
        x1-=1;
        y1-=1;
        if(arr[x1][y1]!=' ' && arr[x1][y1]!='*') printf("The selected cell is already revealed\n");
        else
        {
            arr[x1][y1]=temp[1];
            printf("Enter the coordinates of your second move (x y) \n");
            scanf("%d %d",&x2,&y2);
            x2-=1;
            y2-=1;
            if(arr[x2][y2]!=' ' && arr[x2][y2]!='*') printf("The selected cell is already revealed\n");
            else
            {
                arr[x2][y2]=temp[2];
                if(arr[x1][y1]==arr[x2][y2])
                {
                    printf("Match Found!!\n");
                    match++;
                    if(match==SIZE) 
                    {
                        printf("Congratulations! You won the game.\n");
                        return;
                    }
                }
                else
                {
                    printf("Oops! The cards do not match.\n");
                    arr[x1][y1]=' ';
                    arr[x2][y2]=' ';
                }
                count+=2;
                printBoard(arr);
            }
        }
    }
}

int main()
{
    char arr[SIZE][SIZE];
    char temp[5]={'A','B','C','D','E'};
    int count=0,x,y;
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            arr[i][j]=' ';
        }
    }
    while(count<(SIZE*SIZE))
    {
        x=rand()%SIZE;
        y=rand()%SIZE;
        if(arr[x][y]==' ')
        {
            arr[x][y]=temp[count/2];
            count++;
            arr[rand()%SIZE][rand()%SIZE]=temp[count/2];
            count++;
        }
    }
    shuffle(arr);
    printBoard(arr);
    printf("Let's Begin with the Game!\n");
    startGame(arr);
    return 0;
}