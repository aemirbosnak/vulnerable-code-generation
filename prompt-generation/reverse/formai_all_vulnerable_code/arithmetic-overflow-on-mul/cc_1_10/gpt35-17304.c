//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int alien_count, military_count, resource_count;
    float invasion_probability;

    srand(time(NULL));

    printf("-----------------------------\n");
    printf("|ALIEN INVASION PROBABILITY|\n");
    printf("-----------------------------\n");

    //inputting user data
    printf("Enter number of aliens: ");
    scanf("%d", &alien_count);
    printf("Enter number of military personnel: ");
    scanf("%d", &military_count);
    printf("Enter amount of resources available: ");
    scanf("%d", &resource_count);

    //calculating invasion probability
    invasion_probability = ((float)alien_count * 100) / (float)(military_count * resource_count);

    if (invasion_probability > 100)
    {
        printf("\n--ALERT--\n");
        printf("Probability of alien invasion is more than 100%%.\n");
        printf("The city has already been invaded.\n");
        printf("-----------------------");
    }
    else
    {
        printf("\nProbability of alien invasion: %.2f%%\n", invasion_probability);
        printf("----------------------------\n");
        printf("ALERT LEVELS:\n");

        if (invasion_probability > 75)
        {
            printf("(RED) All military and civilians must evacuate immediately.\n");
        }
        else if (invasion_probability > 50 && invasion_probability <= 75)
        {
            printf("(ORANGE) All military personnel must prepare for battle.\n");
            printf("Civilians must evacuate if possible.\n");
        }
        else if (invasion_probability > 25 && invasion_probability <= 50)
        {
            printf("(YELLOW) Military must prepare for battle.\n");
            printf("Civilians must prepare for possible evacuation.\n");
        }
        else if (invasion_probability > 10 && invasion_probability <= 25)
        {
            printf("(BLUE) Military must remain on alert.\n");
            printf("Civilians must prepare for possible evacuation.\n");
        }
        else
        {
            printf("(GREEN) No immediate threat of alien invasion.\n");
            printf("Military and civilians can continue with regular duties.\n");
        }

        printf("------------------------");
    }

    return 0;
}