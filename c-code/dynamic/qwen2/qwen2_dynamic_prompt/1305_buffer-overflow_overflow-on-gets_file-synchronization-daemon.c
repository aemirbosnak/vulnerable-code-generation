#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void vulnerable_function(char *input) {
    char buffer[BUFFER_SIZE];
    gets(buffer); // Vulnerability: using gets() which does not check buffer size
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        return 1;
    }

    vulnerable_function(argv[1]);

    printf("Buffer processed successfully.\n");
    return 0;
}
