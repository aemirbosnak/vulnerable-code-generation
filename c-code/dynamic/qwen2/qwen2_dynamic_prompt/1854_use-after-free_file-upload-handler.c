#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    // Simulate reading from file
    fread(buffer, 1, BUFFER_SIZE, file);
    fclose(file);

    // Use-after-free vulnerability
    printf("File content: %s\n", buffer);
}

int main() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    handle_file_upload(filename);

    // Freeing the memory that was never allocated
    free(filename); // This is invalid and causes undefined behavior

    return 0;
}
