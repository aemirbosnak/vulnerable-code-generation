#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void game_loop() {
    char input[BUFFER_SIZE];
    char buffer[10];
    char *commands[] = {"quit", "save", "load", "status", "attack", "defend"};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);
        sscanf(input, "%s", buffer);

        for (int i = 0; i < num_commands; ++i) {
            if (strcmp(buffer, commands[i]) == 0) {
                execute_command(i);
                break;
            }
        }
    }
}

void execute_command(int index) {
    switch (index) {
        case 0:
            printf("Exiting game...\n");
            exit(0);
        case 1:
            printf("Saving game state...\n");
            break;
        case 2:
            printf("Loading game state...\n");
            break;
        case 3:
            printf("Current game status:\n");
            printf("Your hero has a health of 100 and level 1.\n");
            break;
        case 4:
            printf("Attacking enemy...\n");
            printf("Your hero deals 10 damage.\n");
            break;
        case 5:
            printf("Defending...\n");
            printf("Your hero takes no damage this round.\n");
            break;
        default:
            printf("Invalid command.\n");
    }
}

int main() {
    game_loop();
    return 0;
}
