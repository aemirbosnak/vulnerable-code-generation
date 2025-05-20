#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename, const char *content) {
    char buffer[MAX_FILENAME_LENGTH];
    size_t content_length = strlen(content);

    // Simulate file handling logic
    if (strlen(filename) >= MAX_FILENAME_LENGTH) {
        fprintf(stderr, "Filename too long\n");
        return;
    }

    strcpy(buffer, filename);
    printf("Uploading file: %s\n", buffer);

    // Deliberate array bounds violation
    char *ptr = buffer + MAX_FILENAME_LENGTH; // Pointer arithmetic error
    *ptr = 'A'; // Dereferencing invalid memory

    // Simulate writing to file
    FILE *file = fopen(buffer, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fwrite(content, 1, content_length, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1], argv[2]);

    return 0;
}
