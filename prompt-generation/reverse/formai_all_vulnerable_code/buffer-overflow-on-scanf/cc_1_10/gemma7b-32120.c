//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_again(int score);

int main()
{
    int score = 0;
    char guess;
    char answer = 'a';
    time_t start_time, end_time;

    start_time = time(NULL);

    while (answer != 'n')
    {
        printf("Enter your guess: ");
        scanf("%c", &guess);

        if (guess == answer)
        {
            score++;
            printf("Correct! You have scored a point.\n");
        }
        else
        {
            printf("Incorrect. The answer is %c.\n", answer);
        }

        printf("Do you want to play again? (y/n): ");
        scanf("%c", &answer);
    }

    end_time = time(NULL);
    time_t time_taken = end_time - start_time;

    play_again(score);

    printf("Thank you for playing. You scored a total of %d points in %d seconds.\n", score, time_taken);

    return 0;
}

void play_again(int score)
{
    char answer;

    printf("Would you like to play again? (y/n): ");
    scanf("%c", &answer);

    if (answer == 'y')
    {
        main();
    }
}