#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
char *cursor = buffer;

void print_buffer() {
    printf("\n%s\n", buffer);
}

void write_char(char c) {
    if (cursor - buffer + 1 >= MAX_LINE) {
        buffer[0] = '\0';
        cursor = buffer;
    }
    *cursor++ = c;
    *cursor = '\0';
}

int main(int argc, char *argv[]) {
    char input[MAX_LINE];

    printf("Text Editor\n");
    printf("Type 'exit' to quit\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        strcat(buffer, input);
        print_buffer();
    }

    return 0;
}
