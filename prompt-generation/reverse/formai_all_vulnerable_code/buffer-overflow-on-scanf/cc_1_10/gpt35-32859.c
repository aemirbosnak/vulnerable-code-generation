//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void redBlinking()
{
    printf("Red Light Blinks!\n");
    sleep(2);
}

void greenBlinking()
{
    printf("Green Light Blinks!\n");
    sleep(2);
}

void amberLight()
{
    printf("Amber Light Turns ON!\n");
    sleep(2);
}

int main()
{
    int option;
    printf("\nTraffic Light Simulator\n\n");
    do
    {
        printf("Enter the Option:\n");
        printf("1. Red Light ON\n");
        printf("2. Green Light ON\n");
        printf("3. Amber Light ON\n");
        printf("0. Exit\n\n");
        scanf("%d", &option);

        switch (option)
        {
            case 0:
                printf("Exiting the program...\n");
                break;
            case 1:
                printf("Red Light Turns ON!\n");
                sleep(5);
                redBlinking();
                break;
            case 2:
                printf("Green Light Turns ON!\n");
                sleep(5);
                greenBlinking();
                break;
            case 3:
                printf("Amber Light Turns ON!\n");
                sleep(3);
                amberLight();
                sleep(2);
                redBlinking();
                break;
            default:
                printf("Invalid Option! Please Enter another Option.\n");
                break;
        }

    } while (option != 0);

    return 0;
}