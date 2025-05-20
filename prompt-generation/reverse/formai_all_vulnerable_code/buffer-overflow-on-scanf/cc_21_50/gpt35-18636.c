//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int rooms[10][10] = {0}; // array to represent the haunted house
    int currentRoom = 0; // start from the first room
    int isGhostPresent = 0; // starts with no ghosts
    int isGameOver = 0; // flag to check if game is over
    int numGhosts = 0; // counter for number of ghosts

    // setting up the haunted house - randomly placing ghosts
    srand(time(NULL));
    int i, j;
    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            int randNum = rand()%10 + 1; // generate a random number between 1 and 10
            if(randNum == 1 && !(i==0 && j==0)) // if the number is 1 and the room is not the first room
            {
                rooms[i][j] = 1; // place a ghost in the room
                numGhosts++; // increase the count of ghosts
            }
        }
    }

    // game loop
    while(!isGameOver)
    {
        printf("You are in room (%d, %d)\n", currentRoom/10, currentRoom%10);

        if(rooms[currentRoom/10][currentRoom%10] == 1) // check if there is a ghost present
        {
            printf("Oh no! There is a ghost in this room!\n");
            isGhostPresent = 1; // set flag to indicate ghost is present
        }

        if(!isGhostPresent) // if no ghosts present
        {
            // ask for movement direction
            printf("Where would you like to go next?\n");
            printf("1. North\n2. South\n3. East\n4. West\n");
            int choice;
            scanf("%d", &choice);

            switch(choice)
            {
                case 1: // north
                    if(currentRoom/10 == 0) // if at top edge
                    {
                        printf("There is a wall blocking the way!\n");
                    }
                    else
                    {
                        currentRoom -= 10; // move north
                    }
                    break;
                case 2: // south
                    if(currentRoom/10 == 9) // if at bottom edge
                    {
                        printf("There is a wall blocking the way!\n");
                    }
                    else
                    {
                        currentRoom += 10; // move south
                    }
                    break;
                case 3: // east
                    if(currentRoom%10 == 9) // if at right edge
                    {
                        printf("There is a wall blocking the way!\n");
                    }
                    else
                    {
                        currentRoom += 1; // move east
                    }
                    break;
                case 4: // west
                    if(currentRoom%10 == 0) // if at left edge
                    {
                        printf("There is a wall blocking the way!\n");
                    }
                    else
                    {
                        currentRoom -= 1; // move west
                    }
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        }

        // check if game is over
        if(currentRoom == 99) // if in the last room
        {
            printf("Congratulations! You survived the haunted house!\n");
            isGameOver = 1;
        }
        else if(isGhostPresent) // if there is a ghost present
        {
            printf("Oh no! The ghost got you!\n");
            isGameOver = 1;
        }

        isGhostPresent = 0; // reset ghost flag for next room
    }

    // game over message
    printf("Game Over!\n");
    if(numGhosts == 0)
    {
        printf("There were no ghosts in the haunted house.\n");
    }
    else if(numGhosts == 1)
    {
        printf("There was 1 ghost in the haunted house.\n");
    }
    else
    {
        printf("There were %d ghosts in the haunted house.\n", numGhosts);
    }

    return 0;
}