#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

void handle_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char buffer[MAX_BUF_SIZE];
    size_t read_bytes;

    while ((read_bytes = fread(buffer, sizeof(char), MAX_BUF_SIZE, file)) > 0) {
        // Deliberate null pointer dereference vulnerability
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);

    return 0;
}
