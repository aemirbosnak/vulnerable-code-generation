//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIN_SCORE 100
#define LOSE_SCORE 0

int main(int argc, char *argv[])
{
    int score = 0;
    int max_score = 0;
    int min_score = 100;
    char input;

    printf("Welcome to the terminal-based game!\n");
    printf("Rules:\n");
    printf("You have to guess a number between 1 and 100.\n");
    printf("You have 10 tries.\n");
    printf("If you guess the number correctly, you win!\n");
    printf("If you fail to guess the number, you lose!\n");

    srand(time(NULL));
    int random_number = rand() % 101;

    do
    {
        printf("Guess a number between 1 and 100: ");
        scanf("%d", &input);
        if (input > 100 || input < 1)
        {
            printf("Invalid input!\n");
            continue;
        }
        if (input == random_number)
        {
            score += WIN_SCORE;
            printf("Congratulations! You guessed the number correctly!\n");
            if (score > max_score)
                max_score = score;
            break;
        }
        else if (input < random_number)
        {
            printf("Too low!\n");
            score += LOSE_SCORE;
        }
        else
        {
            printf("Too high!\n");
            score += LOSE_SCORE;
        }
    } while (score < max_score && score > min_score);

    if (score > max_score)
        printf("You've reached the highest score of %d!\n", score);
    else if (score < min_score)
        printf("You've reached the lowest score of %d!\n", min_score);
    else
        printf("You've reached the average score of %d!\n", score);

    printf("Your final score is %d.\n", score);

    return 0;
}