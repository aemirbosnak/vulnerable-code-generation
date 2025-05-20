//Falcon-180B DATASET v1.0 Category: Table Game ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player1,player2,choice,dice;
    char playagain;

    srand(time(0));

    do
    {
        printf("\n\nWelcome to the Dice Game\n");
        printf("-------------------------------------\n");
        printf("Player 1 : X and Player 2 : O\n");
        printf("-------------------------------------\n");

        printf("\nEnter your choice :\n1.Play\n2.Instructions\n3.Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nPlayer 1's Turn\n");
                dice=rand()%6+1;
                printf("You rolled a %d\n",dice);
                if(dice==1)
                {
                    printf("You lose your turn\n");
                }
                else
                {
                    printf("Press 1 to hold or any other key to roll again\n");
                    scanf("%d",&player1);
                    if(player1==1)
                    {
                        printf("You have held your turn\n");
                    }
                    else
                    {
                        dice=rand()%6+1;
                        printf("You rolled a %d\n",dice);
                        if(dice==1)
                        {
                            printf("You lose your turn\n");
                        }
                        else
                        {
                            printf("Your score is %d\n",dice+player1);
                        }
                    }
                }
                break;

            case 2:
                printf("\nInstructions\n");
                printf("Each player gets a chance to roll the dice\n");
                printf("If a player rolls 1,he loses his turn\n");
                printf("If a player rolls any other number,he can either hold his turn or roll again\n");
                printf("If he rolls again and gets 1,he loses his turn\n");
                printf("The player with the highest score wins\n");
                break;

            case 3:
                printf("\nExiting....\n");
                exit(0);

            default:
                printf("\nInvalid choice\n");
        }

        printf("\nDo you want to play again? (y/n)\n");
        scanf(" %c",&playagain);

    }while(playagain=='y'||playagain=='Y');

    return 0;
}