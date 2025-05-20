//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int floor)
{
    int i, j, k;
    char sound[20];
    srand(time(NULL));

    // Generate random sound
    for (i = 0; i < 5; i++)
    {
        sound[i] = 'a' + rand() % 26;
    }

    // Play sound
    for (i = 0; sound[i] != '\0'; i++)
    {
        printf("%c", sound[i]);
    }

    // Create the haunted environment
    switch (floor)
    {
        case 1:
            printf("You are in the living room.\n");
            break;
        case 2:
            printf("You are in the dining room.\n");
            break;
        case 3:
            printf("You are in the kitchen.\n");
            break;
        case 4:
            printf("You are in the master bedroom.\n");
            break;
    }

    // Recursively call haunted_house
    if (floor < 4)
    {
        haunted_house(floor + 1);
    }

    // End of the haunted house
    printf("You have escaped the haunted house.\n");
}

int main()
{
    haunted_house(1);

    return 0;
}