#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 128

void handle_file_upload(const char* filename, const char* content) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file for writing\n");
        return;
    }

    // Simulate an out-of-bounds write vulnerability
    size_t content_length = strlen(content);
    if (content_length > MAX_FILENAME_LENGTH * 2) {
        fwrite(content, 1, content_length, file); // Out-of-bounds write
    } else {
        fwrite(content, 1, content_length, file);
    }

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    const char* content = argv[2];

    handle_file_upload(filename, content);

    printf("File uploaded successfully\n");

    return 0;
}
