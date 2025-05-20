//Falcon-180B DATASET v1.0 Category: Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,n,m,k,l,count=0,flag=0;
    int arr[10][10],temp[10][10];
    int player=1;
    int choice;
    int sum=0;

    printf("Player 1: X and Player 2: O\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&n,&m);

    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            arr[i][j]=rand()%2;
            if(arr[i][j]==1)
            {
                temp[i][j]=35;
            }
            else
            {
                temp[i][j]=46;
            }
        }
    }

    while(flag!=1)
    {
        system("clear");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%c",temp[i][j]);
            }
            printf("\n");
        }
        if(player==1)
        {
            printf("\nPlayer 1's Turn\n");
        }
        else
        {
            printf("\nPlayer 2's Turn\n");
        }
        printf("Enter your choice of row and column: ");
        scanf("%d%d",&k,&l);
        if(arr[k-1][l-1]!=0)
        {
            printf("Sorry the cell (%d,%d) is already marked with %c\n",k,l,arr[k-1][l-1]+48);
            getchar();
        }
        else
        {
            if(player==1)
            {
                arr[k-1][l-1]=1;
                temp[k-1][l-1]=35;
                count++;
                if(count==m*n)
                {
                    printf("\nPlayer 1 wins\n");
                    flag=1;
                }
            }
            else
            {
                arr[k-1][l-1]=2;
                temp[k-1][l-1]=46;
                count++;
                if(count==m*n)
                {
                    printf("\nPlayer 2 wins\n");
                    flag=1;
                }
            }
            player=player%2+1;
        }
    }

    return 0;
}