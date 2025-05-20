#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handleFileUpload(char *filename, char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    fwrite(data, sizeof(char), strlen(data), file);
    fclose(file);

    // Out-of-bounds read vulnerability
    char buffer[BUFFER_SIZE];
    fseek(file, -1, SEEK_END); // Move to the last byte of the file
    fread(buffer, sizeof(char), BUFFER_SIZE, file); // Read beyond the end of the file
    buffer[BUFFER_SIZE - 1] = '\0'; // Null-terminate the string
    printf("Read data: %s\n", buffer);
}

int main() {
    char filename[256];
    char data[1024];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter data to upload: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    handleFileUpload(filename, data);

    return 0;
}
