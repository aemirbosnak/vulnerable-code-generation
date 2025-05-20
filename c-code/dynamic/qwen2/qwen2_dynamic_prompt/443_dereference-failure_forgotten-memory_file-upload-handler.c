#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    FILE *file;
    char buffer[1024];
    size_t bytes_read;

    // Simulate file opening
    if ((file = fopen(filename, "r")) == NULL) {
        perror("Failed to open file");
        return;
    }

    // Simulate reading from file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        // Process data (simulated)
        printf("Read %zu bytes\n", bytes_read);
    }

    // Close file
    fclose(file);

    // Dereference failure (forgotten memory)
    char *data = malloc(100);
    strcpy(data, "Sensitive Data");
    free(data); // Memory freed

    // Vulnerability: Using freed memory
    printf("%s\n", data); // Use after free
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename to upload: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    handle_file_upload(filename);

    return 0;
}
