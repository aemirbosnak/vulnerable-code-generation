//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void traffic_light(int *);

int main()
{
    int i, j, k, r, t, traffic_light_status = 0;
    char c;

    system("clear");

    printf("Welcome to the bustling streets of Crazy Town!");
    printf("\n");

    printf("Press 's' to start the traffic light simulation:");
    scanf(" %c", &c);

    if (c == 's')
    {
        for (t = 0; t < 5; t++)
        {
            traffic_light( &traffic_light_status );

            switch (traffic_light_status)
            {
                case 0:
                    printf("The traffic light is red.\n");
                    break;
                case 1:
                    printf("The traffic light is yellow.\n");
                    break;
                case 2:
                    printf("The traffic light is green.\n");
                    break;
            }

            printf("Press 'q' to quit or any key to continue:");
            scanf(" %c", &c);

            if (c == 'q')
            {
                break;
            }
        }

        printf("Thank you for experiencing the traffic light simulation in Crazy Town!");
    }
    else
    {
        printf("Please try again and press 's' to start the simulation.");
    }

    return 0;
}

void traffic_light(int *status)
{
    time_t t;
    int rand_num;

    t = time(NULL);
    rand_num = rand() % 3;

    switch (rand_num)
    {
        case 0:
            *status = 0;
            break;
        case 1:
            *status = 1;
            break;
        case 2:
            *status = 2;
            break;
    }

    sleep(1);
}