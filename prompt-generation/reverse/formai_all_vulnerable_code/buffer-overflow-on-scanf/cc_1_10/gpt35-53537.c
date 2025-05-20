//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare the variables
    int answer;
    char name[20];

    // Seed the random number generator
    srand(time(NULL));

    // Greet the user
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");

    // Read in the user's name
    scanf("%s", name);

    // Generate a random number between 1 and 5
    answer = rand() % 5 + 1;

    // Provide the user with a fortune based on their random number
    switch(answer)
    {
        case 1:
            printf("%s, the stars suggest that you will have good luck today!\n", name);
            break;
        case 2:
            printf("%s, you may face some challenges today, but you will overcome them!\n", name);
            break;
        case 3:
            printf("%s, be cautious today, as there may be someone trying to deceive you!\n", name);
            break;
        case 4:
            printf("%s, the future looks bright for you! Keep striving towards your goals!\n", name);
            break;
        case 5:
            printf("%s, today is the perfect day to take a risk and try something new!\n", name);
            break;
        default:
            printf("Sorry %s, there was an error generating your fortune. Please try again later.\n", name);
            break;
    }

    // Farewell the user
    printf("Thank you for using the Automated Fortune Teller! Come back soon!\n");

    return 0;
}