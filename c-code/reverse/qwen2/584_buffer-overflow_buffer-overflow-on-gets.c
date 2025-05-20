#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void playGame() {
    char playerName[20];
    printf("Enter your name: ");
    gets(playerName); // Vulnerable function
    printf("Welcome, %s!\n", playerName);
    // Game logic here
}

int main() {
    playGame();
    return 0;
}
