#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main()
{
    char board[36] = {0};
    int x, y;

    printf("Enter move (x, y): ");
    scanf("%d %d", &x, &y);

    board[x * 6 + y] = 'X';

    printf("Board:\n");
    for (int i = 0; i < 36; i++)
    {
        printf("%c ", board[i]);
    }

    return 0;
}
