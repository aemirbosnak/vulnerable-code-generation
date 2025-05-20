//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void travel(int x, int y)
{
    printf("You travel to the coordinates (%d, %d).", x, y);
}

int main()
{
    int x = 0, y = 0;
    int choice = 0;

    printf("You wake up on a starship. The vast expanse of space stretches before you.\n");

    while (1)
    {
        printf("Enter '1' to travel north, '2' to travel south, '3' to travel east, '4' to travel west:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                x++;
                travel(x, y);
                break;
            case 2:
                x--;
                travel(x, y);
                break;
            case 3:
                y++;
                travel(x, y);
                break;
            case 4:
                y--;
                travel(x, y);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        if (x == 10 && y == 10)
        {
            printf("Congratulations! You have reached the end of the galaxy.\n");
            break;
        }
    }

    return 0;
}