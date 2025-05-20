#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
char *cursor = buffer;

void move_cursor(int offset) {
    cursor += offset;
}

void print_buffer() {
    printf("\n%s\n", buffer);
}

void write_to_buffer(char *str) {
    int len = strlen(str);
    strcpy(cursor, str);
    cursor += len;
}

int main() {
    char command[10];
    int arg_len;

    while (1) {
        printf("> ");
        scanf("%s", command);
        arg_len = strlen(command);

        switch (command[arg_len - 1]) {
            case 'n':
                move_cursor(1);
                break;
            case 'p':
                print_buffer();
                break;
            case 'w': {
                char *arg = &command[0];
                arg++;
                write_to_buffer(arg);
                break;
            }
            case 'q':
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
