//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player,computer,result;
    int count_player=0,count_computer=0;
    int i,n;

    printf("Enter the number of rounds you want to play: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("\nRound %d Begins\n",i);
        printf("Choose between rock(1), paper(2) and scissors(3): ");
        scanf("%d",&player);

        //computer generates its choice randomly
        srand(time(0));
        computer=(rand()%3)+1;

        //game logic
        if(player==1 && computer==2)
        {
            printf("Computer chose paper. You lose this round!");
            count_computer++;
        }
        else if(player==2 && computer==3)
        {
            printf("Computer chose scissors. You lose this round!");
            count_computer++;
        }
        else if(player==3 && computer==1)
        {
            printf("Computer chose rock. You lose this round!");
            count_computer++;
        }
        else if(player==1 && computer==3)
        {
            printf("Computer chose scissors. You win this round!");
            count_player++;
        }
        else if(player==2 && computer==1)
        {
            printf("Computer chose rock. You win this round!");
            count_player++;
        }
        else if(player==3 && computer==2)
        {
            printf("Computer chose paper. You win this round!");
            count_player++;
        }
        else
        {
            printf("It's a tie!");
        }
    }

    //final result
    printf("\nResult:\n");
    if(count_player>count_computer)
        printf("Congratulations! You won the game.");
    else if(count_computer>count_player)
        printf("Computer won the game. Better luck next time.");
    else
        printf("It's a tie!");

    printf("\n\nThank you for playing. Have a nice day.");

    return 0;
}