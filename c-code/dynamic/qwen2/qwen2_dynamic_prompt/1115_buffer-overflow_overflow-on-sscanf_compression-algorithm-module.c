#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(const char *input) {
    char buffer[10];
    int value;

    // Vulnerable to buffer overflow via format string attack
    sscanf(input, "%s %d", buffer, &value);

    printf("Buffer: %s\n", buffer);
    printf("Value: %d\n", value);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    compress_data(argv[1]);

    return 0;
}
