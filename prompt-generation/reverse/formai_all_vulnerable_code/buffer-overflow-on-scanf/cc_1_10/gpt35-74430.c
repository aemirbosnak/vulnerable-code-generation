//FormAI DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>

void apocalypse(int survivors, int zombies)
{
    if (survivors == 0)
    {
        printf("The human race is extinct. The world belongs to the undead.\n");
        return;
    }
    else if (zombies == 0)
    {
        printf("All zombies have been eradicated. Humanity prevails!\n");
        return;
    }
    else
    {
        printf("%d survivors are still alive. %d zombies roam the Earth.\n", survivors, zombies);
        printf("What is your plan of action? (1: Fight, 2: Flee)\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("You choose to fight.\n");
            zombies--;
            apocalypse(survivors, zombies);
        }
        else if (choice == 2)
        {
            printf("You choose to flee.\n");
            survivors--;
            apocalypse(survivors, zombies);
        }
        else
        {
            printf("Invalid choice. Try again.\n");
            apocalypse(survivors, zombies);
        }
    }
}

int main()
{
    int numSurvivors = 10;
    int numZombies = 8;

    printf("The world has been overrun by zombies! Can you survive the apocalypse?\n");

    apocalypse(numSurvivors, numZombies);

    return 0;
}