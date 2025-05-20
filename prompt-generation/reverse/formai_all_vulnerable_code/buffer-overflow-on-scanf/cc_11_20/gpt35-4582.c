//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Thank you for choosing Automated Fortune Teller.\n");

    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nHello, %s, let me tell you your fortune!\n\n", name);

    // Set the random seed
    srand(time(NULL));

    // Generate a random number between 1 and 10 (inclusive)
    int num = rand() % 10 + 1;

    // Use the random number to generate a fortune
    char* fortune;

    switch(num)
    {
        case 1:
            fortune = "Good things come to those who wait.";
            break;
        case 2:
            fortune = "The future is bright.";
            break;
        case 3:
            fortune = "You will receive news from someone far away.";
            break;
        case 4:
            fortune = "Beware of those who are too eager to help.";
            break;
        case 5:
            fortune = "You will soon embark on a journey.";
            break;
        case 6:
            fortune = "You will meet someone important today.";
            break;
        case 7:
            fortune = "A much needed vacation will soon come your way.";
            break;
        case 8:
            fortune = "You are wise to seek new experiences.";
            break;
        case 9:
            fortune = "You will create something of value.";
            break;
        case 10:
            fortune = "Your heartfelt dreams will come true.";
            break;
        default:
            fortune = "Error: Something went wrong!";
            break;
    }

    printf("Your fortune is: %s\n\n", fortune);

    printf("Thank you for using Automated Fortune Teller. Goodbye!");

    return 0;
}