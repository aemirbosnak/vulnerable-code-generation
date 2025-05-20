#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int x = 0, y = 0;
    char direction;

    printf("Enter direction (w, a, s, d): ");
    scanf(" %c", &direction);

    switch (direction)
    {
        case 'w':
            y--;
            break;
        case 'a':
            x--;
            break;
        case 's':
            y++;
            break;
        case 'd':
            x++;
            break;
        default:
            printf("Invalid direction.\n");
            return 1;
    }

    printf("New position: (%d, %d)\n", x, y);

    return 0;
}
