#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void welcome_screen() {
    printf("\n\t************************\n");
    printf("\t* Text-Based Adventure *\n");
    printf("\t************************\n\n");
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Choose your character and embark on a perilous journey.\n");
    printf("\nPlayer 1: Please enter your character name (max 20 characters): ");
}

int main() {
    char player1[32]; // Allocate space for 20 characters and 10 extra for a buffer overflow
    char input[256];

    welcome_screen();
    fgets(player1, sizeof(player1), stdin);
    printf("Player 2, your turn...\n");

    // Create a buffer overflow exploit by using scanf without a max limit
    scanf("%s", input);

    printf("Player 1: %s\n", player1);
    printf("Player 2: %s\n", input);

    // Game loop
    while (1) {
        printf("Press enter to continue the game...\n");
        getchar();
    }

    return 0;
}
