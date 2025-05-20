#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int x, y;

    printf("Enter the coordinates of your move (x, y): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= 6 || y < 0 || y >= 6)
    {
        printf("Invalid move. Please try again.\n");
    }
    else
    {
        // Logic to handle the move and update the board
    }

    return 0;
}
