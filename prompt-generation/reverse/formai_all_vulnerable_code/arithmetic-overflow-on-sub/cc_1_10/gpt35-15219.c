//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
/* Automated Fortune Teller Program in Ada Lovelace Style */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generation
    
    /* Ada Lovelace welcome message */
    printf("Greetings! I am your automated fortune teller.\n");
    printf("I will predict your future with my advanced algorithmic calculations!\n\n");

    /* Gathering user information */
    char name[20];
    printf("Before we begin, what is your name? ");
    scanf("%s", name);

    int age;
    printf("How old are you, %s? ", name);
    scanf("%d", &age);
    
    int lucky_number;
    printf("What is your lucky number, %s? ", name);
    scanf("%d", &lucky_number);

    /* Calculating fortune based on user information */
    int fortune_number = (lucky_number * (rand() % 10 + 1)) - age;

    /* Displaying fortune */
    printf("\nDrum roll please...\n\n");
    printf("%s, your fortune for today is: ", name);

    switch ( fortune_number % 5 )
    {
        case 0:
            printf("You will find great success in your future endeavors!\n");
            break;
        case 1:
            printf("Beware of making hasty decisions, they may lead to regret.\n");
            break;
        case 2:
            printf("Today is a lucky day for you! Look out for unexpected surprises.\n");
            break;
        case 3:
            printf("It is time to take a break and focus on self-care. Remember to take care of yourself.\n");
            break;
        case 4:
            printf("Your future looks bright! Keep up the hard work and you will achieve your goals.\n");
            break;
        default:
            printf("Something went wrong with the algorithm... Please try again later.\n");
            break;
    }

    /* Ada Lovelace farewell message */
    printf("\nThank you for trusting me with your fortune, %s. Remember, the future is not set in stone.", name);
    
    return 0;
}