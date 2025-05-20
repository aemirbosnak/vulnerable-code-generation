//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number
int generateRandom()
{
    srand(time(NULL)); // initialize random seed based on current time
    int random_num = rand() % 10 + 1; // generates a random number between 1 to 10
    return random_num;
}

int main()
{
    int num = generateRandom(); // generate a random number
    int guess;
    int count = 0; // counter for number of attempts

    printf("Guess the number between 1 to 10\n");

    while (1)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        // check if guess is correct
        if (guess == num)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", count);
            break; // exit the loop
        }
        else
        {
            count++; // increment the counter
            if (guess < num)
            {
                printf("Your guess is too low. Try Again!\n");
            }
            else
            {
                printf("Your guess is too high. Try Again!\n");
            }
            if (count == 5) // if user makes 5 incorrect guesses
            {
                printf("You have reached max attempts. The number was %d.\n", num);
                break; // exit the loop
            }
        }
    }

    return 0;
}