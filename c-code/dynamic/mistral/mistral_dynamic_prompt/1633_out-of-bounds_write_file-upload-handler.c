#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define BUFFER_SIZE (MAX_FILE_SIZE + 128)

void save_file(char *filename, char *data, size_t len) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    fwrite(data, len, 1, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <file_content>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];
    char *file_content = argv[2];

    size_t file_content_len = strlen(file_content);
    if (file_content_len > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum allowed size.\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memcpy(buffer, file_content, file_content_len);

    // Out of bounds write vulnerability begins here
    // Assume that the 'filename' variable is user-controlled and can contain extra data beyond the expected file_name.
    strcat(buffer, argv[1] + file_content_len);
    // Out of bounds write vulnerability ends here

    save_file("uploaded_files/", buffer, file_content_len + strlen(argv[1]) + 1);
    printf("File saved successfully.\n");

    return 0;
}
