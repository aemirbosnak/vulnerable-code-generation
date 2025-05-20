//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void play_haunted_house(void)
{
    // Define the haunted house environment
    char *house_environment = "The crumbling Victorian mansion loomed silently, its decaying facade mirroring the crumbling spirit of its former occupants. A cold wind whipped through the dilapidated halls, carrying with it the scent of decay and despair. The only sounds were the rustling of leaves and the occasional groan of the ghostly inhabitants.";

    // Create a spooky atmosphere
    srand(time(NULL));
    int random_number = rand() % 3;
    switch (random_number)
    {
        case 0:
            printf("%s\n", house_environment);
            printf("You hear a faint whisper in the hallway.\n");
            break;
        case 1:
            printf("%s\n", house_environment);
            printf("A cold hand brushes against your skin as you pass through a doorway.\n");
            break;
        case 2:
            printf("%s\n", house_environment);
            printf("You hear the disembodied screams of a former resident echoing through the halls.\n");
            break;
    }

    // Interactive element
    char command;
    printf("What do you want to do? (q/a/c) ");
    scanf("%c", &command);

    // Response to user input
    switch (command)
    {
        case 'q':
            printf("You flee the haunted house, leaving the spirits behind.\n");
            break;
        case 'a':
            printf("You attempt to appease the spirits, but they remain hostile.\n");
            break;
        case 'c':
            printf("You confront the spirits, but they overpower you, and you meet a gruesome end.\n");
            break;
    }
}

int main()
{
    play_haunted_house();

    return 0;
}