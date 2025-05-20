//FormAI DATASET v1.0 Category: Smart home light control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int light_status = 0;
    srand(time(NULL));

    printf("Welcome to Retro Smart Home Light Control\n\n");

    printf("Press 1 to turn on the lights and 0 to turn them off:\n");

    while (1)
    {
        int input;

        scanf("%d", &input);

        if (input != 1 && input != 0)
        {
            printf("Invalid input.\n");
            continue;
        }

        if (input == light_status)
        {
            printf("The lights are already %s.\n", input ? "on" : "off");
        }
        else
        {
            if (input == 1)
            {
                printf("Turning on the lights...\n");
            }
            else
            {
                printf("Turning off the lights...\n");
            }

            int delay = rand() % 5 + 1;

            for (int i = 1; i <= delay; i++)
            {
                printf("%d...\n", i);
                sleep(1);
            }

            light_status = input;
            printf("The lights are now %s.\n", input ? "on" : "off");
        }
    }

    return 0;
}