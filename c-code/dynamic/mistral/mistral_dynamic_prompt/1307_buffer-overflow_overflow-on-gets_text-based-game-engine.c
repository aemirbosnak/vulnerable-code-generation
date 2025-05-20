#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void game_loop(void) {
    char buffer[BUFFER_SIZE];
    printf("Welcome to Secret Dungeon Adventure 3000!\n");
    printf("Please enter your character's name (up to 99 characters): ");
    gets(buffer);

    // Game logic here... (unrelated to the buffer overflow)
    char *name = buffer;
    int i;
    for (i = 0; i < strlen(name); i++) {
        printf("%c: ", name[i]);
        usleep(100000); // Simulate game logic delay
    }
    printf("\nYour character's name is %s.\n", name);

    // Exploit code (buffer overflow)
    printf("Press ENTER to exit the game...\n");
    gets(buffer);
}

int main(int argc, char *argv[]) {
    game_loop();
    return 0;
}
