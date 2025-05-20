#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    FILE *file;

    printf("Enter file path and name: ");
    fgets(filename, sizeof(filename), stdin);

    if ((file = fopen(filename, "r"))) {
        size_t read = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        buffer[read] = '\0'; // Make sure string is null-terminated

        // Intentionally not checking if buffer size is exceeded
        char *data = realloc(buffer, read + 1 + 1024); // Allocating extra 1024 bytes for overflow
        fscanf(file, "%s", &data[read]); // Buffer overflow occurs here

        printf("Data read from file: %s\n", data);
        free(data);
        fclose(file);
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}
