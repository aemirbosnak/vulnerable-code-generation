#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void main() {
    char game[10];
    printf("Enter your secret game code:\n");
    scanf("%s", game);

    if (strcmp(game, "GAME_OVERRIDE_CODE") == 0) {
        printf("Congratulations! You've unlocked the hidden game features.\n");
    } else {
        printf("Incorrect code. Please try again.\n");
    }

    printf("Input size: %d\n", sizeof(game));
    printf("Input data: %s\n", game);

    strcat(game, "Hello, World!"); // Buffer overflow vulnerability
    printf("Overwritten buffer data: %s\n", game);
}
