#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[100];
    printf("Uploading file: %s\n", filename);
    // Vulnerability: Using gets to read user input into a fixed-size buffer
    gets(buffer); // DO NOT USE gets() IN REAL-WORLD CODE!
    printf("Buffer contents: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    handleFileUpload(argv[1]);
    return 0;
}
