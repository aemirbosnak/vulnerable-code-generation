//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    int room = 1; // Player starts in room 1
    int points = 0; // Player starts with 0 points
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    while (room != 5) // Loop until player reaches final room
    {
        printf("You are in room %d.\n", room);
        printf("Choose a direction to move (1 - North, 2 - East, 3 - South, 4 - West):\n");
        
        int direction;
        scanf("%d", &direction);
        
        // Roll a die to determine if something spooky happens
        int roll = rand() % 6;
        
        if (roll == 0)
        {
            printf("You feel a chill run down your spine...\n");
        }
        else if (roll == 1)
        {           
            printf("You hear a strange noise coming from the next room...\n");
        }
        else if (roll == 2)
        {
            printf("You see a figure in the shadows, but when you shine your light on it, it disappears...\n");
        }
        else if (roll == 3)
        {
            printf("You trip on something in the dark and your heart races as you wonder what it could have been...\n");
        }
        else if (roll == 4)
        {
            printf("You smell something foul and wonder if it's just your imagination...\n");
        }
        else if (roll == 5)
        {
            printf("You suddenly feel like something is right behind you and you turn around, but there's nothing there...\n");
        }
        
        if (direction == 1) // Player moves North
        {
            if (room == 4) // Player falls down a trapdoor and loses points
            {
                printf("You fall through a trapdoor and lose 10 points!\n");
                points -= 10;
                room = 2;
                printf("You find yourself back in room 2.\n");
            }
            else // Player moves to the next room and gains points
            {
                printf("You move to the next room and find a treasure worth 5 points!\n");
                points += 5;
                room++;
            }
        }
        else if (direction == 2) // Player moves East
        {
            printf("You run into a ghost who steals 5 points from you!\n");
            points -= 5;
            room--;
            printf("You find yourself back in the previous room.\n");
        }
        else if (direction == 3) // Player moves South
        {
            printf("You hear a terrifying scream and run back to the previous room!\n");
            points--;
            room--;
            printf("You find yourself back in the previous room.\n");
        }
        else if (direction == 4) // Player moves West
        {
            printf("You find a key that unlocks a secret passage to the next room!\n");
            points += 10;
            room++;
        }
        
        printf("You now have %d points.\n", points);
    }
    
    printf("Congratulations, you made it to the final room and won with %d points!\n", points);
    
    return 0;
}