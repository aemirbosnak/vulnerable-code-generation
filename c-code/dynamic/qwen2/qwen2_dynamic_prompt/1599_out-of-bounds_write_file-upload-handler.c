#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename, const char *content) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);
    // Deliberate out-of-bounds write vulnerability
    buffer[MAX_FILENAME_LENGTH] = 'A'; // This will overwrite the return address on the stack
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    const char *content = argv[2];

    handle_file_upload(filename, content);

    printf("File uploaded successfully.\n");
    return 0;
}
