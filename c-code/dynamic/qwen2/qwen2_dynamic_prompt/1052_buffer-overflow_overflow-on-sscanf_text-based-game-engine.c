#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 10

void loadPlayerName(char *name) {
    char input[256];
    printf("Enter your character's name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    sscanf(input, "%s", name); // Vulnerable to buffer overflow
}

int main() {
    char playerName[MAX_NAME_LENGTH];

    printf("Welcome to the Game Engine!\n");
    loadPlayerName(playerName);

    printf("Hello, %s! Let's begin your adventure.\n", playerName);

    return 0;
}
