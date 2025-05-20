//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int input, num, count = 0;
    char choice;

    srand(time(0));
    num = rand() % 100 + 1;

    printf("Welcome to Guess the Number game!\n\n");
    printf("I have chosen a number between 1 and 100. Can you guess it?\n\n");

    do
    {
        count++;
        printf("Enter your guess: ");
        scanf("%d", &input);

        if(input == num)
        {
            printf("\nCongratulations! You guessed the number in %d attempts.\n", count);
            printf("\nDo you want to play again? (y/n): ");
            scanf(" %c", &choice);

            if(choice == 'y' || choice == 'Y')
            {
                num = rand() % 100 + 1;
                printf("\nGreat! Let's play again, I have chosen a new number!\n\n");
                count = 0;
            }
            else
            {
                printf("\nThank you for playing!\n");
                break;
            }
        }
        else if(input < num)
        {
            printf("Too low! Try again.\n\n");
        }
        else if(input > num)
        {
            printf("Too high! Try again.\n\n");
        }

    }while(input != num);

    return 0;
}