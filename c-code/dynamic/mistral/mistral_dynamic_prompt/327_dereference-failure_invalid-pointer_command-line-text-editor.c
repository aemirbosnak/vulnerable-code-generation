#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void edit(char **lines, int *num_lines) {
    char buffer[1024];
    while (1) {
        printf("\nLines: %d\n", *num_lines);
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        char cmd = buffer[0];
        switch (cmd) {
            case 'n':
                (*num_lines)++;
                lines = realloc(lines, (*num_lines) * sizeof(char*));
                lines[*num_lines - 1] = (char*)malloc(strlen(buffer) + 1);
                strcpy(lines[*num_lines - 1], &buffer[1]);
                break;
            case 'r': {
                int line_num;
                if (sscanf(buffer, "%d ", &line_num) != 1 || line_num < 1 || line_num > *num_lines) {
                    printf("Invalid line number.\n");
                    continue;
                }
                printf("Line %d: %s\n", line_num, lines[line_num - 1]);
                break;
            }
            case 'q':
                return;
            default:
                printf("Invalid command.\n");
        }
    }
}

int main() {
    char *lines = NULL;
    int num_lines = 0;
    edit(&lines, &num_lines);
    free(lines);
    return 0;
}
