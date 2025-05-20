#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void main() {
    char game[10] = {0};
    char input[256] = {0};
    int score = 0;

    printf("Welcome to the Secure Hack Me Game!\n");
    printf("Try to break the game by finding the buffer overflow!\n");

    while (1) {
        printf("\nEnter your move: ");
        fgets(input, sizeof(input), stdin);

        // Game logic
        strncat(game, input, strlen(input));

        if (strcmp(game, "SecureHackMeGame") == 0) {
            printf("Congratulations! You have won the game!\n");
            break;
        } else {
            printf("Incorrect move. Your current score is: %d\n", score++);
        }

        // Reset game array for the next move
        memset(game, 0, sizeof(game));
    }
}
