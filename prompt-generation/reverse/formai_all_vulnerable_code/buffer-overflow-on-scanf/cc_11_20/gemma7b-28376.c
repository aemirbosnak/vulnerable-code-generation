//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int num;
    srand(time(NULL));

    printf("Welcome to the Mystical Oracle of Zoltan!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Greetings, %s, your fate is sealed...\n", name);

    num = rand() % 11;

    switch (num)
    {
        case 0:
            printf("The stars align in your favor, my dear %s.\n", name);
            break;
        case 1:
            printf("Beware, my dear %s, misfortune lurks nearby.\n", name);
            break;
        case 2:
            printf("Love and prosperity dance in your path, %s.\n", name);
            break;
        case 3:
            printf("Your spirit guides you towards greatness, %s.\n", name);
            break;
        case 4:
            printf("Obstacles may arise, but you will overcome them, %s.\n", name);
            break;
        case 5:
            printf("The path ahead is uncertain, %s, prepare for surprises.\n", name);
            break;
        case 6:
            printf("Your creativity will bring you fortune, %s.\n", name);
            break;
        case 7:
            printf("Be cautious, my dear %s, danger lies ahead.\n", name);
            break;
        case 8:
            printf("The winds blow strong, %s, prepare for change.\n", name);
            break;
        case 9:
            printf("Your intuition guides you, %s, trust your instincts.\n", name);
            break;
        case 10:
            printf("The future is bright, %s, embrace your destiny.\n", name);
            break;
    }

    printf("Thank you for visiting the Mystical Oracle of Zoltan, %s. May your fortune be ever bright.\n", name);

    return 0;
}