#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void edit(char *buffer, int size) {
    char line[256];
    int pos = 0;

    printf("Text Editor\n");
    while (1) {
        printf("\nBuffer: %.*s\n", pos < size ? pos : size - 1, buffer);
        printf("> ");
        fgets(line, sizeof(line), stdin);
        strncat(buffer, line, strlen(line));
        pos += strlen(line);
    }
}

int main(int argc, char **argv) {
    char buffer[10];
    edit(buffer, sizeof(buffer));
    return 0;
}
