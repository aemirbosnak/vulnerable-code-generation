//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int door = rand() % 3 + 1; // Choose a random door for the player to enter
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered Door %d.\n", door);
    
    if (door == 1) // If the player enters Door 1
    {
        printf("You have entered a dark room filled with whispers.\n");
        printf("You can hear strange noises coming from the corners of the room.\n");
        printf("Do you want to investigate the noises? (1/0)\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("As you investigate, you find a book with creepy symbols.\n");
            printf("Suddenly, the book starts to levitate and open on its own.\n");
            printf("You feel a cold breeze as the ghost of the previous owner appears before you.\n");
            printf("You managed to escape unharmed, but you will never forget what you saw.\n");
        }
        else
        {
            printf("You feel the presence of something sinister and decide it's time to leave.\n");
            printf("You head towards the door but it has disappeared.\n");
            printf("You hear laughter and whispers getting closer to you.\n");
            printf("You black out.\n");
        }
    }
    else if (door == 2) // If the player enters Door 2
    {
        printf("You have entered a master bedroom with a king-sized bed.\n");
        printf("There is a doll sitting on the bed with its eyes staring at you.\n");
        printf("Do you want to approach the doll? (1/0)\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("As you take a closer look, the doll's eyes glow and its head turns 180 degrees.\n");
            printf("You try to run but the door is locked.\n");
            printf("The doll starts to move and it's getting closer and closer to you.\n");
            printf("You scream as the doll touches you and everything goes dark.\n");
        }
        else
        {
            printf("You decide to leave the room, but as you try to open the door, it won't budge.\n");
            printf("You start to hear a baby crying and it's getting louder and louder.\n");
            printf("You hear whispers getting closer to you and you see shadows moving on the walls.\n");
            printf("You black out.\n");
        }
    }
    else // If the player enters Door 3
    {
        printf("You have entered a kitchen filled with rotten food.\n");
        printf("You feel something brushing against your leg and you look down to see a rat.\n");
        printf("Do you want to investigate the rat? (1/0)\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("As you approach the rat, it starts to grow bigger and bigger.\n");
            printf("It transforms into a giant rat monster and attacks you.\n");
            printf("You manage to defeat the monster with a kitchen knife, but you are injured.\n");
            printf("You start to feel dizzy and you black out.\n");
        }
        else
        {
            printf("You try to leave the room, but the door is stuck.\n");
            printf("You hear footsteps getting closer and closer to you.\n");
            printf("You turn around to see a figure with a dark cloak.\n");
            printf("The figure starts to approach you and everything goes dark.\n");
        }
    }
    
    printf("Game Over.\n");
    return 0;
}