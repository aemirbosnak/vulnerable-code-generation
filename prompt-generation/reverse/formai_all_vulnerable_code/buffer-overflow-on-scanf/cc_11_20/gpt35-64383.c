//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int user_choice, comp_choice, result;
    int user_score = 0, comp_score = 0;
    int round = 1;

    srand(time(NULL));

    printf("\t\tROCK-PAPER-SCISSORS GAME\n");

    do
    {
        printf("\nROUND %d\n", round);

        printf("\nChoose your weapon:\n1.ROCK\t2.PAPER\t3.SCISSORS\n");
        scanf("%d", &user_choice);

        if(user_choice < 1 || user_choice > 3)
        {
            printf("Invalid Choice! Try again.\n");
            continue;
        }

        comp_choice = rand() % 3 + 1;

        printf("\nYou selected ");
        switch(user_choice)
        {
            case 1: printf("ROCK\n"); break;
            case 2: printf("PAPER\n"); break;
            case 3: printf("SCISSORS\n"); break;
        }

        printf("The computer selected ");
        switch(comp_choice)
        {
            case 1: printf("ROCK\n"); break;
            case 2: printf("PAPER\n"); break;
            case 3: printf("SCISSORS\n"); break;
        }

        result = user_choice - comp_choice;

        if(result == -2 || result == 1)
        {
            printf("\nYou win this round!\n");
            user_score++;
        }
        else if(result == -1 || result == 2)
        {
            printf("\nThe computer wins this round!\n");
            comp_score++;
        }
        else
        {
            printf("\nIt's a tie this round!\n");
        }

        round++;
        printf("\nYour score: %d | Computer score: %d\n", user_score, comp_score);

    }while(user_score < 3 && comp_score < 3);

    if(user_score == comp_score)
    {
        printf("\nIt's a draw!\n");
    }
    else if(user_score > comp_score)
    {
        printf("\nCongratulations! You win the game!\n");
    }
    else
    {
        printf("\nBetter luck next time! The computer wins the game!\n");
    }

    return 0;
}