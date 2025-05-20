#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096
#define UPLOAD_FILE "upload.bin"

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[MAX_BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if ((file = fopen(UPLOAD_FILE, "wb")) == NULL) {
        perror("Failed to open file for writing.");
        return 1;
    }

    printf("Uploading %s...\n", argv[1]);

    while (1) {
        printf("> ");
        gets(buffer);

        fwrite(buffer, strlen(buffer), 1, file);

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }
    }

    fclose(file);
    printf("File uploaded successfully.\n");
    return 0;
}
