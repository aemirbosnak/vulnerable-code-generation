#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10

void read_line(char *line, int max_len) {
    fgets(line, max_len, stdin);
}

int main() {
    char buffer[MAX_LINES][256];
    int line_count = 0;

    printf("Welcome to the Text Editor!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        if (line_count >= MAX_LINES) {
            printf("Error: Maximum number of lines reached!\n");
            break;
        }

        printf("> ");
        read_line(buffer[line_count], sizeof(buffer[line_count]));

        if (buffer[line_count][0] == '\0') continue;

        if (strcmp(buffer[line_count], "exit\n") == 0) {
            break;
        }

        line_count++;
    }

    printf("\nContent:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%s", buffer[i]);
    }

    return 0;
}
