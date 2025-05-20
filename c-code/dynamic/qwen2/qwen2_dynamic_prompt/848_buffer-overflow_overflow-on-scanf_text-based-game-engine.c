#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void playGame() {
    char playerName[20];
    printf("Enter your name: ");
    scanf("%s", playerName);
    printf("Welcome, %s!\n", playerName);
}

int main() {
    playGame();
    return 0;
}
