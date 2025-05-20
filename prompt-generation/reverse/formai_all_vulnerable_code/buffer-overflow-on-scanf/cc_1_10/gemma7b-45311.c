//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int);

int main()
{
    int choice;

    printf("Welcome to the Haunted Mansion of Thornwood Manor.\n");
    printf("Would you like to enter?\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        haunt(1);
    }
    else
    {
        printf("Thank you for your time. Goodbye.\n");
    }

    return 0;
}

void haunt(int level)
{
    int i, j, rand_num;

    printf("You have entered the haunted mansion. Please select a room:\n");
    printf("1. Living Room\n");
    printf("2. Dining Room\n");
    printf("3. Kitchen\n");
    scanf("%d", &i);

    switch (i)
    {
        case 1:
            printf("You have entered the living room. It is dark and dusty. You hear a shuffling sound and feel a cold hand brush against your back.\n");
            break;
        case 2:
            printf("You have entered the dining room. The table is set for a feast, but there is no food. You hear a ghostly giggle and feel a presence in the room.\n");
            break;
        case 3:
            printf("You have entered the kitchen. The cupboards are open and the floor is covered in blood. You hear a scream and feel a sharp object being pointed at your throat.\n");
            break;
    }

    rand_num = rand() % 3;

    switch (rand_num)
    {
        case 0:
            printf("Suddenly, a door slams shut. You hear footsteps running down the hall.\n");
            break;
        case 1:
            printf("A ghostly voice whispers in your ear, 'You will not escape...'\n");
            break;
        case 2:
            printf("A cold wind blows through the house, and you feel a presence brushing against your skin.\n");
            break;
    }

    printf("Would you like to leave the mansion?\n");
    scanf("%d", &j);

    if (j == 1)
    {
        printf("You have escaped the haunted mansion of Thornwood Manor. Thank you for playing.\n");
    }
    else
    {
        printf("You are trapped in the haunted mansion of Thornwood Manor. Game over.\n");
    }
}