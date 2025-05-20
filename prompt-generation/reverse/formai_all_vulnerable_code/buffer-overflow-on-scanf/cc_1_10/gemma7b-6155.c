//Gemma-7B DATASET v1.0 Category: Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n, i, j, k;

    printf("Prepare for an epic adventure!\n");
    printf("Choose your path:\n");
    printf("1. Travel to the East\n");
    printf("2. Explore the South\n");
    printf("3. Embark on a Quest\n");

    scanf("%d", &n);

    switch (n)
    {
        case 1:
            printf("You journeyed East, brave warrior. Prepare for a battle with fiery demons!\n");
            break;
        case 2:
            printf("You ventured South, hero. Be ready for treacherous terrain and cunning creatures!\n");
            break;
        case 3:
            printf("You embarked on a Quest, legend. Brace yourself for a journey filled with magic and mystery!\n");
            break;
        default:
            printf("Invalid choice, peasant. Try again.\n");
    }

    printf("Now, prepare for a showdown with the evil overlord. Enter 'FIGHT' to engage in battle.\n");

    scanf("%s", k);

    if (strcmp(k, "FIGHT") == 0)
    {
        printf("FIGHT! Prepare for a spectacular battle!\n");
        for (i = 0; i < 10; i++)
        {
            printf("A clash of epic proportions!\n");
            for (j = 0; j < 5; j++)
            {
                printf("Thunderous roar!\n");
            }
        }

        printf("You have defeated the evil overlord. You are a hero!\n");
    }
    else
    {
        printf("Invalid input, peasant. Try again.\n");
    }

    return;
}