//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house()
{
    int i, j, choice, spooky_sound, random_number;

    // Setting the mood
    srand(time(NULL));
    spooky_sound = rand() % 5;

    // Creating the haunted house
    printf("You find yourself standing at the crumbling entrance of a haunted house. The air is thick with the scent of decay and desperation.\n");

    // Choosing a path
    printf("There are two doors before you. The left door is shrouded in an ominous red glow. The right door emanates a cold, sickly-sweet smell.\n");
    printf("Enter your choice (L/R): ");
    scanf("%c", &choice);

    // Spooky sound effects
    switch (spooky_sound)
    {
        case 0:
            printf("A chilling moan echoes through the halls.\n");
            break;
        case 1:
            printf("A ghostly wail pierces through the air.\n");
            break;
        case 2:
            printf("A demonic scream reverberates through the house.\n");
            break;
        case 3:
            printf("A creepy shuffling sound fills the hallway.\n");
            break;
        case 4:
            printf("A bloodcurdling scream echoes through the house.\n");
            break;
    }

    // Randomly generated encounter
    random_number = rand() % 3;

    // Encounters
    switch (random_number)
    {
        case 0:
            printf("You encounter a ghostly figure hovering near the doorway. It turns to you with piercing eyes and a sinister smile.\n");
            break;
        case 1:
            printf("You find a bloody note left on a table. It warns of a demonic presence and a coming darkness.\n");
            break;
        case 2:
            printf("You hear voices whispering secrets in your ear. They beg you to leave the house, but you are too scared to move.\n");
            break;
    }

    // Final message
    printf("You escape the haunted house, but the experience has left you forever changed. You will never forget your night in the haunted house.\n");
}

int main()
{
    play_haunted_house();

    return 0;
}