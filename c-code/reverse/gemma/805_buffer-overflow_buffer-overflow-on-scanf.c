#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char grid[25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int x = 0, y = 0;
    char input[10] = "";

    printf("You are in a 5x5 grid. Use 'w', 'a', 's', 'd' to move. Enter your move: ");

    scanf("%s", input);

    if (strlen(input) > 10)
    {
        printf("Error: Input too long.\n");
    }
    else
    {
        switch (input[0])
        {
            case 'w':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 's':
                y--;
                break;
            case 'd':
                x++;
                break;
            default:
                printf("Invalid move.\n");
        }

        if (grid[x * 5 + y] == 'T')
        {
            printf("Congratulations! You found the treasure!\n");
        }
        else
        {
            printf("Sorry, you have not found the treasure.\n");
        }
    }

    return 0;
}
