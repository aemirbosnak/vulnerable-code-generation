//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate random number between 1 to 100
int generate_random_number()
{
    srand(time(0));
    return rand()%100 + 1;
}

int main()
{
    // Welcome message
    printf("Guess the number between 1 to 100 in 10 attempts\n");

    // generate random number to guess
    int number_to_guess = generate_random_number();
    
    // variable to keep track of number of attempts
    int num_of_attempts = 1;

    // variable to store the user's guess
    int user_guess;

    // loop until user guesses the correct number or number of attempts become greater than 10
    while(num_of_attempts<=10)
    {
        printf("\nEnter your guess: ");
        scanf("%d",&user_guess);

        if(user_guess == number_to_guess)
        {
            printf("You guessed the correct number in %d attempts!", num_of_attempts);
            break;
        }
        else
        {
            printf("Incorrect! ");
            if(user_guess>number_to_guess)
                printf("Guess a smaller number.");
            else
                printf("Guess a larger number.");
        }

        num_of_attempts++;
    }

    if(num_of_attempts>10)
        printf("Sorry, you have exceeded the limit of 10 attempts. The correct number was %d.",number_to_guess);

    return 0;
}