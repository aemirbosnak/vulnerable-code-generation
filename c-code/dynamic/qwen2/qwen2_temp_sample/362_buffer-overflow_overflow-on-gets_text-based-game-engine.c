#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void play_game() {
    char name[BUFFER_SIZE];
    printf("Enter your character's name: ");
    gets(name);
    printf("Hello, %s! Welcome to the game.\n", name);
}

int main() {
    printf("Welcome to the Text-Based Game Engine Tool!\n");
    play_game();
    return 0;
}
