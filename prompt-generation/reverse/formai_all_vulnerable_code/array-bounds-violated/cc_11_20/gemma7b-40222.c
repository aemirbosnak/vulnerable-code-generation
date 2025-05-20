//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    system("clear");
    srand(time(NULL));
    int i, j, k, r, p, q;
    char b[100];

    printf("Welcome to the Haunted House Simulator!\n");
    printf("------------------------\n");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            b[i * 20 + j] = rand() % 2;
        }
    }

    printf("Please enter the room number:");
    scanf("%d", &r);

    switch (r)
    {
        case 1:
            printf("You are in the living room. The air is thick with the scent of burning candles.\n");
            break;
        case 2:
            printf("You are in the dining room. The table is set for a feast, but the food is cold.\n");
            break;
        case 3:
            printf("You are in the bedroom. The bed is made, but the pillows are missing.\n");
            break;
        default:
            printf("Invalid room number.\n");
            break;
    }

    printf("Do you want to explore further? (y/n): ");
    scanf("%c", &p);

    if (p == 'y')
    {
        for (k = 0; k < 5; k++)
        {
            q = rand() % 3;
            switch (q)
            {
                case 0:
                    printf("You hear a rustling sound.\n");
                    break;
                case 1:
                    printf("You smell the scent of burning flesh.\n");
                    break;
                case 2:
                    printf("You see a ghostly figure moving through the hallway.\n");
                    break;
            }
        }
    }

    printf("Thank you for visiting the Haunted House Simulator.\n");
    printf("------------------------\n");
    return;
}