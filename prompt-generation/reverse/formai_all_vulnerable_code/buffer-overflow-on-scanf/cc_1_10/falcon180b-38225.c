//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_score = 0, computer_score = 0;
    char choice;
    int random_number;

    srand(time(NULL));

    do
    {
        printf("\n\nWelcome to the Number Guessing Game!\n\n");
        printf("You have %d points and the computer has %d points.\n", player_score, computer_score);
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &random_number);

        if(random_number == 0)
        {
            printf("\nInvalid input! Please enter a number between 1 and 100.\n");
            continue;
        }

        choice = getchar();

        if(choice == '\n')
        {
            printf("\nYou guessed %d points.\n", random_number);
            player_score += random_number;
        }
        else
        {
            printf("\nYou guessed %c points.\n", choice);
        }

        computer_score += rand() % 101;

        printf("\nThe computer guessed %d points.\n\n", computer_score);

    }while(player_score < 101 || computer_score < 101);

    if(player_score == computer_score)
    {
        printf("\n\nThe game is a tie! You both have %d points.\n", player_score);
    }
    else if(player_score > computer_score)
    {
        printf("\n\nCongratulations! You won the game with %d points.\n", player_score);
    }
    else
    {
        printf("\n\nSorry! You lost the game with %d points.\n", computer_score);
    }

    return 0;
}