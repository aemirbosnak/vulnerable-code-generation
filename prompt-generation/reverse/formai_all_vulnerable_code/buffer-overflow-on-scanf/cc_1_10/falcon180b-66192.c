//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_COMMANDS 100
#define MAX_COMMAND_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

struct command {
    char name[MAX_COMMAND_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    int frequency;
    time_t last_run;
};

void load_commands(struct command *commands, int num_commands) {
    FILE *file;
    char line[MAX_COMMAND_LENGTH];
    int i = 0;

    if ((file = fopen("commands.txt", "r")) == NULL) {
        printf("Error: Unable to open commands file.\n");
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, file)!= NULL) {
        line[strcspn(line, "\r\n")] = '\0'; // Remove newline character
        if (i >= num_commands) {
            printf("Error: Too many commands in file.\n");
            exit(1);
        }
        strcpy(commands[i].name, line);
        strcpy(commands[i].file_name, "");
        commands[i].frequency = 1;
        commands[i].last_run = 0;
        i++;
    }

    fclose(file);
}

int main() {
    struct command commands[MAX_COMMANDS];
    int num_commands;
    char input[MAX_COMMAND_LENGTH];
    int i, j, k;

    printf("Enter the number of commands: ");
    scanf("%d", &num_commands);

    load_commands(commands, num_commands);

    while (1) {
        printf("\nEnter a command: ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\r\n")] = '\0'; // Remove newline character

        for (i = 0; i < num_commands; i++) {
            if (strcmp(commands[i].name, input) == 0) {
                if (commands[i].file_name[0] == '\0') {
                    printf("Error: File name not specified for command '%s'.\n", input);
                } else {
                    system(commands[i].file_name);
                    commands[i].last_run = time(NULL);
                }
                break;
            }
        }

        if (i == num_commands) {
            printf("Error: Command not found.\n");
        }
    }

    return 0;
}