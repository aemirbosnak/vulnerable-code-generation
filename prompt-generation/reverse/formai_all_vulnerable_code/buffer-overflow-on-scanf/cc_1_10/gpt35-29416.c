//FormAI DATASET v1.0 Category: Funny ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("Welcome to the Exciting Number Game!\n");
    printf("We will generate a random number between 1 and 100.\n");
    printf("Then, you will try to guess this number in the fewest attempts possible.\n");
    printf("Are you ready? Let's go!\n\n");

    int num = rand() % 100 + 1;
    int guess = -1;
    int attempts = 0;

    while (guess != num) {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess);

        if (guess < num) {
            printf("Too low!\n");
        } else if (guess > num) {
            printf("Too high!\n");
        }

        attempts++;
    }

    printf("\nCongratulations! You guessed the number in %d attempts!\n", attempts);

    switch(attempts) {
        case 1:
            printf("You are a mind reader!\n");
            break;
        case 2:
        case 3:
            printf("You are awesome!\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("You are pretty good!\n");
            break;
        default:
            printf("You can do better than that!\n");
    }

    return 0;
}