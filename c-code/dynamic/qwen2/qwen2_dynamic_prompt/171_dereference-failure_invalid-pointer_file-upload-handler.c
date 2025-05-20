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
    if (strcmp(filename, "safe.txt") == 0) {
        file = fopen("safe.txt", "r");
    } else {
        file = fopen("unsafe.txt", "w");
        fprintf(file, "This is an unsafe file.\n");
        fclose(file);
        file = fopen("unsafe.txt", "r");
    }

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Simulate reading from file
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }

    // Deliberate dereference failure
    int *ptr = NULL;
    printf("%d\n", *ptr);  // Dereferencing null pointer

    fclose(file);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter the filename to upload: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove newline character if present
    filename[strcspn(filename, "\n")] = '\0';

    handle_file_upload(filename);

    return 0;
}
