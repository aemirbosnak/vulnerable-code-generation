//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int option;
    char play_again = 'y';
    char name[20];

    srand(time(0)); //seed random number generator

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("What is your name?\n");
    scanf("%s", name);

    while(play_again == 'y')
    {
        printf("\n%s, please pick a number from 1 to 5 for your fortune:\n", name);    
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("\n%s, your fortune is... You will have a great day today!\n", name);
                break;
            case 2:
                printf("\n%s, your fortune is... You will find success in your endeavors!\n", name);
                break;
            case 3:
                printf("\n%s, your fortune is... A friendly stranger will cross your path today!\n", name);
                break;
            case 4:
                printf("\n%s, your fortune is... You will receive a gift from someone unexpected!\n", name);
                break;
            case 5:
                printf("\n%s, your fortune is... Your future is looking bright!\n", name);
                break;
            default:
                printf("\nInvalid option selected. Please choose a number between 1 and 5.\n");
        }

        printf("\nWould you like to play again, %s? (y/n)\n", name);
        scanf(" %c", &play_again);

        if(play_again != 'y' && play_again != 'n')
        {
            printf("\nInvalid input. Exiting...\n");
            play_again = 'n';
        }
    }

    printf("\nThank you for playing! Goodbye, %s!\n", name);

    return 0;
}