#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 128

void handle_file_upload(char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    gets(buffer); // Vulnerability: using gets() which does not check buffer size
    printf("File uploaded as: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    handle_file_upload(argv[1]);
    return 0;
}
