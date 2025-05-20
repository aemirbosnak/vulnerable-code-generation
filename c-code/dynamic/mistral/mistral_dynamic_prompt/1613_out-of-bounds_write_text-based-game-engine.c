#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100
#define BUFFER_SIZE 20

void greet_player() {
    printf("Welcome to the Dungeon of Doom!\n");
    printf("Enter your name:\n");
}

void get_player_name(char name[]) {
    fgets(name, MAX_INPUT, stdin);
    name[strcspn(name, "\n")] = 0;
}

void display_room(int room) {
    printf("\nRoom %d:\n", room);
    printf("Here be dragons!\n");
}

void play_game() {
    char name[MAX_INPUT];
    int room = 1;

    greet_player();
    get_player_name(name);
    printf("Hello, %s!\n", name);

    while (1) {
        display_room(room);

        // Insecure code leading to out-of-bounds write
        char buffer[BUFFER_SIZE];
        printf("Enter your move (Q to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        strcpy(buffer + BUFFER_SIZE - 1, "Attack!");
        printf("You attacked!\n");

        room++;
    }
}

int main() {
    play_game();
    return 0;
}
