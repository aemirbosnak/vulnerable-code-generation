#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void loadGameSettings() {
    char settings[10];
    printf("Enter game settings: ");
    fscanf(stdin, "%s", settings);
}

int main() {
    printf("Welcome to the Game Engine!\n");
    loadGameSettings();
    printf("Game started with settings: %s\n", "default");
    return 0;
}
