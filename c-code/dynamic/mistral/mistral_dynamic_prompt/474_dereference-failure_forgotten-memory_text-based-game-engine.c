#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void print_intro() {
    printf("\n\tText-Based Adventure Game Engine v1.0\n\n");
    printf("Welcome to the dark dungeon!\n");
    printf("You are a brave adventurer with a quest to retrieve the mystical gem.\n\n");
}

void get_player_input(char* buffer) {
    fgets(buffer, BUFFER_SIZE, stdin);
}

void process_player_input(char* input) {
    if (strcmp(input, "go north") == 0) {
        printf("You found the mysterious chest and the mystical gem!\n");
        exit(0);
    } else {
        printf("You cannot go that way. Try again.\n");
    }
}

void print_current_location() {
    printf("You are in a dark dungeon room.\n");
}

int main() {
    char input[BUFFER_SIZE];
    char* instructions = "Type 'go north' to find the mystical gem.";
    print_intro();
    print_current_location();
    printf("%s\n", instructions);

    for (int i = 0; i < 10; ++i) {
        get_player_input(input);
        process_player_input(input);
        print_current_location();
        printf("%s\n", instructions);
    }

    // Intentionally accessing an invalid index of the "instructions" string.
    printf("%c", instructions[100]);

    return 0;
}
