#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
int cursor = 0;

void clear_screen() {
    printf("\033[2J\033[H");
}

void move_cursor(int offset) {
    if (cursor + offset < 0 || cursor + offset >= MAX_LINE) return;
    cursor += offset;
}

void print_buffer() {
    for (int i = 0; i < cursor; ++i) printf("%c", buffer[i]);
    printf("\n");
}

void write_buffer(char *text) {
    int len = strlen(text);
    if ((cursor + len) >= MAX_LINE) return;
    strncat(buffer, text, len);
    cursor += len;
}

int main() {
    char command[10];

    while (1) {
        clear_screen();
        print_buffer();

        fgets(command, sizeof(command), stdin);
        if (strcmp(command, "save\n") == 0) {
            FILE *file = fopen("output.txt", "w");
            fprintf(file, "%s", buffer);
            fclose(file);
            printf("File saved.\n");
            continue;
        }
        if (strcmp(command, "quit\n") == 0) break;

        if (strlen(command) + cursor >= MAX_LINE) {
            printf("Buffer overflow detected.\n");
            continue;
        }

        strcat(buffer, command);
        cursor += strlen(command);
    }

    return 0;
}
