#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input) {
    char output[BUFFER_SIZE];
    char *ptr = output;

    while (*input) {
        switch (*input) {
            case 'a': *ptr++ = 'Z'; break;
            case 'b': *ptr++ = '8'; break;
            case 'c': *ptr++ = '('; break;
            case 'd': *ptr++ = '4'; break;
            case 'e': *ptr++ = '3'; break;
            case 'f': *ptr++ = '|'; break;
            default: *ptr++ = *input;
        }
        input++;
    }

    *ptr = '\0';
}

int main() {
    char buffer[10];
    printf("Enter input string (up to 9 characters): ");
    gets(buffer);
    compress(buffer);
    printf("Compressed string: %s\n", buffer);
    return 0;
}
