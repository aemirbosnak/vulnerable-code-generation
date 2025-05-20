#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void read_line(char *buf, int size) {
    fgets(buf, size, stdin);
    buf[strcspn(buf, "\n")] = '\0';
}

void write_line(char *line) {
    printf("%s\n", line);
}

void append_line(char **lines, char *line) {
    *lines = (char *)realloc(*lines, sizeof(char) * (strlen(*lines) + strlen(line) + 2));
    strcat(*lines, line);
    strcat(*lines, "\n");
}

int main() {
    char *lines = malloc(BUFFER_SIZE);
    char line[BUFFER_SIZE];

    while (1) {
        printf("> ");
        read_line(line, BUFFER_SIZE);
        append_line(&lines, line);
        if (strlen(lines) >= BUFFER_SIZE) {
            printf("Memory exhausted.\n");
            break;
        }
    }

    write_line(lines);

    free(lines);
    return 0;
}
