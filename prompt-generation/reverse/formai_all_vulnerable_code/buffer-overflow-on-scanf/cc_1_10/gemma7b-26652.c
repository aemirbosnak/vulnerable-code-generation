//Gemma-7B DATASET v1.0 Category: System administration ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 256

typedef struct Command {
    char **cmd_line;
    int cmd_len;
    struct Command* next;
} Command;

Command* create_command(char* cmd_line, int cmd_len) {
    Command* new_cmd = malloc(sizeof(Command));
    new_cmd->cmd_line = malloc(MAX_CMD_LEN * sizeof(char));
    new_cmd->cmd_len = cmd_len;
    new_cmd->next = NULL;

    strcpy(new_cmd->cmd_line, cmd_line);

    return new_cmd;
}

void print_commands(Command* cmd_list) {
    Command* current_cmd = cmd_list;

    printf("List of commands:\n");

    while (current_cmd) {
        printf("  %s\n", current_cmd->cmd_line);
        current_cmd = current_cmd->next;
    }
}

int main() {
    Command* cmd_list = NULL;

    char cmd_line[MAX_CMD_LEN];

    printf("Enter a command (or leave blank to quit): ");
    scanf("%s", cmd_line);

    while (strcmp(cmd_line, "") != 0) {
        int cmd_len = strlen(cmd_line);

        cmd_list = create_command(cmd_line, cmd_len);

        printf("Enter a command (or leave blank to quit): ");
        scanf("%s", cmd_line);
    }

    print_commands(cmd_list);

    return 0;
}