#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void editor() {
    char line[MAX_LINE];
    char * buffer = malloc(sizeof(char) * MAX_LINE);
    int pos = 0, len = 0;

    printf("\033[2J\033[H"); // Clear console

    while (1) {
        printf(">%s%c", buffer, (pos == len) ? '\n' : ' ');
        fflush(stdout);

        fgets(line, MAX_LINE, stdin);
        strcat(buffer, line);
        len += strlen(line);

        if (strchr(line, ':') || strchr(line, '+')) {
            char command[3];
            strncpy(command, line, 2);
            command[2] = '\0';

            if (!strcmp(command, ":q"))
                break;
            else if (!strcmp(command, ":+")) {
                int offset;
                if (sscanf(line + 2, "%d", &offset) != 1)
                    continue;
                memmove(buffer + pos + offset, buffer + pos, len - pos);
                len += strlen(line) - offset - 2;
                pos += offset;
            }
        } else {
            int new_pos = pos + strlen(line);
            memmove(buffer + new_pos, buffer + pos, len - pos);
            strcpy(buffer + pos, line);
            len += strlen(line);
            pos = new_pos;
        }
    }

    free(buffer);
}

int main() {
    editor();
    return 0;
}
