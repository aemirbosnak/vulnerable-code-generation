//Gemma-7B DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 0;
    char name[20];
    printf("What is your name, my dear? ");
    scanf("%s", name);

    printf("Welcome, %s, to the grandest C table game ever created!\n", name);

    // Let's play a game of... Poop Bingo!
    printf("Would you like to play Poop Bingo? (Y/N) ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'Y' || answer == 'y')
    {
        // Prepare the bingo card
        int numbers[5] = {1, 2, 3, 4, 5};
        int i = 0;
        for (i = 0; i < 5; i++)
        {
            printf("Bingo card number: %d\n", numbers[i]);
        }

        // Draw a number
        int drawnNumber = rand() % 5 + 1;
        printf("The number drawn is: %d\n", drawnNumber);

        // Check if the number is on the card
        int found = 0;
        for (i = 0; i < 5; i++)
        {
            if (numbers[i] == drawnNumber)
            {
                found = 1;
            }
        }

        // If the number is found, increase the score
        if (found)
        {
            score++;
            printf("Congratulations, %s, you found the number! Your score is: %d\n", name, score);
        }
        else
        {
            printf("Sorry, %s, you didn't find the number. Better luck next time.\n", name);
        }
    }
    else
    {
        printf("Oh well, %s, maybe next time. Have a nice day!\n", name);
    }

    return 0;
}