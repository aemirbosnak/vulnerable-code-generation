//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int i,j,k,l,count=0,arr[5][5];
    char ch;
    int player=1;
    int flag=0;
    int choice;
    int num;

    printf("Enter the number of players: ");
    scanf("%d",&num);

    for(i=0;i<num;i++)
    {
        if(i==0)
        {
            printf("\nPlayer 1's Turn\n");
        }
        else if(i==1)
        {
            printf("\nPlayer 2's Turn\n");
        }
        else
        {
            printf("\nPlayer %d's Turn\n",i+1);
        }

        do
        {
            printf("\nEnter your choice of number: ");
            scanf("%d",&choice);

            if(choice>=1 && choice<=15)
            {
                if(arr[i/2][choice-1]!=choice)
                {
                    arr[i/2][choice-1]=choice;
                    count++;
                }
                else
                {
                    printf("\nSorry! This number is already marked.\n");
                }
            }
            else
            {
                printf("\nInvalid choice! Please enter a number between 1 and 15.\n");
            }
        }
        while(count!=5);

        if(flag==0)
        {
            if(i%2==0)
            {
                for(j=0;j<3;j++)
                {
                    for(k=0;k<3;k++)
                    {
                        printf("%d ",arr[j][k]);
                    }
                    printf("\n");
                }
            }
            else
            {
                for(l=0;l<3;l++)
                {
                    for(j=3;j<6;j++)
                    {
                        printf("%d ",arr[l][j]);
                    }
                    printf("\n");
                }
            }
        }

        flag=1;
        count=0;
    }

    if(player%2==0)
    {
        printf("\nPlayer 1 wins!\n");
    }
    else
    {
        printf("\nPlayer 2 wins!\n");
    }
}