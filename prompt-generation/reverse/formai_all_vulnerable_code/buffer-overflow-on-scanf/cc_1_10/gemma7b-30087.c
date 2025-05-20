//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int);

int main()
{
    int choice;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please select an option:\n");
    printf("1. Enter the Haunted House\n");
    printf("2. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            haunted_house(1);
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
    }

    return 0;
}

void haunted_house(int level)
{
    int i, j, r, t;
    char c;

    system("clear");

    if (level == 1)
    {
        printf("You have entered the haunted house. Prepare for a scare...\n");
    }
    else if (level == 2)
    {
        printf("You have passed the first room. Now you are in the second room. Be careful...\n");
    }
    else if (level == 3)
    {
        printf("You have passed the second room. Now you are in the final room. Prepare for the climax...\n");
    }

    r = rand() % 3;

    switch (r)
    {
        case 0:
            printf("Suddenly, a door creaks open...\n");
            break;
        case 1:
            printf("You hear footsteps behind you...\n");
            break;
        case 2:
            printf("A ghostly hand reaches out to grab you...\n");
            break;
    }

    t = rand() % 3;

    switch (t)
    {
        case 0:
            printf("You see a flickering light...\n");
            break;
        case 1:
            printf("You hear a voice calling your name...\n");
            break;
        case 2:
            printf("You feel a cold hand brush against your skin...\n");
            break;
    }

    c = getchar();

    haunted_house(level + 1);
}