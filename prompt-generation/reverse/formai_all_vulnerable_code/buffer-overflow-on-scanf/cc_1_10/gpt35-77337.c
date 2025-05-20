//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: recursive
#include <stdio.h>

void navigate(int x, int y, int dest_x, int dest_y)
{
    // Base case: If the current position is the destination, print the message and return
    if (x == dest_x && y == dest_y)
    {
        printf("\nYou have reached your destination!");
        return;
    }

    // Recursive case: Determine the direction to move
    int new_x = x, new_y = y;
    if (x < dest_x)
    {
        new_x++;
        printf("\nMove one block East.");
    }
    else if (x > dest_x)
    {
        new_x--;
        printf("\nMove one block West.");
    }
    else if (y < dest_y)
    {
        new_y++;
        printf("\nMove one block North.");
    }
    else if (y > dest_y)
    {
        new_y--;
        printf("\nMove one block South.");
    }

    // Make the recursive call with the new coordinates
    navigate(new_x, new_y, dest_x, dest_y);
}

int main()
{
    int x, y, dest_x, dest_y;

    printf("Enter your current location (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter your destination (x, y): ");
    scanf("%d %d", &dest_x, &dest_y);

    printf("\nStarting navigation...\n");

    // Start the recursive function
    navigate(x, y, dest_x, dest_y);

    return 0;
}