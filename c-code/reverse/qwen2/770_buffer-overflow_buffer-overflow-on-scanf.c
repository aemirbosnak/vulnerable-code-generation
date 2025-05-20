#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char board[7][7] = {0};
    int x, y;

    while (1) {
        printf("Enter your move (x y): ");
        scanf("%d %d", &x, &y);
        board[x][y] = 'X';
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
