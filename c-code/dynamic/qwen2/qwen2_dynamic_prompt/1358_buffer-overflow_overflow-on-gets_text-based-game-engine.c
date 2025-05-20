#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void playGame() {
    char playerName[20];
    printf("Enter your name: ");
    gets(playerName); // Vulnerable to buffer overflow

    printf("Welcome, %s!\n", playerName);
}

int main() {
    playGame();
    return 0;
}
