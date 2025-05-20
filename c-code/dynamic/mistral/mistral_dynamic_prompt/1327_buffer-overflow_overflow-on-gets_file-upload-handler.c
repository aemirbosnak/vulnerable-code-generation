#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char* filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Uploading file: %s\n", filename);
    fgets(buffer, BUFFER_SIZE, file); // Vulnerable to buffer overflow when reading a large input

    fclose(file);
    printf("File uploaded successfully.\n");
}

int main() {
    char input[100];
    printf("Enter the filename to upload: ");
    gets(input); // vulnerable to buffer overflow when reading a large input
    handle_file_upload(input);

    return 0;
}
