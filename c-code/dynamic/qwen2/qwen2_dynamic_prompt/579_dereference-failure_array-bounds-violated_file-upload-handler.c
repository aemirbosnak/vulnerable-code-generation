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
    printf("Handling file: %s\n", buffer);

    // Deliberate array bounds violation
    char *data = malloc(content_length + 1);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    memcpy(data, content, content_length);
    data[content_length] = '\0';

    // Intentional out-of-bounds write
    data[content_length + 1] = 'X'; // This will cause a segmentation fault

    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return 1;
    }

    handle_file_upload(argv[1], argv[2]);

    return 0;
}
