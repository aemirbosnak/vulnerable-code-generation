#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *file;
    char filename[256];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    printf("Enter the filename: ");
    scanf("%255s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            if (buffer[i] < 32 || buffer[i] > 126) {
                fprintf(stderr, "Non-ASCII character detected\n");
                fclose(file);
                return EXIT_FAILURE;
            }
        }
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (feof(file)) {
        printf("File recovered successfully!\n");
    } else {
        printf("Failed to recover file.\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}
