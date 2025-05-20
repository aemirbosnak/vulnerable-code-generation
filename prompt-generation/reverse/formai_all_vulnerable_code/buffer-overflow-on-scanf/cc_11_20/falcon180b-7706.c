//Falcon-180B DATASET v1.0 Category: Table Game ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int player, com;
    int choice;
    int flag = 0;
    int score_player = 0;
    int score_com = 0;

    printf("Welcome to the Rock Paper Scissors Game!\n");
    printf("Player 1, please enter your choice: ");
    scanf("%d", &choice);

    srand(time(0));
    player = rand() % 3 + 1;

    if(player == 1)
    {
        printf("You chose Rock!\n");
    }
    else if(player == 2)
    {
        printf("You chose Paper!\n");
    }
    else
    {
        printf("You chose Scissors!\n");
    }

    com = rand() % 3 + 1;

    if(com == 1)
    {
        printf("Computer chose Rock!\n");
    }
    else if(com == 2)
    {
        printf("Computer chose Paper!\n");
    }
    else
    {
        printf("Computer chose Scissors!\n");
    }

    if(player == com)
    {
        printf("It's a tie!\n");
    }
    else if((player == 1 && com == 2) || (player == 2 && com == 1))
    {
        printf("You win!\n");
        score_player++;
    }
    else if((player == 2 && com == 3) || (player == 3 && com == 2))
    {
        printf("You lose!\n");
        score_com++;
    }

    printf("Score: Player %d - Computer %d\n", score_player, score_com);

    return 0;
}