#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    int count = sscanf(input, "%*s %n", &buffer[0]);

    // Excessive strlen() call is to overwrite the stack beyond buffer
    int length = strlen(buffer) + 1;
    strcpy(buffer, output);

    // Overflow occurs here, overwriting the return address
    strcpy(buffer + length, "malicious_code");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    compress(argv[1], "");

    return 0;
}
