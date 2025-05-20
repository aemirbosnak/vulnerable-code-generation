//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int);

int main()
{
    int choice, i, j;
    time_t t;

    printf("The clock strikes midnight... A gust of wind whips through the crumbling Victorian manor of Thornfield Hall.\n");
    printf("You hear whispers in the corridors and a chilling scream echoes through the halls.\n");
    printf("You find yourself alone in the grand hall, a feeling of dread creeping into your stomach.\n");

    // Choose a path
    printf("Please select an option:\n");
    printf("1. Explore the east wing.\n");
    printf("2. Investigate the west wing.\n");
    printf("3. Seek refuge in the ballroom.\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            haunt(1);
            break;
        case 2:
            haunt(2);
            break;
        case 3:
            haunt(3);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}

void haunt(int num)
{
    int i, j;
    time_t t;

    switch (num)
    {
        case 1:
            printf("You cautiously explore the east wing, finding a hidden room. Inside, the air is thick with the scent of decaying roses and the scent of blood.\n");
            break;
        case 2:
            printf("You investigate the west wing, uncovering a secret passage leading to a ghostly chamber. The room is filled with the echoes of screams and the scent of burning flesh.\n");
            break;
        case 3:
            printf("You seek refuge in the ballroom, but find that the doors are bolted shut. Panic erupts as you hear footsteps approaching.\n");
            break;
    }

    // Create a haunting atmosphere
    t = time(NULL);
    for (i = 0; i < 5; i++)
    {
        printf("%c", 248);
        sleep(1);
    }

    printf("A cold wind whips through the halls of Thornfield Hall, carrying with it the scent of decay and despair.\n");
    printf("You hear the echoes of your own screams fading into the night.\n");
    printf("The clock strikes dawn, and you wake up in a cold sweat, the memory of your encounter at Thornfield Hall lingering in your mind.\n");
}