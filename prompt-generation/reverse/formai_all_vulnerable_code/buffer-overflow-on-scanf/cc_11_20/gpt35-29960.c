//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;
    char input;
    srand(time(NULL));

    printf("Welcome to Shape Shifters!\n");
    printf("Try to guess the shape that the computer is thinking of. You have 5 tries!\n");

    for (int i = 0; i < 5; i++)
    {
        int computer_choice = rand() % 3;

        printf("Enter 'c' for circle, 't' for triangle, or 's' for square: ");
        scanf(" %c", &input);

        if (input == 'c')
        {
            if (computer_choice == 0)
            {
                printf("Computer chose circle! You got it right!\n");
                score += 10;
            }
            else
            {
                printf("Computer chose %s! You got it wrong.\n", computer_choice == 1 ? "triangle" : "square");
            }
        }
        else if (input == 't')
        {
            if (computer_choice == 1)
            {
                printf("Computer chose triangle! You got it right!\n");
                score += 10;
            }
            else
            {
                printf("Computer chose %s! You got it wrong.\n", computer_choice == 0 ? "circle" : "square");
            }
        }
        else if (input == 's')
        {
            if (computer_choice == 2)
            {
                printf("Computer chose square! You got it right!\n");
                score += 10;
            }
            else
            {
                printf("Computer chose %s! You got it wrong.\n", computer_choice == 0 ? "circle" : "triangle");
            }
        }
        else
        {
            printf("Invalid input. Try again.\n");
            i--;
            continue;
        }

        printf("Your current score is: %d\n", score);
    }

    printf("Game over! Your final score is: %d\n", score);

    return 0;
}