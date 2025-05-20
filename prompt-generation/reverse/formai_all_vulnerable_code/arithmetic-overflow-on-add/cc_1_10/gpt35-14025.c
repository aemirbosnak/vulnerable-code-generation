//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int redTime, greenTime, yellowTime;
    int currentState = 0; // 0 represents Red Light, 1 represents Green Light
    int randomTime, elapsedTime = 0;
    srand(time(NULL));

    printf("Enter Red Light duration:");
    scanf("%d", &redTime);

    printf("Enter Green Light duration:");
    scanf("%d", &greenTime);

    printf("Enter Yellow Light duration:");
    scanf("%d", &yellowTime);

    printf("\nTraffic Light Simulation Started...\n\n");

    while (1)
    {
        if (currentState == 0) // Red Light
        {
            printf("Red Light\n");
            printf("%d Seconds elapsed\n", elapsedTime);

            randomTime = rand() % (greenTime + yellowTime);

            while (elapsedTime < redTime)
            {
                printf("%d Seconds remaining\n", redTime - elapsedTime);
                elapsedTime++;
                sleep(1);
            }

            currentState = 1; // Switch to Green Light
            elapsedTime = 0;
        }
        else if (currentState == 1) // Green Light
        {
            printf("Green Light\n");
            printf("%d Seconds elapsed\n", elapsedTime);

            randomTime = rand() % (redTime + yellowTime);

            while (elapsedTime < greenTime)
            {
                printf("%d Seconds remaining\n", greenTime - elapsedTime);
                elapsedTime++;
                sleep(1);
            }

            currentState = 0; // Switch to Red Light
            elapsedTime = 0;
        }
    }

    return 0;
}