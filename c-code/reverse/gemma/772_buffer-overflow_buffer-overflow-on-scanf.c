#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    int x, y;

    printf("Enter move coordinates (x, y): ");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x < 6 && y >= 0 && y < 6)
    {
        // Logic to handle move
    }
    else
    {
        printf("Invalid move. Please try again.\n");
    }

    return 0;
}
