#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename) {
    char buffer[MAX_FILENAME_LENGTH];
    int id;
    float size;

    // Simulate receiving data from a client
    const char *data = "1234567890.txt 1 1024.5";

    // Vulnerable sscanf call
    if (sscanf(data, "%s %d %f", buffer, &id, &size) != 3) {
        fprintf(stderr, "Error parsing input\n");
        return;
    }

    // Print the parsed values to simulate further processing
    printf("Filename: %s\n", buffer);
    printf("ID: %d\n", id);
    printf("Size: %.2f\n", size);

    // Simulate saving the file
    FILE *file = fopen(buffer, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }
    fclose(file);
}

int main() {
    const char *filename = "example.txt";
    handle_file_upload(filename);
    return 0;
}
