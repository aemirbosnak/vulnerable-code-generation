#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void edit(char **lines, int lines_len, char *buffer, int buf_size) {
    char command[10];

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (!strcmp(command, "quit"))
            break;
        else if (!strcmp(command, "append")) {
            if (fgets(buffer, buf_size, stdin) == NULL)
                break;
            lines[lines_len] = malloc(strlen(buffer) + 1);
            strcpy(lines[lines_len], buffer);
            lines_len++;
        }
        else if (!strcmp(command, "list")) {
            for (int i = 0; i < lines_len; i++)
                printf("%s\n", lines[i]);
        }
        else {
            printf("Invalid command\n");
        }
    }
}

int main() {
    char *lines[100];
    char buffer[10];
    int lines_len = 0;

    edit(lines, lines_len, buffer, sizeof(buffer));

    return 0;
}
