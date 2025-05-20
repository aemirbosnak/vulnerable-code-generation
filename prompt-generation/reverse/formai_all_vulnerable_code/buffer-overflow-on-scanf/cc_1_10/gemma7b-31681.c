//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int argc, char *argv[])
{
    system("clear");
    srand(time(NULL));
    int r = rand() % 3;
    switch (r)
    {
        case 0:
            printf("The air is thick with the scent of decaying flesh and blood.\n");
            break;
        case 1:
            printf("The sound of chains rattling and a rusty door opening echoes through the halls.\n");
            break;
        case 2:
            printf("A cold wind whips through the corridors, extinguishing the flickering candles.\n");
            break;
    }

    printf("You hear a rustle in the shadows. Turn around to face your doom...\n");
    sleep(1);

    r = rand() % 2;
    switch (r)
    {
        case 0:
            printf("A disembodied hand reaches out from the darkness, grabbing your arm. Prepare for a bone-chilling bite.\n");
            break;
        case 1:
            printf("A ghostly figure stands behind you, its decaying face dripping blood. Prepare for a haunting encounter.\n");
            break;
    }

    printf("Do you flee or fight back? Please enter your choice (f/f) below: ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'f')
    {
        printf("You flee into the night, leaving the haunted house behind.\n");
    }
    else if (choice == 'f')
    {
        printf("You attempt to fight back, but the ghostly figure is too powerful. It tears you limb from limb, leaving only your blood to stain the floor.\n");
    }
    else
    {
        printf("Invalid input. Please try again.\n");
    }

    system("pause");
}

int main(int argc, char *argv[])
{
    haunted_house(argc, argv);
    return 0;
}