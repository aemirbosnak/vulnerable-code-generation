//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, guess, num, count;
    char option;

    srand(time(NULL));

    printf("\n----------------------------------------------------");
    printf("\n              AUTOMATED FORTUNE TELLER              ");
    printf("\n----------------------------------------------------");
    printf("\nWelcome to the Automated Fortune Teller!\n");
    printf("Would you like your fortune predicted? (y/n): ");
    scanf("%c", &option);

    while(option == 'y')
    {
        printf("\nGreat! I will now generate a random number between 1 and 100.\n");
        num = rand() % 100 + 1;
        count = 0;

        do{
            printf("Make your guess: ");
            scanf("%d", &guess);
            count++;

            if(guess > num)
            {
                printf("Too high! Try again.\n");
            }
            else if(guess < num)
            {
                printf("Too low! Try again.\n");
            }
            else
            {
                printf("\nCongratulations! You guessed the number in %d tries!\n", count);
            }
        }while(guess != num);

        printf("Would you like to predict your fortune again? (y/n): ");
        scanf(" %c", &option);

    }

    printf("\nThank you for trying out the Automated Fortune Teller!\n");
    return 0;
}