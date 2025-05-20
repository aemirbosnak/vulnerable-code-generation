//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int );

int main()
{
    int choice,guess,answer,points=0;
    char name[50];

    srand(time(0)); //seeding rand function with current time

    printf("Welcome to the Text-Based Adventure Game! \n");
    printf("What is your name?\n");
    scanf("%s",name);

    printf("\nHi %s, are you ready to play the game?\n", name);

    do
    {
        printf("\nChoose one of the below options: \n");
        printf("1. Guess a number between 1 to 10\n");
        printf("2. Guess a number between 1 to 20\n");
        printf("3. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nYou have chosen to guess a number between 1 to 10\n");
                answer = rand()%10 + 1; //generating random number between 1 to 10
                printf("Guess a number between 1 to 10: ");
                scanf("%d",&guess);

                if(guess == answer)
                {
                    printf("Congratulations! You guess the number correctly!");
                    points++;
                }
                else
                {
                    printf("Sorry! The correct answer is %d",answer);
                }
                break;
            case 2:
                printf("\nYou have chosen to guess a number between 1 to 20\n");
                answer = rand()%20 + 1; //generating random number between 1 to 20
                printf("Guess a number between 1 to 20: ");
                scanf("%d",&guess);

                if(guess == answer)
                {
                    printf("Good job! you got it right!");
                    points++;
                }
                else
                {
                    printf("Oops! The number was actually %d",answer);
                }
                break;
            case 3:
                printf("\nThanks for playing, %s!\n",name);
                printf("Your total points are : %d",points);
                exit(0);
            default:
                printf("\nInvalid choice, please choose again\n");
                break;
        }
        delay(2); //pausing the program for 2 seconds
    }while(choice != 3);

    return 0;
}

void delay(int secs)
{
    int milli_secs = 1000 * secs;
    clock_t start_time = clock();

    while(clock() < start_time + milli_secs);
}