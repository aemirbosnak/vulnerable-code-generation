//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Funniest Game of the Century!\n");
    printf("In this game, you will play against the computer in a battle of wits.\n");
    printf("The first one to make a mistake loses the game.\n");

    int player_score = 0, computer_score = 0;

    srand(time(NULL));

    while (1)
    {
        printf("\nWhat is the capital of California?\n");
        printf("a) San Francisco\n");
        printf("b) Sacramento\n");
        printf("c) Los Angeles\n");

        char player_answer;
        scanf(" %c", &player_answer);

        if (player_answer != 'b')
        {
            printf("You lose!\n");
            computer_score++;
            break;
        }

        printf("What's the square root of 64?\n");
        printf("a) 6\n");
        printf("b) 8\n");
        printf("c) 9\n");

        char computer_answer = rand() % 3 + 'a';
        printf("Computer chooses: %c\n", computer_answer);

        char player_answer2;
        scanf(" %c", &player_answer2);

        if (player_answer2 != 'b' && computer_answer == 'b')
        {
            printf("You both got it right! But since the computer is a machine and can't really enjoy the game, you win (for now)!\n");
            player_score++;
        }
        else if (player_answer2 != 'b' && computer_answer != 'b')
        {
            printf("Nobody got it right! But since the computer is a machine and can't really feel bad about it, you lose (for now)!\n");
            computer_score++;
            break;
        }
        else if (player_answer2 == 'b' && computer_answer != 'b')
        {
            printf("The computer got it wrong! You win!\n");
            player_score++;
            break;
        }
        else if (player_answer2 == 'b' && computer_answer == 'b')
        {
            printf("You both got it right! But since the computer is a machine and can't really enjoy the game, you win (for now)!\n");
            player_score++;
            break;
        }
    }

    printf("Final score: You - %d, Computer - %d\n", player_score, computer_score);

    if (player_score >= 3)
    {
        printf("Congratulations, you win the game! You are officially smarter than a computer (for now).\n");
    }
    else
    {
        printf("Sorry, you lost the game. Please try again later when you are feeling smarter.\n");
    }
    
    return 0;
}