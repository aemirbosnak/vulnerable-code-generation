//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spook(int);

int main()
{
    int choice, i;
    time_t t;

    printf("Welcome to the Haunted House of Screams!\n");
    printf("Please choose an option:\n");
    printf("1. Enter the house\n");
    printf("2. Leave\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            t = time(NULL);
            srand(t);

            for (i = 0; i < 10; i++)
            {
                spook(rand() % 3);
            }

            printf("You have escaped the Haunted House of Screams!\n");
            break;

        case 2:
            printf("You have left the Haunted House of Screams.\n");
            break;

        default:
            printf("Invalid input.\n");
    }

    return 0;
}

void spook(int type)
{
    switch (type)
    {
        case 0:
            printf("You hear footsteps behind you.\n");
            break;

        case 1:
            printf("You see a ghostly figure hovering near you.\n");
            break;

        case 2:
            printf("You smell a strong, pungent odor.\n");
            break;
    }
}