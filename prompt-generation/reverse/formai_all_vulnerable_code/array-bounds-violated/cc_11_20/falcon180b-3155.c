//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,j,k,l,m,n,o,num,count=0;
    char bingo[5][5]={{'B','I','N','G','O'}};
    int player[5][5];

    srand(time(0));

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            num=rand()%15+1;
            player[i][j]=num;
            printf("%d ",player[i][j]);
        }
        printf("\n");
    }

    int flag=0;

    while(1)
    {
        int x,y,p,q;
        char ch;
        system("clear");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(player[i][j]==0)
                {
                    printf(" %c ",bingo[i][j]);
                }
                else
                {
                    printf("%d ",player[i][j]);
                }
            }
            printf("\n");
        }

        if(flag==0)
        {
            printf("Enter the number called out by the organizer:\n");
            scanf("%d",&num);

            x=num/5;
            y=num%5;

            if(player[x][y]==num)
            {
                player[x][y]=0;
                count++;
            }

            system("clear");

            for(i=0;i<5;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(player[i][j]==0)
                    {
                        printf(" %c ",bingo[i][j]);
                    }
                    else
                    {
                        printf("%d ",player[i][j]);
                    }
                }
                printf("\n");
            }

            if(count==15)
            {
                printf("\n\nPlayer wins!!!\n");
                flag=1;
            }
        }

        if(flag==1)
        {
            break;
        }
    }

    return 0;
}