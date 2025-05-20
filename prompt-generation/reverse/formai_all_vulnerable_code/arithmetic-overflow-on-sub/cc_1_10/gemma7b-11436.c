//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

int main()
{
    int num_guess = 0;
    int guess_num;
    int target_num;
    int is_won = 0;
    time_t start_time, end_time;

    target_num = rand() % MAX_NUM + 1;
    start_time = time(NULL);

    printf("I'm thinking of a number between 1 and %d. Guess what it is: ", MAX_NUM);

    while (!is_won && num_guess < MAX_NUM)
    {
        scanf("Enter your guess: ", &guess_num);

        if (guess_num == target_num)
        {
            is_won = 1;
            printf("Congratulations! You guessed the number in %d guesses.", num_guess);
        }
        else if (guess_num < target_num)
        {
            num_guess++;
            printf("Too low. Try again.\n");
        }
        else
        {
            num_guess++;
            printf("Too high. Try again.\n");
        }
    }

    if (!is_won)
    {
        printf("Sorry, you lost. The number was %d.", target_num);
    }

    end_time = time(NULL);
    printf("Time taken: %lf seconds", end_time - start_time);

    return 0;
}