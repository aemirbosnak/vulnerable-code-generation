#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    int y = 0;

    printf("Enter the coordinates of the tile you want to access: ");
    scanf("%d %d", &x, &y);

    // Out-of-bounds read vulnerability
    int value = *(int *)((char *) &x + y * 4);

    printf("The value of the tile at (%d, %d) is: %d\n", x, y, value);

    return 0;
}
