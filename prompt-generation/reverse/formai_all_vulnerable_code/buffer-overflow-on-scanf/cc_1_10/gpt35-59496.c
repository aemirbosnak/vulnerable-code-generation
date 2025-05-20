//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int number, guess, attempt = 1;
    srand(time(0));
    number = rand()%100 + 1; // generates random number between 1 to 100

    // game menu for user
    printf("\nWelcome to the Guessing Game!\n\n");
    printf("Rules:\n");
    printf("1. Guess a number between 1 to 100.\n");
    printf("2. You have only 5 attempts.\n");
    printf("3. If your guess is within 10 of the number, you will be notified by 'WARM' , else 'COLD'\n");
    printf("4. If your guess is closer than your previous guess, 'WARMER' otherwise 'COLDER'\n\n");

    // loop for five attempts
    while(attempt <= 5)
    {
        printf("\nEnter your guess:");
        scanf("%d", &guess);

        // checking for valid input between 1 to 100
        if(guess<1 || guess>100)
        {
            printf("Invalid Input! Try again.\n");
            continue;
        }

        // matching number and guess
        if(guess == number)
        {
            printf("\nCongratulations! You guessed the right number in %d attempts.\n", attempt);
            break;
        }
        else if(attempt == 5) // Max attempts
        {
            printf("\nSorry! You have run out of attempts. The number was %d.\n", number);
            break;
        }
        else // user still has attempt left
        {
            // checking the distance between guess and number
            if(abs(guess - number) <= 10)
                printf("WARM ");
            else
                printf("COLD ");

            // checking if warmer or colder than previous try
            if(attempt == 1)
                printf("Guess Again!\n");
            else if(abs(guess-number) < abs(guess-number))
                printf("WARMER Guess Again!\n");
            else
                printf("COLDER Guess Again!\n");

            attempt++;
        }
    } 

    return 0;
}