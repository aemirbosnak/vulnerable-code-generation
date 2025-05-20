//Falcon-180B DATASET v1.0 Category: System administration ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10
#define DELIM " "

char *command = NULL;
char *arguments[MAX_ARGUMENTS];
int argument_count = 0;

void parse_command(char *input) {
    char *token;
    int i = 0;

    command = strdup(input);
    token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments[i] = strdup(token);
        i++;

        if (i >= MAX_ARGUMENTS) {
            printf("Too many arguments!\n");
            exit(1);
        }

        token = strtok(NULL, DELIM);
    }

    argument_count = i;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the surprise shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        } else {
            parse_command(input);

            if (strcmp(command, "echo") == 0) {
                for (int i = 0; i < argument_count; i++) {
                    printf("%s ", arguments[i]);
                }
                printf("\n");
            } else if (strcmp(command, "ls") == 0) {
                printf("Listing files...\n");
            } else {
                printf("Unknown command: %s\n", command);
            }
        }
    }

    return 0;
}