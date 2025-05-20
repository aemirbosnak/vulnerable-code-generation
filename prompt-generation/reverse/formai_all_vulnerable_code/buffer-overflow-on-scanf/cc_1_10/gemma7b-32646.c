//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt_house()
{
    // Create a spooky atmosphere
    srand(time(NULL));
    int rand_num = rand() % 3;
    switch (rand_num)
    {
        case 0:
            printf("A cold wind whispers secrets through the decaying walls.\n");
            break;
        case 1:
            printf("The scent of decaying flesh and blood permeates the air.\n");
            break;
        case 2:
            printf("The echoes of screams and whispers haunt the halls.\n");
            break;
    }

    // Randomly select a haunted object
    int object_num = rand() % 5;
    switch (object_num)
    {
        case 0:
            printf("A ghostly figure flickers in the dim light.\n");
            break;
        case 1:
            printf("A bloodstained axe stands menacingly on the floor.\n");
            break;
        case 2:
            printf("A shattered mirror reflects your own fear.\n");
            break;
        case 3:
            printf("A demonic entity whispers secrets into your ear.\n");
            break;
        case 4:
            printf("A ghostly piano plays a haunting melody.\n");
            break;
    }

    // Simulate a haunting event
    switch (rand() % 3)
    {
        case 0:
            printf("The hairs on your neck stand on end as a cold wind blows through the house.\n");
            break;
        case 1:
            printf("You hear footsteps echoing through the halls.\n");
            break;
        case 2:
            printf("A door slams shut, and you feel a presence lurking nearby.\n");
            break;
    }

    // Give the user a chance to escape
    printf("Enter a command (help, escape): ");
    char command[20];
    scanf("%s", command);

    // If the user enters "escape," they leave the haunted house
    if (strcmp(command, "escape") == 0)
    {
        printf("You escape the haunted house.\n");
    }
    // Otherwise, they are trapped in the house
    else
    {
        printf("You are trapped in the haunted house.\n");
    }
}

int main()
{
    haunt_house();
    return 0;
}