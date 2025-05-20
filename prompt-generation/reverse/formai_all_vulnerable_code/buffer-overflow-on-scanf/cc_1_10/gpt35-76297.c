//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Traffic_Light_Controller
{
    int redLight : 1;
    int yellowLight : 1;
    int greenLight : 1;
} Traffic_Light_Controller;

void initialize(Traffic_Light_Controller *tlc)
{
    tlc->redLight = 1;
    tlc->yellowLight = 0;
    tlc->greenLight = 0;
}

void redToGreen(Traffic_Light_Controller *tlc, int seconds)
{
    tlc->redLight = 1;
    tlc->yellowLight = 0;
    tlc->greenLight = 0;

    printf("\nRED LIGHT\n");

    sleep(seconds);

    tlc->redLight = 0;
    tlc->yellowLight = 1;
    tlc->greenLight = 0;

    printf("\nYELLOW LIGHT\n");

    sleep(3);

    tlc->redLight = 0;
    tlc->yellowLight = 0;
    tlc->greenLight = 1;

    printf("\nGREEN LIGHT\n");

    sleep(seconds);
}

void greenToRed(Traffic_Light_Controller *tlc, int seconds)
{
    tlc->redLight = 0;
    tlc->yellowLight = 0;
    tlc->greenLight = 1;

    printf("\nGREEN LIGHT\n");

    sleep(seconds);

    tlc->redLight = 0;
    tlc->yellowLight = 1;
    tlc->greenLight = 0;

    printf("\nYELLOW LIGHT\n");

    sleep(3);

    tlc->redLight = 1;
    tlc->yellowLight = 0;
    tlc->greenLight = 0;

    printf("\nRED LIGHT\n");

    sleep(seconds);
}

int main()
{
    Traffic_Light_Controller tlc;

    initialize(&tlc);

    int choice, seconds;

    printf("\nTRAFFIC LIGHT SIMULATOR\n");

    while (1)
    {
        printf("\n1 - Red to Green\n2 - Green to Red\n3 - Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter duration of red and green light (in seconds): ");
            scanf("%d", &seconds);

            redToGreen(&tlc, seconds);
            break;

        case 2:
            printf("Enter duration of green and red light (in seconds): ");
            scanf("%d", &seconds);

            greenToRed(&tlc, seconds);
            break;

        case 3:
            exit(0);

        default:
            printf("\nInvalid choice!\n");
            break;
        }
    }

    return 0;
}