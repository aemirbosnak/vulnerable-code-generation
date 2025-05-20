//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize random number generator
    srand(time(NULL));

    // welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // ask for user's name
    char name[20];
    printf("What is your name?\n");
    scanf("%s", name);

    // generate a random number between 1 and 5
    int fortune = rand() % 5 + 1;

    // use switch statement to display a different fortune based on the random number
    switch(fortune)
    {
        case 1:
            printf("%s, you will have a successful career in the future.\n", name);
            break;
        case 2:
            printf("%s, you will meet your soulmate within the next year.\n", name);
            break;
        case 3:
            printf("%s, you will have a major life change coming up soon.\n", name);
            break;
        case 4:
            printf("%s, you will receive unexpected good news within the next week.\n", name);
            break;
        case 5:
            printf("%s, you will travel to a new and exciting place in the near future.\n", name);
            break;
        default:
            printf("Error: invalid fortune number.\n");
    }

    // ask if user wants another fortune
    printf("Would you like to see another fortune? (y/n)\n");
    char answer;
    scanf(" %c", &answer);

    // use while loop to continue generating fortunes until user says no
    while(answer == 'y')
    {
        fortune = rand() % 5 + 1;

        switch(fortune)
        {
            case 1:
                printf("%s, you will receive a surprise gift from someone special soon.\n", name);
                break;
            case 2:
                printf("%s, you will make an unexpected friend in the coming weeks.\n", name);
                break;
            case 3:
                printf("%s, you will overcome a major obstacle in your life.\n", name);
                break;
            case 4:
                printf("%s, you will learn a valuable life lesson in the near future.\n", name);
                break;
            case 5:
                printf("%s, you will achieve a long-term goal that you have been working towards.\n", name);
                break;
            default:
                printf("Error: invalid fortune number.\n");
        }

        // ask again if user wants another fortune
        printf("Would you like to see another fortune? (y/n)\n");
        scanf(" %c", &answer);
    }

    printf("Thank you for using the Automated Fortune Teller. Goodbye!\n");

    return 0;
}