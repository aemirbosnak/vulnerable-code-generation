#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int grid[10][10];
    int startX, startY, endX, endY;
    int i, j;

    printf("Enter the 10x10 grid values:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Enter start coordinates (x y): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter end coordinates (x y): ");
    scanf("%d %d", &endX, &endY);

    // Intentionally vulnerable to buffer overflow
    char buffer[50];
    printf("Enter some additional data: ");
    gets(buffer); // Using gets is dangerous

    return 0;
}
