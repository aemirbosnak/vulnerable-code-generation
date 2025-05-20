//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, x, y, z, choice, map[10][10] = {{0}}, explored[10][10] = {{0}};

    // Generating a random map
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            map[i][j] = rand() % 3;
        }
    }

    // Displaying the map
    printf("Map:\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    // Choosing a direction
    printf("Enter your choice (N, S, E, W): ");
    scanf("%d", &choice);

    // Moving in the chosen direction
    switch (choice)
    {
        case 1:
            x = 0;
            y = 1;
            break;
        case 2:
            x = 0;
            y = -1;
            break;
        case 3:
            x = 1;
            y = 0;
            break;
        case 4:
            x = -1;
            y = 0;
            break;
    }

    // Checking if the cell is explored or not
    if (explored[x][y] == 0)
    {
        // Marking the cell as explored
        explored[x][y] = 1;

        // Displaying the cell's contents
        printf("You are in cell (%d, %d). The contents are: ", x, y);
        switch (map[x][y])
        {
            case 0:
                printf("Nothing.\n");
                break;
            case 1:
                printf("A treasure.\n");
                break;
            case 2:
                printf("A monster.\n");
                break;
            case 3:
                printf("A portal.\n");
                break;
        }
    }
    else
    {
        printf("You have already explored this cell.\n");
    }

    return 0;
}