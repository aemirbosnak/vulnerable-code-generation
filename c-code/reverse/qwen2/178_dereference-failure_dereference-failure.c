#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Failed to read file");
        free(buffer);
        fclose(file);
        return EXIT_FAILURE;
    }
    buffer[file_size] = '\0';

    int success = 1;
    for (size_t i = 0; i < file_size; ++i) {
        if (buffer[i] == '\0' || buffer[i] == ' ') {
            buffer[i] = '_';
        } else if ((unsigned char)buffer[i] > 127) {
            success = 0;
            break;
        }
    }

    if (success) {
        printf("File processed successfully.\n");
    } else {
        printf("Error processing file: Non-ASCII character found.\n");
    }

    free(buffer);
    fclose(file);
    return EXIT_SUCCESS;
}
