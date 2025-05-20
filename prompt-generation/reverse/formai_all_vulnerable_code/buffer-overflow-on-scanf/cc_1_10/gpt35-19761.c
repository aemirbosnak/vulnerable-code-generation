//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get random number
int getRandomNumber(int min, int max)
{
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    int inputNumber, randomNumber, score=0;

    printf("Welcome to Guess the Number game!\n");
    printf("You will be given 5 chances to guess the random number.\n\n");

    // get random number
    randomNumber = getRandomNumber(1, 100);

    // game loop, 5 chances to guess
    for(int i=0; i<5; i++)
    {
        printf("Enter your guess (between 1-100): ");
        scanf("%d", &inputNumber);

        // check if input is valid
        if(inputNumber < 1 || inputNumber > 100)
        {
            printf("Invalid input! Please enter a number between 1-100.\n\n");
            i--; // decrement i to get full 5 chances
            continue;
        }

        // check if guessed number is correct
        if(inputNumber == randomNumber)
        {
            score += 100; // add 100 points for correct guess
            printf("Congratulations! You guessed the number.\n");
            break;
        }
        else
        {
            // calculate the difference
            int difference = abs(randomNumber - inputNumber);
            if(difference <= 5)
            {
                printf("Hot! You are within 5 numbers of the correct answer.\n\n");
            }
            else if(difference <= 10)
            {
                printf("Warm! You are within 10 numbers of the correct answer.\n\n");
            }
            else
            {
                printf("Cold! You are more than 10 numbers away from the correct answer.\n\n");
            }

            score += 10; // add 10 points for each guess
        }
    }

    printf("The correct number was %d.\n", randomNumber);
    printf("Your final score is %d.\n", score);

    return 0;
}