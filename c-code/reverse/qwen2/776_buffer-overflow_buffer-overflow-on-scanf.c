#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int board[6][6];
    int x, y;

    printf("Enter coordinates (x y): ");
    scanf("%d %d", &x, &y);

    // Vulnerable line: no bounds checking
    board[x][y] = 1;

    return 0;
}
