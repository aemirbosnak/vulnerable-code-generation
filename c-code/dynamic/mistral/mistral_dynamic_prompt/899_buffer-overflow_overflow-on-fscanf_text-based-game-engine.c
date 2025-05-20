#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT 100

void game_input() {
    char input[MAX_INPUT];
    printf("Enter your move (max 100 chars):\n");
    fgets(input, sizeof(input), stdin);
}

void process_input(char *input) {
    int i = 0;
    while (input[i]) {
        // Process each character of the input
        // ... (Some game-related processing code)
        i++;
    }
}

int main() {
    char input[MAX_INPUT];
    char large_input[1000]; // Large enough to cause buffer overflow

    printf("Welcome to the Text-Based Adventure Game!\n");

    while (1) {
        game_input();
        strcpy(large_input, input); // Overflow occurs here
        process_input(large_input);
    }

    return 0;
}
