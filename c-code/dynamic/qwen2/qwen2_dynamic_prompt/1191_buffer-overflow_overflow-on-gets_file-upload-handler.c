#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char* filename) {
    char buffer[MAX_FILENAME_LENGTH];
    printf("Uploading file: %s\n", filename);
    // Vulnerability: Using gets() to read user input into a fixed-size buffer
    gets(buffer); // DO NOT USE gets() IN REAL CODE! This is just for demonstration purposes.
    printf("Buffer contents: %s\n", buffer);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    handle_file_upload(argv[1]);
    return 0;
}
