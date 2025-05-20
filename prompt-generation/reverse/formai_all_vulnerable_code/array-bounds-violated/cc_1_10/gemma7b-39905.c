//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j, n, m;
    scanf("Enter the number of ghosts: ", &n);
    scanf("Enter the number of rooms: ", &m);

    // Create a 2D array of ghosts
    int ghosts[n][m];

    // Initialize the ghosts
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            ghosts[i][j] = 0;
        }
    }

    // Get the ghosts' locations
    for (i = 0; i < n; i++)
    {
        scanf("Enter the location of ghost %d: ", &ghosts[i][0]);
        scanf("Enter the location of ghost %d: ", &ghosts[i][1]);
    }

    // Check if the player is in a haunted room
    int x, y;
    scanf("Enter your location: ", &x);
    scanf("Enter your location: ", &y);

    // Iterate over the ghosts and see if the player is in their room
    for (i = 0; i < n; i++)
    {
        if (ghosts[i][0] == x && ghosts[i][1] == y)
        {
            printf("You are in the room of ghost %d!\n", i);
        }
    }

    // If the player is not in a haunted room, print a message
    if (ghosts[0][0] != x || ghosts[0][1] != y)
    {
        printf("You are not in a haunted room.\n");
    }

    return;
}