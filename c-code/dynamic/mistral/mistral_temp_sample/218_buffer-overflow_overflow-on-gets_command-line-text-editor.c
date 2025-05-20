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
    printf("\n");
    for (int i = 0; i < MAX_LINE; ++i) {
        printf("%c", buffer[i]);
    }
}

void insert_char(char c) {
    *cursor++ = c;
    *cursor = '\0';
    print_buffer();
}

void delete_char() {
    if (cursor > buffer) {
        --cursor;
        *cursor = '\0';
        print_buffer();
    }
}

int main(int argc, char *argv[]) {
    char input[MAX_LINE];

    printf("Vulnerable Text Editor\n");
    printf("Type 'h' for help, 'i' to insert a character, 'd' to delete a character, 'q' to quit.\n");

    while (1) {
        fgets(input, MAX_LINE, stdin);
        if (strcmp(input, "h\n") == 0) {
            printf("Type 'i' to insert a character, 'd' to delete a character, 'q' to quit.\n");
        } else if (strcmp(input, "i\n") == 0) {
            printf("Insert a character: ");
            char c;
            scanf("%c", &c);
            insert_char(c);
        } else if (strcmp(input, "d\n") == 0) {
            delete_char();
        } else if (strcmp(input, "q\n") == 0) {
            break;
        }
    }

    return 0;
}
