//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generateRandomNumber(int lower, int upper)
{
    int num;
    srand(time(0));
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    int num, guess, attempts = 1;
    const int lower = 1, upper = 100; // Minimum and maximum values for the random number

    num = generateRandomNumber(lower, upper);

    printf("*** Welcome to the Happy Guessing Game! ***\n\n");

    // Loop for taking guesses from the user
    do
    {
        printf("Guess the number between %d and %d: ", lower, upper);
        scanf("%d", &guess);

        if (guess == num)
        {
            printf("Congratulations! You have guessed the number in %d attempt(s)!\n", attempts);
            break;
        }
        else if (guess < num)
        {
            printf("Oops! Your guess was too low. Try again.\n\n");
        }
        else if (guess > num)
        {
            printf("Oops! Your guess was too high. Try again.\n\n");
        }

        attempts++;

    } while (guess != num);

    printf("\nThank you for playing the Happy Guessing Game! Have a great day!");

    return 0;
}