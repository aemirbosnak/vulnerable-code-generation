//FormAI DATASET v1.0 Category: Math exercise ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random integer */
int generate_random_number()
{
    int num;
    srand(time(NULL));
    num = rand() % 100; // Generate integer between 0 to 99
    return num;
}

/* Function to check if user's guess is correct */
void check_guess(int num, int guess, int *num_of_guesses)
{
    (*num_of_guesses)++; // Increment number of guesses
    if(guess < num)
    {
        printf("Your guess is too low. Try again!\n");
    }
    else if(guess > num)
    {
        printf("Your guess is too high. Try again!\n");
    }
    else
    {
        printf("Congratulations! You guessed the number in %d attempts.\n", *num_of_guesses);
    }
}

/* Main function */
int main()
{
    int num = generate_random_number(); // Generate random number
    int guess;
    int num_of_guesses = 0;

    printf("Welcome to the Guessing Game!\n");
    printf("Can you guess the number between 0 to 99?\n");

    /* Loop until user guesses the correct number */
    while(1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        check_guess(num, guess, &num_of_guesses); // Check user's guess

        if(guess == num)
        {
            printf("Do you want to play again? (y/n): ");
            getchar(); // Clear input buffer
            char choice = getchar();

            /* Play again if user enters 'y', otherwise exit */
            if(choice == 'y')
            {
                num = generate_random_number(); // Generate new random number
                num_of_guesses = 0; // Reset number of guesses
                printf("Can you guess the new number between 0 to 99?\n");
            }
            else
            {
                printf("Thanks for playing! Goodbye!\n");
                break;
            }
        }
    }

    return 0;
}