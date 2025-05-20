//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player1,player2,dice1,dice2,sum1=0,sum2=0,i;
    char playagain;

    srand(time(NULL));

    do
    {
        printf("\nPlayer 1: ");
        scanf("%d",&player1);
        printf("\nPlayer 2: ");
        scanf("%d",&player2);

        for(i=1;i<=3;i++)
        {
            dice1=rand()%6+1;
            dice2=rand()%6+1;

            sum1+=dice1;
            sum2+=dice2;

            printf("\nRound %d\n",i);
            printf("Player 1 rolled: %d\n",dice1);
            printf("Player 2 rolled: %d\n",dice2);

            if(sum1>sum2)
            {
                printf("\nPlayer 1 wins this round!\n");
            }
            else if(sum2>sum1)
            {
                printf("\nPlayer 2 wins this round!\n");
            }
            else
            {
                printf("\nIt's a tie!\n");
            }
        }

        printf("\nDo you want to play again(y/n): ");
        scanf(" %c",&playagain);

    }while(playagain=='y'||playagain=='Y');

    return 0;
}