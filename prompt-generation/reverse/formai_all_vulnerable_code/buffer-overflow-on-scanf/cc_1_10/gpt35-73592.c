//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to clear the screen
void clrscr()
{
    system("@cls||clear");
}

int main()
{
    clrscr();
    printf("\nWelcome to Dice Roll!\n");
    printf("---------------------\n\n");
    printf("You will be rolling two dice.\nIf the sum of the dice is 7 or 11, you win!\nIf the sum is 2, 3, or 12, you lose!\nOtherwise, you will keep rolling until you either win or lose.\n\n");

    //initialize random number generator
    srand(time(0));

    char choice;
    int dice1, dice2, sum;

    do
    {
        printf("Press 'r' to roll the dice.\n");
        scanf(" %c", &choice);
        if(choice == 'r')
        {
            //rolling the dice
            dice1 = rand()%6 + 1;
            dice2 = rand()%6 + 1;
            sum = dice1 + dice2;

            printf("You rolled a %d and a %d.\n", dice1, dice2);

            if(sum == 7 || sum == 11)
            {
                printf("Congratulations! You win!\n");
                break;
            }
            else if(sum == 2 || sum == 3 || sum == 12)
            {
                printf("Sorry! You lost!\n");
                break;
            }
            else
            {
                printf("You rolled a %d.\n", sum);
                printf("Keep rolling!\n\n");
            }
        }
        else
        {
            printf("Invalid input. Try again!\n\n");
        }
    } while (1);

    return 0;
}