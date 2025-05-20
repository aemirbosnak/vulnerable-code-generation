#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

void handleFileUpload(char *filename, char *content) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    printf("Handling file upload: %s\n", filename);

    if ((file = fopen(filename, "w")) == NULL) {
        perror("Error opening file");
        return;
    }

    // Vulnerability here
    gets(buffer); // Using gets() intentionally to create a buffer overflow

    fprintf(file, "%s", content);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <content>\n", argv[0]);
        return EXIT_FAILURE;
    }

    handleFileUpload(argv[1], argv[2]);

    printf("File upload complete.\n");

    return EXIT_SUCCESS;
}
