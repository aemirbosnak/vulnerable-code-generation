//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player_choice,computer_choice,result,player_score=0,computer_score=0,play_again=1;  
    srand(time(NULL));
    printf("Welcome to the Rock Paper Scissors game!\n\n");
    printf("-----RULES:-----\n");
    printf("Rock beats scissors.\n");
    printf("Scissors beats paper.\n");
    printf("Paper beats rock.\n");
    printf("-----------------\n");

    while(play_again==1)
    {
        printf("\n\nEnter your choice:\n[1]Rock [2]Paper [3]Scissors\n");
        scanf("%d",&player_choice);
        printf("\nPlayer chose: ");
        switch(player_choice)
        {
            case 1:
                printf("Rock\n");
                break;
            case 2:
                printf("Paper\n");
                break;
            case 3:
                printf("Scissors\n");
                break;
            default:
                printf("Invalid choice!\n");
                return 0;
        }

        computer_choice=rand()%3+1;
        printf("Computer chose: ");
        switch(computer_choice)
        {
            case 1:
                printf("Rock\n");
                break;
            case 2:
                printf("Paper\n");
                break;
            case 3:
                printf("Scissors\n");
                break;
        }

        if(player_choice==computer_choice)
        {
            printf("It's a tie!\n");
            result=0;
        }
        else if(player_choice==1 && computer_choice==3 || player_choice==2 && computer_choice==1 || player_choice==3 && computer_choice==2)
        {
            printf("Player wins!\n");
            result=1;
            player_score++;
        }
        else
        {
            printf("Computer wins!\n");
            result=-1;
            computer_score++;
        }

        printf("Current score:\nPlayer %d:%d Computer\n",player_score,computer_score);

        if(player_score==3)
        {
            printf("\nPlayer wins the game!\n");
            play_again=0;
        }
        else if(computer_score==3)
        {
            printf("\nComputer wins the game! You lose.\n");
            play_again=0;
        }

        printf("Do you want to play again?\n[1]Yes [0]No\n");
        scanf("%d",&play_again);
        if(play_again!=1 && play_again!=0)
        {
            printf("Invalid input! Ending game.\n");
            play_again=0;
        }
    }
    printf("\nThanks for playing the Rock Paper Scissors game!\n");
    return 0;
}