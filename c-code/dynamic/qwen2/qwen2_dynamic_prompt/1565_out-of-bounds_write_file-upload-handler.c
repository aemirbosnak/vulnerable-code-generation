#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

void handle_file_upload(const char *filename, const char *data, size_t data_size) {
    char buffer[MAX_FILENAME_LENGTH];
    strcpy(buffer, filename);

    // Deliberate out-of-bounds write vulnerability
    buffer[data_size] = 'A'; // This will overwrite memory beyond the buffer

    printf("File: %s\n", buffer);
    printf("Data: ");
    fwrite(data, 1, data_size, stdout);
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char data[1024];

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    printf("Enter data to upload: ");
    fgets(data, sizeof(data), stdin);

    handle_file_upload(filename, data, strlen(data));

    return 0;
}
