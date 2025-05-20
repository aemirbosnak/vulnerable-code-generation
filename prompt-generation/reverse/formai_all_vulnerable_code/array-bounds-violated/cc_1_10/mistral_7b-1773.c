//MISTRAL-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 100
#define MAX_WORDS 20
#define WORD_SIZE 20

typedef struct {
    char command[MAX_LINE];
    char* args[MAX_WORDS];
    int num_args;
} Command;

void str_split(char* str, char delim, Command* cmd) {
    char* token = strtok(str, &delim);
    int i = 0;

    while (token != NULL) {
        cmd->args[i] = token;
        i++;

        if (cmd->num_args >= MAX_WORDS) {
            printf("Too many arguments.\n");
            exit(1);
        }

        token = strtok(NULL, &delim);
        cmd->num_args++;
    }

    cmd->args[i] = NULL;
}

void parse_command(Command* cmd, char* line) {
    str_split(line, ' ', cmd);

    switch (cmd->num_args) {
        case 0:
            printf("Enter a command.\n");
            break;

        case 1:
            if (strcmp(cmd->args[0], "quit") == 0) {
                printf("Exiting the game...\n");
                exit(0);
            } else {
                printf("Invalid command.\n");
            }
            break;

        case 2:
            if (strcmp(cmd->args[0], "go") == 0) {
                if (strcmp(cmd->args[1], "north") == 0) {
                    printf("You go north and find yourself in the clearing.\n");
                } else if (strcmp(cmd->args[1], "south") == 0) {
                    printf("You go south and enter the dark forest.\n");
                } else {
                    printf("Invalid direction.\n");
                }
            } else if (strcmp(cmd->args[0], "take") == 0) {
                if (strcmp(cmd->args[1], "apple") == 0) {
                    printf("You take an apple.\n");
                } else {
                    printf("There's no such thing here.\n");
                }
            } else {
                printf("Invalid command.\n");
            }
            break;

        default:
            printf("Too many arguments.\n");
            break;
    }
}

int main() {
    char line[MAX_LINE];
    Command cmd;

    printf("Welcome to The Enchanted Forest!\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printf("\n> ");
        fgets(line, MAX_LINE, stdin);
        line[strlen(line) - 1] = '\0';

        parse_command(&cmd, line);
    }

    return 0;
}