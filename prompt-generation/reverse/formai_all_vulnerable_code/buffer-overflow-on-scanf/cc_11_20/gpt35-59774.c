//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, fortune;
    printf("Select a number from 1 to 10: ");
    scanf("%d", &choice);
    srand(time(NULL));
    fortune = rand() % 10 + 1;

    switch (choice)
    {
        case 1:
            printf("Your future looks bright.\n");
            break;
        case 2:
            printf("Be prepared for a big change in your life.\n");
            break;
        case 3:
            printf("You will find love in the most unexpected place.\n");
            break;
        case 4:
            printf("Financial success is in your near future.\n");
            break;
        case 5:
            printf("Your hard work will finally pay off.\n");
            break;
        case 6:
            printf("The universe is conspiring in your favor.\n");
            break;
        case 7:
            printf("Be careful with your decisions, they will have a big impact.\n");
            break;
        case 8:
            printf("Your creativity will reach new heights.\n");
            break;
        case 9:
            printf("A new opportunity will present itself.\n");
            break;
        case 10:
            printf("Travel will play a big role in your future.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    if (fortune == choice)
    {
        printf("You got lucky! Your fortune is now doubled.\n");
    }
    else
    {
        printf("Better luck next time.\n");
    }

    return 0;
}