#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

enum GameState {
    START,
    IN_GAME,
    END
};

void print_instructions() {
    printf("Welcome to the Adventure Game!\n");
    printf("Type 'help' for commands.\n");
}

void handle_command(char* command) {
    if (strcmp(command, "exit") == 0) {
        printf("Exiting game...\n");
        exit(0);
    } else if (strcmp(command, "help") == 0) {
        printf("Available commands: help, exit\n");
    } else {
        printf("Unknown command. Type 'help' for available commands.\n");
    }
}

int main() {
    enum GameState state = START;
    char input[MAX_INPUT_SIZE];

    while (state != END) {
        switch (state) {
            case START:
                print_instructions();
                state = IN_GAME;
                break;
            case IN_GAME:
                printf("> ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Remove newline character
                handle_command(input);
                break;
            default:
                state = END;
                break;
        }
    }

    return 0;
}
